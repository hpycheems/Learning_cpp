#pragma once
#include "MsgNode.h"

#include <boost/asio.hpp>
#include <boost/uuid/uuid_generators.hpp>
#include <boost/uuid/uuid_io.hpp>

#include <queue>
#include <iostream>
#include <memory>
#include <mutex>

using boost::asio::ip::tcp;

class CServer;


class CSession :public std::enable_shared_from_this<CSession> {
public:
	CSession(boost::asio::io_context& io_context, CServer* server);
	~CSession();

	tcp::socket& GetSocket();
	std::string& GetUuid();
	void Start();
	void Send(char* msg, int max_length);
	void Close();
	void PrintRecvData(char* data, int length);
private:

	void HandleRead(const boost::system::error_code& ec, std::size_t bytes_transferred, std::shared_ptr<CSession>);
	void HandleWrite(const boost::system::error_code& ec, std::shared_ptr<CSession>);

	tcp::socket _socket;
	std::string _uuid;
	char _data[MAX_LENGTH];
	CServer* _server;

	std::queue<std::shared_ptr<MsgNode>> _send_queue;
	std::mutex _send_lock;

	std::shared_ptr<MsgNode> _recv_msg_node;
	std::shared_ptr<MsgNode> _recv_head_node;
	bool _b_head_parse;
};