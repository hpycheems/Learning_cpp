//#pragma once
//#include <boost/asio.hpp>
//
//#include <deque>
//#include <iostream>
//#include <memory>
//using namespace boost;
////using boost::asio::ip::tcp;
//const int RECVSIZE = 1024;
//
//class MsgNode {
//public:
//	MsgNode(const char* msg, int total_len) :_total_len{ _total_len }, _cur_len{ 0 } {
//		_msg = new char[total_len];
//		memcpy(_msg, msg, total_len);
//	}
//
//	MsgNode(int total_len) :_total_len{ _total_len }, _cur_len{ 0 } {
//		_msg = new char[total_len];
//	}
//
//	~MsgNode() {
//		delete[] _msg;
//	}
//
//	int _total_len;//总长度
//	int _cur_len;//当前长度
//	char* _msg;//消息
//};
//
//class Session {
//public :
//	Session(std::shared_ptr<asio::ip::tcp::socket> socket);
//	void Connect(const asio::ip::tcp::endpoint& ep);
//
//	void WroteCallBackErr(const boost::system::error_code& ec, std::size_t bytes_transferred,
//		std::shared_ptr<MsgNode> msg_node);
//	void WriteToSocketErr(const std::string& buf);
//
//	void WroteCallBack(const boost::system::error_code& ec, std::size_t bytes_transferred);
//	void WriteToSocket(const std::string& buf);
//
//	void WriteAllToSocket(const std::string& buf);
//	void WriteAllToCallback(const boost::system::error_code& ec, std::size_t bytes_transferred);
//
//	void ReadFromSocket();
//	void ReadCallBack(const boost::system::error_code& ec, std::size_t bytes_transferred);
//
//	void ReadAllFromSocket();
//	void ReadAllCallBack(const boost::system::error_code& ec, std::size_t bytes_transferred);
//private:
//	std::shared_ptr<asio::ip::tcp::socket> _socket;
//	std::shared_ptr<MsgNode> _send_node;
//	std::deque<std::shared_ptr<MsgNode>> _send_deque;
//	bool _send_pending;
//
//	std::shared_ptr<MsgNode> _read_node;
//	bool _read_pending;
//};