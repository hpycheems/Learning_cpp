#include "CSession.h"
#include "CServer.h"

#include <sstream>
#include <iomanip>

CSession::CSession(boost::asio::io_context& io_context, CServer* server) :_socket(io_context), _server(server), _b_head_parse(false)
{
	boost::uuids::uuid a_uuid = boost::uuids::random_generator()();
	_uuid = boost::uuids::to_string(a_uuid);
	_recv_head_node = std::make_shared<MsgNode>(HEAD_LENGTH);
}

CSession::~CSession()
{
	std::cout << "CSession 析构\n";
}

tcp::socket& CSession::GetSocket()
{
	return _socket;
}

std::string& CSession::GetUuid()
{
	return _uuid;
}

void CSession::Start()
{
	memset(_data, 0, MAX_LENGTH);
	_socket.async_read_some(boost::asio::buffer(_data, MAX_LENGTH),
		std::bind(&CSession::HandleRead, this, std::placeholders::_1, std::placeholders::_2, shared_from_this()));
}

void CSession::Send(char* msg, int max_length)
{
	std::lock_guard<std::mutex> lock(_send_lock);
	int send_size = _send_queue.size();
	if (send_size > MAX_SENDMSG) {
		std::cout << "session : " << _uuid << " send que fulled, size is " << MAX_SENDMSG << "\n";
		return;
	}

	_send_queue.push(std::make_shared<MsgNode>(msg, max_length));
	if (send_size > 0) {
		return;
	}

	auto& node = _send_queue.front();
	boost::asio::async_write(_socket, boost::asio::buffer(node->_data, node->_total_len), std::bind(
		&CSession::HandleWrite, this, std::placeholders::_1, shared_from_this()
	));
}

void CSession::Close()
{
}

void CSession::PrintRecvData(char* data, int length)
{
	std::stringstream ss;
	std::string result = "0x";
	for (int i = 0; i < length; i++) {
		std::string hexstr;
		ss << std::hex << std::setw(2) << std::setfill('0') << int(data[i]) << std::endl;
		ss >> hexstr;
		result += hexstr;
	}
	std::cout << "receive raw data is : " << result << std::endl;
}

void CSession::HandleWrite(const boost::system::error_code& ec, std::shared_ptr<CSession> session)
{
	if (!ec) {//调到这里说明 已经发生成功一条数据
		std::lock_guard<std::mutex> lock(_send_lock);
		std::cout << "send data :" << _send_queue.front()->_data << "\n";
		_send_queue.pop();

		if (!_send_queue.empty()) {
			auto& msgnode = _send_queue.front();
			_socket.async_read_some(boost::asio::buffer(msgnode->_data, msgnode->_total_len), std::bind(
				&CSession::HandleWrite, this, std::placeholders::_1, session
			));
		}
	}
	else {
		std::cout << "Handle write faile: error is " << ec.value() << "\n";
		_server->ClearSession(_uuid);
	}
}

