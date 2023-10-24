#include <iostream>
#include <boost/asio.hpp>
#include <functional>
#include <boost/date_time/posix_time/posix_time.hpp>

class printer_ {
public:
	printer_(boost::asio::io_service& io) :
		timer_{boost::asio::deadline_timer (io, boost::posix_time::seconds(5))}, 
		count_(0) { 
		timer_.async_wait([this](const auto& error) {
			if (error == boost::asio::error::operation_aborted) {
				std::cout << "cancel now\n";
			}
			else {
				this->print();
			}
			});
		//timer_.async_wait(std::bind(&printer::print, this));
	}
	~printer_() {
		//timer_.cancel();此时调用cancel已经晚了
		std::cout << "Final count is " << count_ << std::endl;
	}
	void print() {
		if (count_ < 5) {
			std::cout << count_ << std::endl;
			++count_;

			timer_.expires_at(timer_.expires_at() + boost::posix_time::seconds(1));
			timer_.async_wait([this](const auto& error) {
				if (error == boost::asio::error::operation_aborted) {
					std::cout << "cancel now\n";
				}
				else {
					this->print();
				}
				});
		}
	}
private:
	boost::asio::deadline_timer timer_;
	int count_;
};

int main3() {

	boost::asio::io_service io;
	printer_ p(io);

	io.run();
	return 0;
}