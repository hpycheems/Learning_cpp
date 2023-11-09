#include "CSession.h"
#include "CServer.h"

CSession::CSession(boost::asio::io_context& io_context, CServer* server) :_socket(io_context), _server(server), _b_head_parse(false), _b_close(false) {
    boost::uuids::uuid a_uuid = boost::uuids::random_generator()();
    _uuid = boost::uuids::to_string(a_uuid);
    _recv_head_node = std::make_shared<MsgNode>(HEAD_TOTAL_LEN);
}
CSession::~CSession() {
    _socket.close();
    _b_close = true;
}
std::string& CSession::GetUuid() {
    return _uuid;
}
tcp::socket& CSession::GetSocket() {
    return _socket;
}
void CSession::Close() {

}
void CSession::Start() {
    memset(_data, 0, MAX_LENGHT);
    _socket.async_read_some(boost::asio::buffer(_data, MAX_LENGHT), std::bind(
        &CSession::HandleRead, this, std::placeholders::_1, std::placeholders::_2, SessionSelf()
    ));
    // boost::asio::async_read(_socket, boost::asio::buffer(_recv_head_node->_data, HEAD_TOTAL_LEN),std::bind(
    //     &CSession::HandleReadHead, this, std::placeholders::_1,std::placeholders::_2, SessionSelf()
    // ));
}
std::shared_ptr<CSession> CSession::SessionSelf() {
    return shared_from_this();
}

void CSession::Send(char* msg, int max_len, short msg_id) {
    std::lock_guard<std::mutex> lock(_send_lock);
    int send_que_size = _send_queue.size();
    if (send_que_size > MAX_SENDQUE) {
        std::cout << "session :" << _uuid << " send que failed, size is" << MAX_SENDQUE << "\n";
        return;
    }

    _send_queue.push(std::make_shared<SendNode>(msg, max_len, msg_id));
    if (send_que_size > 0) {
        return;
    }
    auto& node = _send_queue.front();
    boost::asio::async_write(_socket, boost::asio::buffer(node->_data, node->_total_len), std::bind(
        &CSession::HandleWrite, this, std::placeholders::_1, SessionSelf()
    ));
}

void CSession::Send(std::string msg, int max_len, short msg_id) {
    std::lock_guard<std::mutex> lock(_send_lock);
    int send_que_size = _send_queue.size();
    if (send_que_size > MAX_SENDQUE) {
        std::cout << "session :" << _uuid << " send que failed, size is" << MAX_SENDQUE << "\n";
        return;
    }

    _send_queue.push(std::make_shared<SendNode>(msg.c_str(), msg.length(), msg_id));
    if (send_que_size > 0) {
        return;
    }
    auto& node = _send_queue.front();
    boost::asio::async_write(_socket, boost::asio::buffer(node->_data, node->_total_len), std::bind(
        &CSession::HandleWrite, this, std::placeholders::_1, SessionSelf()
    ));
}

void CSession::HandleWrite(const boost::system::error_code& ec, std::shared_ptr<CSession> session) {
    try
    {
        if (!ec) {
            std::lock_guard<std::mutex> lock(_send_lock);
            _send_queue.pop();
            if (!_send_queue.empty()) {
                auto& node = _send_queue.front();
                boost::asio::async_write(_socket, boost::asio::buffer(node->_data, node->_total_len), std::bind(
                    &CSession::HandleWrite, this, std::placeholders::_1, session
                ));
            }
        }
        else {
            std::cout << "Handle Write Failed, error is " << ec.what() << "\n";
            Close();
            //DOTO ��server�б����Ƴ���csession
            _server->ClearSession(_uuid);
        }
    }
    catch (const std::exception& e)
    {
        std::cerr << "Exception code : " << e.what() << std::endl;
    }

}

