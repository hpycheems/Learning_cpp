#include <iostream>
#include <boost/array.hpp>
#include <boost/asio.hpp>

//ʹ��asioͨ��TCPʵ�ֿͻ���Ӧ�ó���
//Ŀ���Ƿ������ڷ��� ��Ҫ�ֶ�ָ��������
using tcp = boost::asio::ip::tcp;
int main5(int argc, char* argv[]) {
	try
	{
		if (argc != 2) {
			std::cout << "Usage: client <host>" << std::endl;
			return 1;
		}
		boost::asio::io_context io;
		//��Ҫ��ָ��Ϊ��������ķ���������ת��ΪTCP�յ㡣
		tcp::resolver resolver(io);
		//�յ��б�ʹ��ip::tcp::resolver::resilts_type���͵Ķ��󷵻ء�
		//�˶�����һ����Χ�����а������ڵ��������begin()��end()��Ա����
		tcp::resolver::results_type endpoints = resolver.resolve(argv[1], "daytime");

		tcp::socket socket(io);//����socket
		//�����õĶ˵��б���ܰ��� IPv4 �� IPv6 �˵㣬���������Ҫ���������е�ÿһ����ֱ���ҵ�һ����Ч�Ķ˵�
		boost::asio::connect(socket, endpoints);

		//��ȡ����
		for (;;) {
			boost::array<char, 128> buf;
			boost::system::error_code error;
			//boost::asio::buffer(buf) �����Զ�ȷ������Ĵ�С���԰�����ֹ���������
			size_t len = socket.read_some(boost::asio::buffer(buf), error);

			//���ر�����ʱ�� read_some()�������˳�����ʾ eof����
			if (error == boost::asio::error::eof) {//ȫ����ȡ���
				break;
			}
			else if (error) {
				throw boost::system::system_error(error);
			}

			std::cout.write(buf.data(), len);
		}
	}
	catch (const std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
	
	

	system("pause");
	return 0;
}