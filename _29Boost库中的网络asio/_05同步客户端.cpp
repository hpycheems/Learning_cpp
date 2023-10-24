#include <iostream>
#include <boost/array.hpp>
#include <boost/asio.hpp>

//使用asio通过TCP实现客户端应用程序
//目的是访问日期服务， 需要手动指定服务器
using tcp = boost::asio::ip::tcp;
int main5(int argc, char* argv[]) {
	try
	{
		if (argc != 2) {
			std::cout << "Usage: client <host>" << std::endl;
			return 1;
		}
		boost::asio::io_context io;
		//需要将指定为程序参数的服务器名称转换为TCP终点。
		tcp::resolver resolver(io);
		//终点列表使用ip::tcp::resolver::resilts_type类型的对象返回。
		//此对象是一个范围，其中包含用于迭代结果的begin()和end()成员函数
		tcp::resolver::results_type endpoints = resolver.resolve(argv[1], "daytime");

		tcp::socket socket(io);//创建socket
		//上面获得的端点列表可能包含 IPv4 和 IPv6 端点，因此我们需要尝试它们中的每一个，直到找到一个有效的端点
		boost::asio::connect(socket, endpoints);

		//读取数据
		for (;;) {
			boost::array<char, 128> buf;
			boost::system::error_code error;
			//boost::asio::buffer(buf) 函数自动确定数组的大小，以帮助防止缓冲区溢出
			size_t len = socket.read_some(boost::asio::buffer(buf), error);

			//当关闭连接时， read_some()函数将退出并显示 eof错误
			if (error == boost::asio::error::eof) {//全部读取完毕
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