#include "chat_client.hpp"

#include <iostream>

int main_11(int argc, char* argv[]) {

	//�ɰ汾
	/*try
	{
		if (argc != 3) {
			std::cout << "Usage: chat_client <host> <port>\n";
			return 1;
		}

		boost::asio::io_context io_context;

		tcp::resolver resolver(io_context);
		auto endpoints = resolver.resolve({ argv[1], argv[2] });
		chat_client client(io_context, endpoints);

		std::thread t([&io_context] {io_context.run(); });
		char line[chat_message::max_body_lenght + 1];
		while (std::cin.getline(line, chat_message::max_body_lenght + 1)) {
			chat_message msg;
			msg.body_length(std::strlen(line));
			msg.encode_header();
			std::memcpy(msg.body(), line, msg.body_length());
			client.write(msg);
		}

		client.close();
		t.join();
	}
	catch (const std::exception& e)
	{
		std::cerr << "Exception:" << e.what() << "\n";
	}*/

	//�°汾
	try
	{
		if (argc != 3) {
			std::cout << "Usage: chat_client <host> <port>\n";
			return 1;
		}

		boost::asio::io_context io_context;

		tcp::resolver resolver(io_context);
		auto endpoints = resolver.resolve({ argv[1], argv[2] });
		chat_client client(io_context, endpoints);

		std::thread t([&io_context] {io_context.run(); });
		char line[chat_message::max_body_lenght + 1];
		while (std::cin.getline(line, chat_message::max_body_lenght + 1)) {
			New_chat_message msg;
			auto type = 0;
			std::string input(line, line + std::strlen(line));
			std::string output;
			if (paresMessage(input, &type, output)) {
				msg.setMessage(type, output.data(), output.size());
				client.write(msg);
				std::cout << "write message for server" << output.size() << std::endl;
			}
		}

		client.close();
		t.join();
	}
	catch (const std::exception& e)
	{
		std::cerr << "Exception:" << e.what() << "\n";
	}

	//char str[] = "abcd";
	//char* str_ = str + 2;
	//std::cout << *str_ << std::endl;

	//chat_message msg;
	//char arry[] = "abcdefg";
	//msg.body_length(std::strlen(arry));
	//std::memcpy(msg.body(), arry, msg.body_length());
	//msg.encode_header();
	//std::cout << *msg.data() << std::endl;

	//std::cout << arry << std::endl;

	return 0;
}