#include <iostream>
#include <boost/asio.hpp>//����asio�඼����ͨ���򵥵İ�����asio.hpp����ʹ��
#include <boost/bind/bind.hpp>
#include <boost/asio/steady_timer.hpp>
//#include <boost/date_time/posix_time/posix_time.hpp>

//#include "boost/lexical_cast.hpp"

/*
* Boost�⣺
*	�Ӵ��Ҹ���
*	��׼��ı�ѡ��
*	��������Ŀ��ˮ׼�ܸ�
*	����ḻ
*
* ��������Ŀ�ֻ��һ�� asio
*	����������͵ײ�IO��̵Ŀ�ƽ̨C++�⣬Ϊ�������ṩ��C++�������ȶ����첽ģ��
*	����ֲ��
*	����չ��
*	Ч��
*	������BSD Socketsһ��ͨ��API��������ģ�͸���
*	����ʹ��
*   ���ڸ���ĳ���
*
* ͬ��
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

#pragma region Boost�����ò��Դ���
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

	// io_serveice ͬ�����

	//boost::asio::io_service io;
	//boost::asio::deadline_timer t(io, boost::posix_time::seconds(5));
	//t.wait();//�߳����� 5��

	// io_serveice �첽���

	//boost::asio::io_service io;
	//boost::asio::deadline_timer t(io, boost::posix_time::seconds(5));
	//t.async_wait(callback);//�����첽������ �ȴ�5������ callback����
	//boost::asio::deadline_timer t2(io, boost::posix_time::seconds(2));
	//t2.async_wait([](const boost::system::error_code&) {std::cout << "Second \n"; });
	//std::cout << "run start\n";
	//io.run();// ioѭ�� ����������ĺ��������������������������
	//std::cout << typeid(io).name() << "\n";
	//std::cout << "run finish \n";
	//system("pause");

	//��� ʹ���첽���ʵ�� t2�ص��������ú�ֱ�ӵ���t1

	//steady_timer ��ʹ�� //asio��ͬ�����첽����
	/*
	* ����asio�ĳ�����Ҫ����һ��I/Oִ�������ģ�����io_context��thread_pool����I/Oִ���������ṩ��I/O���ܵķ��ʡ�

	boost::asio::io_context io;
	//�ṩI/O���ܵĺ���asio��ʼ�ս�ִ������ִ�������ĵ����ã��� io_context����Ϊ��һ�����캯���Ĳ���
	boost::asio::steady_timer t(io, std::chrono::seconds(3)); //��ʱ�� ֻ��������״̬���ѹ��ڡ�����δ���ڡ�������ڹ��ڵļ�ʱ���ϵ���wait()������������������
	std::cout << "run\n";
	//t.wait();//ͬ������
	t.async_wait(printCallback);//�첽�ȴ�
	io.run();//asio�Ᵽ֤���ӵ�ǰ����io_context::run()���̵߳�����ɴ��������ˣ����ǵ���io_context.run()������������Զ������õȴ���ɵ���ɴ������
	//��ioû���κι���Ҫ��ʱ������������
	//t.async_wait();
	std::cout << "finish \n"; */


	//ʹ��asioʵ���ظ���ʱ��
	boost::asio::io_context io_;
	boost::asio::steady_timer t(io_, std::chrono::seconds(1));
	int count = 1;
	t.async_wait(boost::bind(print_, boost::asio::placeholders::error, &t, &count));
	//t.async_wait([&t, &count](auto error) {print_(error, std::move(t),count); });
	io_.run();
	return 0;
}