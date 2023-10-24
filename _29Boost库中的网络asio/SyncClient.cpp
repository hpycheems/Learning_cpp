#include "MsgNode.h"

#include <boost/asio.hpp>

#include <chrono>
#include <iostream>
#include <thread>

using boost::asio::ip::tcp;



int main() {
	try
	{
		boost::asio::io_context ioc;
		tcp::endpoint ep(boost::asio::ip::address::from_string("127.0.0.1"), 8888);
		tcp::socket sock(ioc);//创建socket
		boost::system::error_code ec = boost::asio::error::host_not_found;
		sock.connect(ep, ec);//连接服务端
		if (ec) {
			std::cout << "connect failed,code is:" << ec.value()
				<< "error Message" << ec.what() << "\n";
			return 0;
		}

		//std::thread t1([&sock]{
		//	while (true) {
		//		std::this_thread::sleep_for(std::chrono::milliseconds(2));//让线程休息两毫秒
		//		const char* request = "hello world";
		//		short request_length = std::strlen(request);
		//		char send_data[MAX_LENGTH] = { 0 };
		//		memcpy(send_data, &request_length, 2);
		//		memcpy(send_data + 2, request, request_length);
		//		boost::asio::write(sock, boost::asio::buffer(send_data, request_length + 2));
		//	}
		//});
		//
		//std::thread t2([&sock] {
		//	while (true) {
		//		std::this_thread::sleep_for(std::chrono::milliseconds(2));//让线程休息两毫秒
		//		std::cout << "begin to receive..\n";
		//		char reply_head[HEAD_LENGTH];
		//		std::size_t reply_length = boost::asio::read(sock,boost::asio::buffer(reply_head, HEAD_LENGTH));
		//		short msgLen = 0;
		//		memcpy(&msgLen, reply_head, HEAD_LENGTH);

		//		char msg[MAX_LENGTH];
		//		std::size_t msg_Length = boost::asio::read(sock, boost::asio::buffer(msg, msgLen));

		//		std::cout << "Reply is: ";
		//		std::cout.write(msg, msgLen) << std::endl;
		//		std::cout << "Reply len is:" << msgLen;
		//		std::cout << "\n";
		//	}
		//	});

		//t1.join();
		//t2.join();

		std::cout << "Enter message: ";
		char request[MAX_LENGTH];
		std::cin.getline(request, MAX_LENGTH);
		size_t request_length = strlen(request);
		char send_data[MAX_LENGTH] = { 0 };
		memcpy(send_data, &request_length, 2);
		memcpy(send_data + 2, request, request_length);
		boost::asio::write(sock, boost::asio::buffer(send_data, request_length + 2));


		//读取服务端 发送回来的信息
		char reply_head[HEAD_LENGTH];
		size_t reply_length = boost::asio::read(sock, boost::asio::buffer(reply_head, HEAD_LENGTH));
		short msglen = 0;
		memcpy(&msglen, reply_head, HEAD_LENGTH);
		char msg[MAX_LENGTH] = { 0 };
		size_t  msg_length = boost::asio::read(sock, boost::asio::buffer(msg, msglen));

		std::cout << "Reply is: ";
		std::cout.write(msg, msglen) << std::endl;
		std::cout << "Reply len is " << msglen;
		std::cout << "\n";
	}
	catch (const std::exception& e)
	{
		std::cerr << "Exception:" << e.what() << '\n';
	}

	return 0;
}