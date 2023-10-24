#include "Session.h"

void Session::Start() {
	memcpy(_data, 0, max_length);
	_socket.async_read_some(boost::asio::buffer(_data, max_length),
		std::bind(&Session::handle_read, this, std::placeholders::_1, std::placeholders::_2, shared_from_this()));
}

void Session::handle_read(const boost::system::error_code& ec, std::size_t bytes_transferred, std::shared_ptr<Session>_self_shared)
{
	if (!ec) {
		std::cout << "serrver receive data is " << _data << std::endl;
		memcpy(_data, 0, max_length);
		_socket.async_read_some(boost::asio::buffer(_data, max_length),
			std::bind(&Session::handle_read, this, std::placeholders::_1, std::placeholders::_2, _self_shared));
		/*
		* 在这打断点 然后当服务端接收到 客户端发送来的消息后 关闭客户端
		* 此时继续服务端 会调用handle_read的错误处理吧session移除
		* 之后继续运行 到bind handle_write 
		* 在handle_write 中又进行了错误处理 然后会打印1054对端关闭造成的写异常错误码 
		* 
		* 服务端不会崩溃的原因是
		*/
		_socket.async_send(boost::asio::buffer("Hello World"),
			std::bind(&Session::handle_write, this, std::placeholders::_1, _self_shared));
	}
	else {
		std::cout << "handle read failed, error is" << ec.value() << "\n";
		_server->ClearSession(_uuid);
	}
}

void Session::handle_write(const boost::system::error_code& ec, std::shared_ptr<Session>_self_shared)
{
	if (!ec) {
		memcpy(_data, 0, max_length);
		_socket.async_read_some(boost::asio::buffer(_data, max_length),
			std::bind(&Session::handle_read, this, std::placeholders::_1, std::placeholders::_2));
	}
	else {
		std::cout << "handle write failed, error is" << ec.value() << "\n";
		_server->ClearSession(_uuid);
	}
}
//两次delete this 会造成两次的内存释放

Server::Server(boost::asio::io_context& io, short port) : _io(io),
_acceptor(io, tcp::endpoint(tcp::v4(), port)), _port(port)
{
	start_accept();
}

void Server::ClearSession(std::string uuid)
{
	_sessions.erase(uuid);
}

void Server::start_accept()
{
	std::shared_ptr<Session> new_Session = std::make_shared<Session>(_io, this);//引用计数为1
	_acceptor.async_accept(new_Session->GetSocket(),
		std::bind(&Server::handle_acceptor, this, new_Session, std::placeholders::_1));//引用计数为2
	std::cout << "Sever start success !\n";
}

void Server::handle_acceptor(std::shared_ptr<Session> new_session,
	const boost::system::error_code& ec)//当start_accept函数调用完后，引用计数-1=1
{
	if (!ec) {
		new_session->Start();
		_sessions.emplace(std::make_pair(new_session->GetUuid(), new_session));//引用计数+1=2
	}
	else {
		std::cout << ec.what() << "\n";
	}
	start_accept();
}//结束后引用计数-1=1

