#include <iostream>
#include <boost/asio.hpp>//所有asio类都可以通过简单的包含“asio.hpp”来使用
#include <boost/bind/bind.hpp>
#include <boost/asio/steady_timer.hpp>
//#include <boost/date_time/posix_time/posix_time.hpp>

//#include "boost/lexical_cast.hpp"

/*
* Boost库：
*	庞大且复杂
*	标准库的备选库
*	绝大多数的库的水准很高
*	主题丰富
*
* 处理网络的库只有一个 asio
*	是用于网络和底层IO编程的跨平台C++库，为开发者提供了C++环境下稳定的异步模型
*	可移植性
*	可扩展性
*	效率
*	可以像BSD Sockets一样通过API函数建立模型概念
*	易于使用
*   基于更多的抽象
*
* 同步
*	io_service
*   I/O Object
*   e.g. socket
*/

void callback(const boost::system::error_code&) {
	std::cout << "Hello World\n";
}

void printCallback(const boost::system::error_code& error /*e*/) {
	std::cout << "Hello Asio async Operation\n";
}
void print_(const boost::system::error_code& error, boost::asio::steady_timer* t, int* count) {
	if (*count < 6) {
		std::cout << *count << "\n";
		++(*count);
		t->expires_at(t->expiry() + std::chrono::seconds(1));
		t->async_wait(boost::bind(print_, boost::asio::placeholders::error, t, count));
	}
}

int main1() {

#pragma region Boost库引用测试代码
	//using namespace std;
	//cout << "Enter your weight: ";
	//float weight;
	//cin >> weight;
	//string gain = "A 10% increase raises ";
	//string wt = boost::lexical_cast<string> (weight);
	//gain = gain + wt + " to ";      // string operator()
	//weight = 1.1 * weight;
	//gain = gain + boost::lexical_cast<string>(weight) + ".";
	//cout << gain << endl;
#pragma endregion

	// io_serveice 同步风格

	//boost::asio::io_service io;
	//boost::asio::deadline_timer t(io, boost::posix_time::seconds(5));
	//t.wait();//线程阻塞 5秒

	// io_serveice 异步风格

	//boost::asio::io_service io;
	//boost::asio::deadline_timer t(io, boost::posix_time::seconds(5));
	//t.async_wait(callback);//进行异步操作， 等待5秒后调用 callback函数
	//boost::asio::deadline_timer t2(io, boost::posix_time::seconds(2));
	//t2.async_wait([](const boost::system::error_code&) {std::cout << "Second \n"; });
	//std::cout << "run start\n";
	//io.run();// io循环 它里面监听的函数，如果都做完了则往下运行
	//std::cout << typeid(io).name() << "\n";
	//std::cout << "run finish \n";
	//system("pause");

	//如何 使用异步风格实现 t2回调函数调用后直接调用t1

	//steady_timer 的使用 //asio的同步、异步功能
	/*
	* 所有asio的程序都需要至少一个I/O执行上下文，例如io_context或thread_pool对象，I/O执行上下文提供对I/O功能的访问。

	boost::asio::io_context io;
	//提供I/O功能的核心asio类始终将执行器或执行上下文的引用（如 io_context）作为第一个构造函数的参数
	boost::asio::steady_timer t(io, std::chrono::seconds(3)); //计时器 只存在两种状态”已过期“，”未过期“，如果在过期的计时器上调用wait()函数，它将立即返回
	std::cout << "run\n";
	//t.wait();//同步阻塞
	t.async_wait(printCallback);//异步等待
	io.run();//asio库保证仅从当前调用io_context::run()的线程调用完成处理程序。因此，除非调用io_context.run()函数，否则永远不会调用等待完成的完成处理程序。
	//当io没有任何工作要做时，将立即返回
	//t.async_wait();
	std::cout << "finish \n"; */


	//使用asio实现重复计时器
	boost::asio::io_context io_;
	boost::asio::steady_timer t(io_, std::chrono::seconds(1));
	int count = 1;
	t.async_wait(boost::bind(print_, boost::asio::placeholders::error, &t, &count));
	//t.async_wait([&t, &count](auto error) {print_(error, std::move(t),count); });
	io_.run();
	return 0;
}