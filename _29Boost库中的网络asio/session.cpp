//#include "session.h"
//
//
//
//Session::Session(std::shared_ptr<asio::ip::tcp::socket> socket) :_socket(socket), _send_pending{false},
//_read_pending{false}
//{
//}
//
//void Session::Connect(const asio::ip::tcp::endpoint& ep)
//{
//	_socket->connect(ep);
//}
//
//void Session::WroteCallBackErr(const boost::system::error_code& ec, std::size_t bytes_transferred,
//	std::shared_ptr<MsgNode> msg_node)
//{
//	if (bytes_transferred + msg_node->_cur_len < msg_node->_total_len) {
//		_send_node->_cur_len += bytes_transferred;
//		this->_socket->async_write_some(asio::buffer(msg_node->_msg + msg_node->_cur_len,
//			_send_node->_total_len - _send_node->_cur_len),
//			std::bind(&Session::WroteCallBackErr, this, std::placeholders::_1,
//				std::placeholders::_2, _send_node));
//	}
//}
//
//void Session::WriteToSocketErr(const std::string& buf)
//{
//	_send_node = std::make_shared<MsgNode>(buf, buf.length());
//	_socket->async_write_some(asio::buffer(_send_node->_msg, _send_node->_total_len),
//		std::bind(&Session::WroteCallBackErr, this, std::placeholders::_1, std::placeholders::_2,
//			_send_node));
//}
////================================== 异步方式难以控制发送顺序 ==================================
////使用队列
//void Session::WroteCallBack(const boost::system::error_code& ec,std::size_t bytes_transferred)
//{
//	if (ec.value() != 0) {
//		std::cout << "Error, code is" << ec.value() << " .Message " << ec.message() << "\n";
//		return;
//	}
//
//	auto& send_data = _send_deque.front();//取出队列的头元素
//
//	send_data->_cur_len += bytes_transferred;
//
//	if (send_data->_cur_len < send_data->_total_len) {//消息没有完整发送
//		_socket->async_write_some(boost::asio::buffer(send_data->_msg + send_data->_cur_len,
//			send_data->_total_len - send_data->_cur_len),
//			std::bind(&Session::WroteCallBack, this, std::placeholders::_1, std::placeholders::_2)
//			);
//		return;
//	}
//
//	_send_deque.pop_front();//头元素出队列
//
//	if (_send_deque.empty()) {//队列为空 停止发送
//		_send_pending = false;
//	}
//
//	if (!_send_deque.empty()) {
//		auto& send_data = _send_deque.front();
//		_socket->async_write_some(boost::asio::buffer(send_data->_msg,send_data->_total_len),
//			std::bind(&Session::WroteCallBack, this, std::placeholders::_1, std::placeholders::_2)
//		);
//	}
//}
//void Session::WriteToSocket(const std::string& buf)
//{
//	_send_deque.emplace_back(std::make_shared<MsgNode>(buf.c_str(), buf.length()));//将消息添加到队列
//
//	if (_send_pending)return;//如果正在发消息，则让回调函数发送发送消息队列中的消息
//
//	_socket->async_write_some(boost::asio::buffer(buf), std::bind(&Session::WroteCallBack, this,
//		std::placeholders::_1, std::placeholders::_2));
//
//	_send_pending = true;
//}
////让内置函数帮我们直接发送完 async_send
//void Session::WriteAllToSocket(const std::string& buf)
//{
//	//现将消息加入队列
//	_send_deque.emplace_back(new MsgNode(buf.c_str(), buf.length()));
//
//	if (_send_pending) return;
//
//	_socket->async_send(boost::asio::buffer(buf), std::bind(
//		&Session::WriteAllToCallback, this, std::placeholders::_1, std::placeholders::_2));
//
//	_send_pending = true;
//}
//
//void Session::WriteAllToCallback(const boost::system::error_code& ec, std::size_t bytes_transferred)
//{
//	if (ec.value() != 0) {
//		std::cout << "Error, code is" << ec.value() << " .Message " << ec.message() << "\n";
//		return;
//	}
//	//回调到这里的时候已经发送完成了
//
//	//出队
//	_send_deque.pop_front();
//
//	if (_send_deque.empty()) {
//		_send_pending = false;
//		return;
//	}
//	else {
//		auto& send_data = _send_deque.front();
//		_socket->async_send(boost::asio::buffer(send_data->_msg + send_data->_cur_len,
//			send_data->_total_len - send_data->_cur_len),
//			std::bind(&Session::WriteAllToCallback, this, std::placeholders::_1, std::placeholders::_2));
//	}
//}
//
//void Session::ReadFromSocket()
//{
//	if (_read_pending) return;
//
//	_read_node = std::make_shared<MsgNode>(RECVSIZE);
//	_socket->async_read_some(boost::asio::buffer(_read_node->_msg, _read_node->_cur_len),
//		std::bind(&Session::ReadCallBack, this, std::placeholders::_1, std::placeholders::_2));
//
//	_read_pending = true;
//}
//
//void Session::ReadCallBack(const boost::system::error_code& ec, std::size_t bytes_transferred)
//{
//	_read_node->_cur_len += bytes_transferred;
//	if (_read_node->_cur_len < _read_node->_total_len) {
//		_socket->async_read_some(boost::asio::buffer(_read_node->_msg + _read_node->_cur_len, 
//			_read_node->_total_len - _read_node->_cur_len),
//			std::bind(&Session::ReadCallBack, this, std::placeholders::_1, std::placeholders::_2));
//		return;
//	}
//
//	_read_pending = false;
//	_read_node = nullptr;
//}
//
//void Session::ReadAllFromSocket()
//{
//	if (_read_pending) return;
//
//	_read_node = std::make_shared<MsgNode>(RECVSIZE);
//	_socket->async_receive(boost::asio::buffer(_read_node->_msg, _read_node->_total_len),
//		std::bind(&Session::ReadAllCallBack, this, std::placeholders::_1, std::placeholders::_2)
//	);
//
//	_read_pending = true;
//}
//
//void Session::ReadAllCallBack(const boost::system::error_code& ec, std::size_t bytes_transferred)
//{
//	_read_node->_cur_len += bytes_transferred;
//	_read_pending = false;
//	_read_node = nullptr;
//}