void CSession::HandleRead(const boost::system::error_code& ec, std::size_t bytes_transferred, std::shared_ptr<CSession> session)
{
	if (!ec) {
		/*PrintRecvData(_data, bytes_transferred);
		std::chrono::milliseconds dura(2000);
		std::this_thread::sleep_for(dura);*/

		short copy_len = 0;
		while (bytes_transferred > 0)
		{
			if (!_b_head_parse) {//未处理头部
				if (bytes_transferred + _recv_head_node->_cur_len < HEAD_LENGTH) {
					memcpy(_recv_head_node->_data + _recv_head_node->_cur_len, _data + copy_len, bytes_transferred);
					_recv_head_node->_cur_len += bytes_transferred;//更新已经处理的数据
					//继续接收
					::memset(_data, 0, MAX_LENGTH);

					_socket.async_read_some(boost::asio::buffer(_data, MAX_LENGTH),
						std::bind(&CSession::HandleRead, this,
							std::placeholders::_1, std::placeholders::_2, session)
					);
					return;
				}

				//当接收到的数据 大于头
				//先处理头
				int head_remain = HEAD_LENGTH - _recv_head_node->_cur_len;
				memcpy(_recv_head_node->_data + _recv_head_node->_cur_len, _data + copy_len, head_remain);
				_recv_head_node->_cur_len += head_remain;
				copy_len += head_remain;
				bytes_transferred -= head_remain;

				short data_len = 0;
				memcpy(&data_len, _recv_head_node->_data, HEAD_LENGTH);
				//网络字节序转为本地字节序
				data_len = boost::asio::detail::socket_ops::host_to_network_short(data_len);
				std::cout << "recieve data len :" << data_len << "\n";
				if (bytes_transferred > MAX_LENGTH) {//当接收到的数据大于 最大能接收的数据时，直接断开
					std::cout << "invalid data length is: " << data_len << "\n";
					_server->ClearSession(_uuid);
					return;
				}

				_recv_msg_node = std::make_shared<MsgNode>(data_len);//初始化 _recv_msg_node
				if (bytes_transferred < data_len) {
					memcpy(_recv_msg_node->_data + _recv_msg_node->_cur_len, _data + copy_len, bytes_transferred);
					_recv_msg_node->_cur_len += bytes_transferred;
					memset(_data, 0, MAX_LENGTH);

					_socket.async_read_some(boost::asio::buffer(_data, MAX_LENGTH),
						std::bind(&CSession::HandleRead, this,
							std::placeholders::_1, std::placeholders::_2, session)
					);
					_b_head_parse = true;
					return;
				}

				memcpy(_recv_msg_node->_data + _recv_msg_node->_cur_len, _data + copy_len, data_len);
				_recv_msg_node->_cur_len += data_len;
				copy_len += data_len;
				bytes_transferred -= data_len;
				_recv_msg_node->_data[_recv_msg_node->_total_len] = '\0';
				std::cout << "receive data is:" << _recv_msg_node->_data << "\n";

				Send(_recv_msg_node->_data, _recv_msg_node->_total_len);

				_b_head_parse = false;
				_recv_head_node->Clear();
				if (bytes_transferred <= 0) {
					memset(_data, 0, MAX_LENGTH);
					_socket.async_read_some(boost::asio::buffer(_data, MAX_LENGTH),
						std::bind(&CSession::HandleRead, this,
							std::placeholders::_1, std::placeholders::_2, session)
					);
					return;
				}
				continue;
			}

			int remain_msg = _recv_msg_node->_total_len - _recv_msg_node->_cur_len;
			if (bytes_transferred < remain_msg) {
				memcpy(_recv_msg_node->_data + _recv_msg_node->_cur_len, _data + copy_len, bytes_transferred);
				_recv_msg_node->_cur_len += bytes_transferred;
				memset(_data, 0, MAX_LENGTH);
				_socket.async_read_some(boost::asio::buffer(_data, MAX_LENGTH),
					std::bind(&CSession::HandleRead, this,
						std::placeholders::_1, std::placeholders::_2, session)
				);
				return;
			}

			memcpy(_recv_msg_node->_data + _recv_msg_node->_cur_len, _data + copy_len, remain_msg);
			_recv_msg_node->_cur_len += remain_msg;
			copy_len += remain_msg;
			bytes_transferred -= remain_msg;
			_recv_msg_node->_data[_recv_msg_node->_total_len] = '\0';
			std::cout << "receive data is :" << _recv_msg_node->_data << "\n";
			Send(_recv_msg_node->_data, _recv_msg_node->_total_len);

			_b_head_parse = false;
			_recv_head_node->Clear();
			if (bytes_transferred <= 0) {
				memset(_data, 0, MAX_LENGTH);
				_socket.async_read_some(boost::asio::buffer(_data, MAX_LENGTH),
					std::bind(&CSession::HandleRead, this,
						std::placeholders::_1, std::placeholders::_2, session)
				);
				return;
			}
			continue;
		}
	}
	else {
		std::cout << "Handle read faile, error is :" << ec.what() << "\n";
		//Close();
		_server->ClearSession(_uuid);
	}
}
