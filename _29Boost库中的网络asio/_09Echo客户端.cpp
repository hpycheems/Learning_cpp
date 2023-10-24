#include <cstdlib>
#include <cstring>
#include <iostream>
#include <boost/asio.hpp>

using boost::asio::ip::tcp;
enum {max_length = 1024};

int main9(int argc, char* argv[]) {
	try
	{
		if (argc != 3) {
			std::cout << "Usage: main <host> <port>\n";
			return 1;
		}
		boost::asio::io_context io_context;
		tcp::socket s(io_context);
		tcp::resolver resolver(io_context);
		//同步状态下 resolve有时 可能会非常耗时
		boost::asio::connect(s, resolver.resolve({ argv[1], argv[2] }));

		std::cout << "Enter message:";
		char request[max_length];
		std::cin.getline(request, max_length);
		size_t request_length = std::strlen(request);
		boost::asio::write(s, boost::asio::buffer(request, request_length));

		char reply[max_length];
		size_t reply_lenght = boost::asio::read(s, boost::asio::buffer(reply, request_length));
		std::cout << "Reply is:";
		//std::cout << reply << std::endl;
		std::cout.write(reply, reply_lenght);
		std::cout << "\n";
	}
	catch (const std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
	return 0;
}