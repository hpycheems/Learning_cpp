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
		* �����ϵ� Ȼ�󵱷���˽��յ� �ͻ��˷���������Ϣ�� �رտͻ���
		* ��ʱ��������� �����handle_read�Ĵ������session�Ƴ�
		* ֮��������� ��bind handle_write 
		* ��handle_write ���ֽ����˴����� Ȼ����ӡ1054�Զ˹ر���ɵ�д�쳣������ 
		* 
		* ����˲��������ԭ����
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
//����delete this ��������ε��ڴ��ͷ�

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
	std::shared_ptr<Session> new_Session = std::make_shared<Session>(_io, this);//���ü���Ϊ1
	_acceptor.async_accept(new_Session->GetSocket(),
		std::bind(&Server::handle_acceptor, this, new_Session, std::placeholders::_1));//���ü���Ϊ2
	std::cout << "Sever start success !\n";
}

void Server::handle_acceptor(std::shared_ptr<Session> new_session,
	const boost::system::error_code& ec)//��start_accept��������������ü���-1=1
{
	if (!ec) {
		new_session->Start();
		_sessions.emplace(std::make_pair(new_session->GetUuid(), new_session));//���ü���+1=2
	}
	else {
		std::cout << ec.what() << "\n";
	}
	start_accept();
}//���������ü���-1=1

