#include <boost/asio.hpp>

#include <iostream>

using boost::asio::ip::tcp;

class Session :public std::enable_shared_from_this<Session> {
public:
	Session(tcp::socket socket) : socket_(std::move(socket)) {}
	void Start() {
		do_read();
	}
private:
	void do_read() {//读取客户端发送过来的消息
		auto self(shared_from_this());
		socket_.async_read_some(boost::asio::buffer(data_, max_lenght),
			[this, self](boost::system::error_code ec, size_t length) {
				if (!ec) {
					do_write(length);
				}
			}
		);
	}

	void do_write(int length) {

		auto self(shared_from_this());
		socket_.async_write_some(boost::asio::buffer(data_, length),
			[this, self](boost::system::error_code ec, size_t) {
				if (!ec) {
					do_read();
				}
			}
		);
	}
	tcp::socket socket_;
	enum { max_lenght = 1024 };
	char data_[max_lenght];
};

class Server {
public:
	Server(boost::asio::io_context& io_context, short port) :acceptor_{ io_context,tcp::endpoint( tcp::v4(), port )}, socket_{ io_context } {
	}
	void Start() {
		do_accept();
	}
private:
	void do_accept() {//接收客户端的连接
		acceptor_.async_accept(socket_, [this](boost::system::error_code ec) {
			if (!ec) {
				auto newSession = std::make_shared<Session>(std::move(socket_));
				newSession->Start();
			}
			//有人连接进来则继续调用
			do_accept();//这个方法是绑定的this的方法
			});
	}
	tcp::socket socket_;
	tcp::acceptor acceptor_;
};

//class Empty {
//
//public:
//	Empty(boost::asio::io_context& io) :acceptor_{io,tcp::endpoint( tcp::v4(), 8080)}, socket_ { io } {}
//private:
//	tcp::socket socket_;
//	tcp::acceptor acceptor_;
//};

int main8(int argc, char* argv[]) {
	try
	{
		//if (argc != 2) {
		//	std::cerr << "Usage: async_time_server <port>\n";
		//	return 1;
		//}
		boost::asio::io_context io_context;
		Server server(io_context, 8080);
		server.Start();
		io_context.run();
	}
	catch (const std::exception& e)
	{
		std::cerr << "Exception: " << e.what() << "\n";
	}

	return 0;
}