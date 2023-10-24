#include <boost/asio.hpp>

#include <iostream>
#include <memory>
#include <set>

using boost::asio::ip::tcp;

using socket_ptr = std::shared_ptr<tcp::socket>;
const int max_length = 1024;
std::set<std::shared_ptr<std::thread>> thread_set;

void session(socket_ptr& socket) {
	try
	{
		for (;;) {
			char data[max_length];
			memset(data, '\0', max_length);//用于将一段内存区域的内容设置为指定的值。
			boost::system::error_code ec;
			std::size_t length = socket->read_some(boost::asio::buffer(data, max_length), ec);
			if (ec == boost::asio::error::eof) {//对端关闭
				std::cout << "connection closed by peer\n";
				break;
			}
			else if (ec) {
				throw boost::system::system_error(ec);
			}
			std::cout << "receive from " << socket->remote_endpoint().address().to_string() << "\n";
			std::cout << "receive message is" << data << std::endl;

			boost::asio::write(*socket, boost::asio::buffer(data, length));
		}
	}
	catch (const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

}
void server(boost::asio::io_context& io_context, std::size_t port) {
	tcp::acceptor acceptor(io_context, tcp::endpoint(tcp::v4(), port));
	for (;;) {
		socket_ptr socket(new tcp::socket(io_context));//管理socket的智能指针 创建这个指针时也会创建socket
		acceptor.accept(*socket);//连接
		//session(socket);
		auto t = std::make_shared<std::thread>(std::bind(session, socket));
		//auto t = std::make_shared<std::thread>(session, socket);
		//auto t = std::make_shared<std::thread>(session);//管理线程的智能指针 
		//
		//thread_set.insert(t);//线程智能指针 set容器 加入之后 for循环结束之后 t不会被智能指针析构
	}
}

/*
* 1 同步读写的缺陷在于读写是阻塞的，如果客户端对端不发送数据服务器的read操作是阻塞的，这将导致服务器处于阻塞等待状态。
  2 可以通过开辟新的线程为新生成的连接处理读写，但是一个进程开辟的线程是有限的，约为2048个线程，
    在Linux环境可以通过unlimit增加一个进程开辟的线程数，但是线程过多也会导致切换消耗的时间片较多。
  3 该服务器和客户端为应答式，实际场景为全双工通信模式，发送和接收要独立分开。
  4 该服务器和客户端未考虑粘包处理。
  综上所述，是我们这个服务器和客户端存在的问题，为解决上述问题，我们在接下里的文章里做不断完善和改进，主要以异步读写改进上述方案。
  当然同步读写的方式也有其优点，比如客户端连接数不多，而且服务器并发性不高的场景，可以使用同步读写的方式。使用同步读写能简化编码难度。
*/

int main_S() {

	try
	{
		boost::asio::io_context io;
		server(io, 8888);

		for (auto& item : thread_set) {
			item->join();
		}
	}
	catch (const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	return 0;
}