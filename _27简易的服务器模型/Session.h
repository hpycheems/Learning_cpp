#pragma once
#include <boost/asio.hpp>
#include <boost/uuid/uuid_generators.hpp>
#include <boost/uuid/uuid_io.hpp>

#include <iostream>
#include <map>
#include <memory>

using boost::asio::ip::tcp;
class Server;

class Session : public std::enable_shared_from_this<Session> {
public:
	Session(boost::asio::io_context& io_context, Server* server) :_socket{ io_context }, _server(server) {
		boost::uuids::uuid a_uuid = boost::uuids::random_generator()();
		_uuid = boost::uuids::to_string(a_uuid);
	}
	tcp::socket& GetSocket() {
		return _socket;
	}
	std::string GetUuid() {
		return _uuid;
	}
	void Start();
private:
	void handle_read(const boost::system::error_code& ec, std::size_t bytes_transferred, std::shared_ptr<Session>_self_shared);
	void handle_write(const boost::system::error_code& ec, std::shared_ptr<Session>_self_shared);
	tcp::socket _socket;
	enum { max_length = 1024 };
	char _data[max_length];
	std::string _uuid;
	Server* _server;
};

class Server {
public:
	Server(boost::asio::io_context& io, short port);
	void ClearSession(std::string uuid);
private:
	void start_accept();
	void handle_acceptor(std::shared_ptr<Session> new_session, const boost::system::error_code& ec);
	boost::asio::io_context& _io;
	short _port;
	tcp::acceptor _acceptor;
	std::map<std::string, std::shared_ptr<Session>> _sessions;
};