void CSession::HandleRead(const boost::system::error_code& ec, std::size_t bytes_transferred, std::shared_ptr<CSession> session) {
    if (!ec) {
        int copy_len = 0;
        while (bytes_transferred > 0) {
            if (!_b_head_parse) {
                if (bytes_transferred < HEAD_TOTAL_LEN) {//���յ���ͷ����Ϣ���̵�����
                    memcpy(_recv_head_node->_data + _recv_head_node->_cur_len, _data, bytes_transferred);
                    _recv_head_node->_cur_len += bytes_transferred;
                    memset(_data, 0, MAX_LENGHT);
                    _socket.async_read_some(boost::asio::buffer(_data, MAX_LENGHT), std::bind(
                        &CSession::HandleRead, this, std::placeholders::_1, std::placeholders::_2, session
                    ));
                    return;
                }
                //���յ������ݱ�ͷ����
                int remain_head = HEAD_TOTAL_LEN - _recv_head_node->_cur_len;
                memcpy(_recv_head_node->_data + _recv_head_node->_cur_len, _data, remain_head);
                _recv_head_node->_cur_len += remain_head;
                bytes_transferred -= remain_head;
                copy_len += remain_head;

                //��ȡ��ϢID
                short msg_id = 0;
                memcpy(&msg_id, _recv_head_node->_data, HEAD_ID_LEN);
                //ת�������ֽ���
                msg_id = boost::asio::detail::socket_ops::network_to_host_short(msg_id);
                std::cout << "msg id is " << msg_id << "\n";
                if (msg_id > MAX_LENGHT) {
                    std::cout << "invalid msg_id is" << msg_id << "\n";
                    //DOTO ����ǰ��Session�Ͽ�
                    _server->ClearSession(_uuid);
                    return;
                }

                //��ȡ����
                short msg_len = 0;
                memcpy(&msg_len, _recv_head_node->_data + HEAD_ID_LEN, HEAD_MSG_LEN);
                msg_len = boost::asio::detail::socket_ops::network_to_host_short(msg_len);
                std::cout << "msg_len is" << msg_len << "\n";
                if (msg_len > MAX_LENGHT) {
                    std::cout << "invalid msg_len is " << msg_len << "\n";
                    //DOTO ����ǰ��Session�Ͽ�
                    _server->ClearSession(_uuid);
                    return;
                }

                _recv_msg_node = std::make_shared<RecvNode>(msg_len, msg_id);
                if (bytes_transferred < msg_len) {//���յ����� һ�����ݵ���Ϣ 
                    memcpy(_recv_msg_node->_data + _recv_msg_node->_cur_len, _data + copy_len, bytes_transferred);
                    _recv_msg_node->_data += bytes_transferred;
                    memset(_data, 0, MAX_LENGHT);
                    _socket.async_read_some(boost::asio::buffer(_data, MAX_LENGHT), std::bind(
                        &CSession::HandleRead, this, std::placeholders::_1, std::placeholders::_2, session
                    ));
                    _b_head_parse = true;
                    return;
                }

                memcpy(_recv_msg_node->_data + _recv_msg_node->_cur_len, _data, msg_len);
                _recv_msg_node->_cur_len += msg_len;
                bytes_transferred -= msg_len;
                copy_len += msg_len;
                _recv_msg_node->_data[_recv_msg_node->_total_len] = '\0';

                std::cout << "_data is " << _data << "\n";
                std::cout << "receive data is" << _recv_msg_node->_data << "\n";
                std::cout << "receive data total_len is" << _recv_msg_node->_total_len << "\n";
                std::cout << "receive data msg_cur_len is" << _recv_msg_node->_cur_len << "\n";
                std::cout << "receive data msg_len is" << std::strlen(_recv_msg_node->_data) << "\n";

                //DOTO���ͻؿͻ���

                //������ȡʣ�������
                _b_head_parse = false;
                _recv_head_node->Clear();
                if (bytes_transferred <= 0) {
                    memset(_data, 0, MAX_LENGHT);
                    _socket.async_read_some(boost::asio::buffer(_data, MAX_LENGHT), std::bind(
                        &CSession::HandleRead, this, std::placeholders::_1, std::placeholders::_2, session
                    ));
                    return;
                }
                continue;
            }

            int remain_msg = _recv_msg_node->_total_len - _recv_msg_node->_cur_len;
            if (bytes_transferred < remain_msg) {
                memcpy(_recv_msg_node->_data + _recv_msg_node->_cur_len, _data + copy_len, bytes_transferred);
                _recv_msg_node->_cur_len += bytes_transferred;
                memset(_data, 0, MAX_LENGHT);
                _socket.async_read_some(boost::asio::buffer(_data, MAX_LENGHT), std::bind(
                    &CSession::HandleRead, this, std::placeholders::_1, std::placeholders::_2, session
                ));
                return;
            }
            memcpy(_recv_msg_node->_data + _recv_msg_node->_cur_len, _data + copy_len, remain_msg);
            _recv_msg_node->_cur_len += remain_msg;
            bytes_transferred -= remain_msg;
            copy_len += remain_msg;
            _recv_msg_node->_data[_recv_msg_node->_total_len] = '\0';

            //DOTO ���ͻؿͻ���
            _b_head_parse = false;
            _recv_head_node->Clear();
            if (bytes_transferred <= 0) {
                memset(_data, 0, MAX_LENGHT);
                _socket.async_read_some(boost::asio::buffer(_data, MAX_LENGHT), std::bind(
                    &CSession::HandleRead, this, std::placeholders::_1, std::placeholders::_2, session
                ));
                return;
            }
            continue;
        }
    }
    else {
        std::cout << "Handle Read Faile, error is " << ec.what() << "\n";
        Close();
        //DOTO ��server�б����Ƴ���csession
        _server->ClearSession(_uuid);
    }
}

