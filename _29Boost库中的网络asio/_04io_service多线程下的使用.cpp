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
		//timer_.cancel();��ʱ����cancel�Ѿ�����
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
	* ��Ҫ�����ڶ��̻߳����б������ݲ�������߳�ͬʱ���ʡ���ͨ���������װ��һ�����������У�
	   ȷ����ִ������ʱֻ��һ���߳̿��Է��ʹ�����Դ���������Է�ֹ���ݾ��������������⡣
	*/
	boost::asio::io_service::strand strand_;
	boost::asio::deadline_timer timer_;
	boost::asio::deadline_timer timer2_;
	int count_;
};

int main4() {
	boost::asio::io_service io;
	printer p(io);
	std::thread t([&io] {io.run(); });//�� ����io.run��io.run�в����ڻص�������Ȼ��Ͱ�io����Ϊstop״̬
	//��io����stop״̬���ٴε��� run�ͻ�ֱ�ӷ���
	//io.run();
	//������ io��������
	//if (io.stopped()) {
	//	io.restart();
	//}
	//io.run();
	//�����ǽ����� run֮��ѻص������󶨺ú��ٵ���run
	if(t.joinable())
		t.join();
	return 0;
}