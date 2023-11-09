#include "CServer.h"

CServer::CServer(boost::asio::io_context& io_context, short port) :_io_context(io_context),
_acceptor(io_context, tcp::endpoint(tcp::v4(), port)), _port(port) {
    std::cout << "Server start success, listen on port : " << _port << std::endl;
    StartAccept();
}
void CServer::ClearSession(std::string uuid) {
    _sessions.erase(uuid);
}
void CServer::StartAccept() {
    std::shared_ptr<CSession> newSession = std::make_shared<CSession>(_io_context, this);
    _acceptor.async_accept(newSession->GetSocket(), std::bind(
        &CServer::HandleAccept, this, std::placeholders::_1, newSession
    ));
}
void CServer::HandleAccept(const boost::system::error_code& ec, std::shared_ptr<CSession> newSession) {
    if (!ec) {
        newSession->Start();
        _sessions.insert(std::make_pair(newSession->GetUuid(), newSession));
    }
    else {
        std::cout << "session accept failed, error is" << ec.what() << "\n";
    }
    StartAccept();
}