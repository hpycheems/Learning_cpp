#include <ctime>

#include <iostream>
#include <string>

#include <boost/asio.hpp>

using boost::asio::ip::tcp;

std::string make_daytime_string() {
	using namespace std;
	time_t now = time(nullptr);
	char time_str[26];
	ctime_s(time_str, sizeof(time_str), &now);
	return time_str;
}

int main6() {

	try
	{
		boost::asio::io_context io;
		//����һ�� tcp::acceptor���������������ӡ�����ʼ��Ϊ����TCP�˿�13������IP�汾4
		tcp::acceptor acceptor(io, tcp::endpoint(tcp::v4(), 13));
		std::cout << "Service Start\n";
		for (;;) {
			tcp::socket socket(io);
			acceptor.accept(socket);//���������� �ȴ�һ���ͻ��˵�����

			std::string message = make_daytime_string();
			boost::system::error_code error;
			boost::asio::write(socket, boost::asio::buffer(message), error);
		}
	}
	catch (const std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}

	system("pause");
	return 0;
}