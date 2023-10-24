#include <iostream>
#include <boost/asio.hpp>
#include <boost/bind.hpp>
#include <boost/date_time/posix_time/posix_time.hpp>
//auto lambda = []() {}; 的本质
class Lambda {
public:
	void operator()(int count) const { std::cout << count <<" and " << m_b << std::endl; }
private:
	int m_b;
	int* m_c;
};

//Lambda的本质
void LambdaTest() {
	int b = 2;
	int c = 3;
	auto lambda = [b, &c](int count) {std::cout << count << " and " << b << std::endl; };
	lambda(1);
	std::cout << sizeof(lambda) << std::endl;//16是因为指针为8字节 而int根据内存对齐 则2*8 = 16
	Lambda lambda_;
	lambda_(2);
	std::cout << sizeof(lambda_) << std::endl;
}

void print(const boost::system::error_code& e /* e*/, 
	std::shared_ptr<boost::asio::deadline_timer> t, int* count) {
	if (*count < 5) {
		std::cout << *count <<"t usecount:"<<t.use_count()<< std::endl;
		++(*count);

		t->expires_at(t->expires_at() + boost::posix_time::seconds(1));
		//使用lambda函数代替bind
		t->async_wait([t, count](const auto& error) {print(error, t, count); });
		//t->async_wait(boost::bind(print, boost::asio::placeholders::error, t, count));
	}
}
std::shared_ptr<boost::asio::deadline_timer>
registerPrint(boost::asio::io_service& io, int* count) {
	auto t = 
		std::make_shared<boost::asio::deadline_timer>(io, boost::posix_time::seconds(1));
	t->async_wait([t, count](const auto& error) {print(error, t, count); });
	return t;
	//当 此函数结束后 智能指针调用析构 那么传入到 print中的pt就变成了野指针 程序抛出异常
}
int main2() {
	boost::asio::io_service io;

	//boost::asio::deadline_timer t(io, boost::posix_time::seconds(5));
	std::vector<int> v;
	for (int i = 0; i < 5; ++i){v.push_back(i);}
	for (int i = 0; i < 5; i++)
	{
		auto t = registerPrint(io, &v[i]);
		std::cout << "pointer address is:" << t.get() << std::endl;
	}
	//int count = 0;
	//registerPrint(io, &count);
	//使用lambda函数代替bind
	//t.async_wait([&t, &count](const auto& error) {print(error, &t, &count);});
	//t.async_wait(boost::bind(print, boost::asio::placeholders::error, &t, &count));

	//t在调用到io.run()之前一定要有足够长的声明周期
	io.run();
	//std::cout << "run finish\n ";
	for (int i = 0; i < 5; i++)
	{
		std::cout << "Final count is " << v[i] << std::endl;
	}


	//LambdaTest();

	return 0;
}