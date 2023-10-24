#include "Session.h"

#include <vector>
#include <iostream>



std::vector<std::shared_ptr<int>> v;

void func() {
	std::shared_ptr<int> m = std::make_shared<int>(10);
	std::cout << m.use_count() << "\n";

	v.push_back(m);

	std::cout << m.use_count() << "\n";

	auto f = [m]() {
		std::cout << m.use_count() << "\n";
	};
	f();
}

int main() {

	try
	{
		boost::asio::io_context io;

		Server s(io, 3333);

		io.run();
	}
	catch (const std::exception& e)
	{
		std::cout << e.what() << "\n";
	}
	//func();
	//std::cout << v[0].use_count() << "\n";

	system("puase");
	return 0;
}