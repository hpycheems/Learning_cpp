#pragma once
#include "CSession.h"

#include <map>

class CServer {
public:
	CServer(boost::asio::io_context& io_context, short port);
	void ClearSession(std::string uuid);
private:
	void HandleAccept(std::shared_ptr<CSession> session, const boost::system::error_code& error);
	void StartAccept();
	boost::asio::io_context& _io_context;
	short _port;
	tcp::acceptor _acceptor;
	std::map<std::string, std::shared_ptr<CSession>> _sessions;
};