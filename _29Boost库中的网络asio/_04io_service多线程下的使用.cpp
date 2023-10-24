#include <iostream>
#include <boost/asio.hpp>
#include <functional>
#include <boost/date_time/posix_time/posix_time.hpp>
#include <thread>

class printer {
public:
	printer(boost::asio::io_service& io) :
		timer_{ boost::asio::deadline_timer(io, boost::posix_time::seconds(1)) },
		timer2_{ boost::asio::deadline_timer(io, boost::posix_time::seconds(1)) },
		count_(0), 
		strand_{ io }  {
		//timer_.async_wait([this](const auto& error) {
		//	if (error == boost::asio::error::operation_aborted) {
		//		std::cout << "cancel now\n";
		//	}
		//	else {
		//		this->print();
		//	}
		//	});
		////timer_.async_wait(std::bind(&printer::print, this));
		timer_.async_wait(strand_.wrap([this](const auto&) {this->print(); }));
		timer2_.async_wait(strand_.wrap([this](const auto&) {this->print2(); }));
	}
	~printer() {
		//timer_.cancel();此时调用cancel已经晚了
		std::cout << "Final count is " << count_ << std::endl;
	}
	void print() {
		if (count_ < 10) {
			std::cout << "Timer 1:" << count_ << std::endl;
			++count_;

			timer_.expires_at(timer_.expires_at() + boost::posix_time::seconds(1));
			timer_.async_wait(strand_.wrap([this](const auto&) {this->print(); }));
		}
	}
	void print2() {
		if (count_ < 10) {
			std::cout << "Timer 2:" << count_ << std::endl;
			++count_;

			timer2_.expires_at(timer2_.expires_at() + boost::posix_time::seconds(1));
			timer2_.async_wait(strand_.wrap([this](const auto&) {this->print2(); }));
		}
	}
private:
	/*
	* 主要用于在多线程环境中保护数据不被多个线程同时访问。它通过将任务封装在一个函数对象中，
	   确保在执行任务时只有一个线程可以访问共享资源。这样可以防止数据竞争和死锁等问题。
	*/
	boost::asio::io_service::strand strand_;
	boost::asio::deadline_timer timer_;
	boost::asio::deadline_timer timer2_;
	int count_;
};

int main4() {
	boost::asio::io_service io;
	printer p(io);
	std::thread t([&io] {io.run(); });//当 调用io.run后，io.run中不存在回调函数，然后就把io设置为stop状态
	//当io处于stop状态后，再次调用 run就会直接返回
	//io.run();
	//可以让 io重新启动
	//if (io.stopped()) {
	//	io.restart();
	//}
	//io.run();
	//但还是建议在 run之间把回调函数绑定好后再调用run
	if(t.joinable())
		t.join();
	return 0;
}