void CSession::HandleReadHead(const boost::system::error_code& ec, std::size_t bytes_transferred, std::shared_ptr<CSession> session) {
    if (!ec) {
        if (bytes_transferred < HEAD_TOTAL_LEN) {
            std::cout << "read head error \n";
            Close();
            _server->ClearSession(_uuid);
            return;
        }
        short msg_id = 0;
        memcpy(&msg_id, _recv_head_node->_data, HEAD_ID_LEN);
        msg_id = boost::asio::detail::socket_ops::network_to_host_short(msg_id);
        std::cout << "read msg_id is " << msg_id << "\n";
        if (msg_id > MAX_LENGHT) {
            std::cout << "invalid msg_id is" << msg_id << "\n";
            Close();
            _server->ClearSession(_uuid);
            return;
        }
        short msg_len = 0;
        memcpy(&msg_len, _recv_head_node->_data + HEAD_ID_LEN, HEAD_MSG_LEN);
        msg_len = boost::asio::detail::socket_ops::network_to_host_short(msg_len);
        std::cout << "read msg_len is " << msg_len << "\n";
        if (msg_len > MAX_LENGHT) {
            std::cout << "invalid msg_len is" << msg_id << "\n";
            Close();
            _server->ClearSession(_uuid);
            return;
        }

        _recv_msg_node = std::make_shared<RecvNode>(msg_len, msg_id);
        boost::asio::async_read(_socket, boost::asio::buffer(_recv_msg_node->_data, _recv_msg_node->_cur_len), std::bind(
            &CSession::HeadleReadMsg, this, std::placeholders::_1, std::placeholders::_2, session
        ));
    }
    else {
        std::cout << "Handle Read Head Failed, error is" << ec.what() << "\n";
        Close();
        _server->ClearSession(_uuid);
    }
}
void CSession::HeadleReadMsg(const boost::system::error_code& ec, std::size_t bytes_transferred, std::shared_ptr<CSession> session) {
    if (!ec) {
        _recv_msg_node->_data[_recv_msg_node->_total_len] = '\0';
        std::cout << "read data is:" << _recv_msg_node->_data << "\n";

        _recv_head_node->Clear();
        boost::asio::async_read(_socket, boost::asio::buffer(_recv_head_node->_data, HEAD_TOTAL_LEN), std::bind(
            &CSession::HandleReadHead, this, std::placeholders::_1, std::placeholders::_2, session
        ));
    }
    else {
        std::cout << "Heandle Read Msg failed, error is " << ec.what() << "\n";
        Close();
        _server->ClearSession(_uuid);
    }
}

LogicNode::LogicNode(std::shared_ptr<CSession> session, std::shared_ptr<RecvNode> recvNode):_session(session),_recvnode(recvNode) {}