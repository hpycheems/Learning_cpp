#include <boost/asio.hpp>

#include <memory>
#include <iostream>
#include <string>

#include <ctime>

using boost::asio::ip::tcp;

std::string make_daytime_string_() {
	using namespace std;
	time_t now = time(nullptr);
	char time_str[26];
	ctime_s(time_str, sizeof(time_str), &now);
	return time_str;
}

class tcp_connection :public std::enable_shared_from_this<tcp_connection> {
	
public:
	tcp_connection(tcp::socket socket) :socket_{std::move(socket)} {
		
	}
	void start() {
		do_read();
	}
private:
	void do_read() {//读取客户端发送过来的消息
		auto self(shared_from_this());
		socket_.async_read_some(boost::asio::buffer(data_, max_length),
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
	tcp_connection(boost::asio::io_context& io) :socket_{io} {}
	void handle_write(const boost::system::error_code&, size_t) {}
	tcp::socket socket_;
	enum { max_length = 1024 };
	char data_[max_length];
};


class tcp_server{
public:
	tcp_server(boost::asio::io_context& io) : acceptro_{ io, tcp::endpoint(tcp::v4(), 13) } {
		start_accept();
	}
private:
	void start_accept() {
		//tcp_connection::pointer new_connection = tcp_connection::create(io);
		acceptro_.async_accept([this](boost::system::error_code ec, tcp::socket socket) {
			if (!ec) {
				std::make_shared<tcp_connection>(std::move(socket))->start();
				}
			start_accept();
			});
	}
	
	tcp::acceptor acceptro_;
};

int main7() {

	try
	{
		boost::asio::io_context io;
		tcp_server s(io);
		io.run();
	}
	catch (const std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}

	system("pause");
	return 0;
}
