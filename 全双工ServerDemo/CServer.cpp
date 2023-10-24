#include "CServer.h"

CServer::CServer(boost::asio::io_context& io_context, short port) :_io_context{ io_context },
_acceptor(io_context, tcp::endpoint(tcp::v4(), port)), _port(port)
{
	StartAccept();
}

void CServer::ClearSession(std::string uuid)
{
	_sessions.erase(uuid);
}

void CServer::StartAccept()
{
	std::cout << "Server surcces port is :"<< _port << "\n";
	std::shared_ptr<CSession> newSession = std::make_shared<CSession>(_io_context, this);
	_acceptor.async_accept(newSession->GetSocket(), std::bind(
		&CServer::HandleAccept, this, newSession, std::placeholders::_1
	));
}

void CServer::HandleAccept(std::shared_ptr<CSession> session, 
	const boost::system::error_code& error)
{
	if (!error) {
		session->Start();
		_sessions.insert(std::make_pair(session->GetUuid(), session));
	}
	else {
		std::cout << "Accetpr faild, error is :" << error.value() << "\n";
	}
}


