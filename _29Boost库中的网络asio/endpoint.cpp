#include "endpoint.h"

#include <boost/asio.hpp>

#include <iostream>

using boost::asio::ip::tcp;

int client_end_point(){
	std::string raw_ip_address = "127.0.0.1";
	std::size_t port_num = 3333;

	boost::system::error_code ec;
	boost::asio::ip::address ip_address = boost::asio::ip::address::from_string(raw_ip_address, ec);
	if (ec.value() != 0) {
		std::cout
			<< "Failed to parse the IP address. Error code = "
			<< ec.value() << ". Message: " << ec.message();
		return ec.value();
	}
	tcp::endpoint ep(ip_address, port_num);
	return 0;
}

int server_end_point() {
	unsigned short prot_num = 3333;

	boost::asio::ip::address ip_address = boost::asio::ip::address_v6::any();

	tcp::endpoint ep(ip_address, prot_num);
	return 0;

}

int create_tcp_socket() {
	boost::asio::io_context io;

	tcp protocol = tcp::v4();

	tcp::socket socket(io);

	boost::system::error_code ec;
	socket.open(protocol, ec);
	if (ec.value() != 0) {
		// Failed to open the socket.
		std::cout
			<< "Failed to open the socket! Error code = "
			<< ec.value() << ". Message: " << ec.message();
		return ec.value();
	}
	return 0;
}

int create_acceptor_socket() {
	boost::asio::io_context io;

	tcp protocol = tcp::v6();

	tcp::acceptor acceptor(io);

	boost::system::error_code ec;
	acceptor.open(protocol, ec);

	if (ec.value() != 0) {
		// Failed to open the socket.
		std::cout
			<< "Failed to open the acceptor socket!"
			<< "Error code = "
			<< ec.value() << ". Message: " << ec.message();
		return ec.value();
	}
	return 0;
}

int bind_acceptor_socket() {
	
	unsigned short port_num = 3333;
	tcp::endpoint ep(tcp::v4(), port_num);
	boost::asio::io_context io;
	tcp::acceptor acceptor(io);
	boost::system::error_code ec;
	acceptor.bind(ep, ec);
	if (ec.value() != 0) {
		// Failed to bind the acceptor socket. Breaking
		// execution.
		std::cout << "Failed to bind the acceptor socket."
			<< "Error code = " << ec.value() << ". Message: "
			<< ec.message();
		return ec.value();
	}
	return 0;
}

int connect_to_end() {
	std::string raw_ip_address = "127.0.0.1";
	unsigned short port_num = 3333;

	try
	{
		boost::asio::io_context io;
		tcp::endpoint ep(boost::asio::ip::address::from_string(raw_ip_address), port_num);
		tcp::socket socket(io);

		socket.connect(ep);
	}
	catch (boost::system::system_error& e)
	{
		std::cout << "Error occured! Error code = " << e.code()
			<< ". Message: " << e.what();
		return e.code().value();
	}
	return 0;
}

int acceptor_new_connection() {
	const int BACKLOG_SIZE = 30;
	unsigned short port_num = 3333;
	boost::asio::ip::tcp::endpoint ep(boost::asio::ip::address_v4::any(),
		port_num);
	boost::asio::io_context  ios;
	try
	{
		boost::asio::ip::tcp::acceptor acceptor(ios, ep.protocol());
		acceptor.bind(ep);
		acceptor.listen(BACKLOG_SIZE);
		tcp::socket socket(ios);
		acceptor.accept(socket);
	}
	catch (boost::system::system_error& e) {
		std::cout << "Error occured! Error code = " << e.code()
			<< ". Message: " << e.what();
		return e.code().value();
	}
}