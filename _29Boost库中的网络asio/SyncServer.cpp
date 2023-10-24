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
			memset(data, '\0', max_length);//���ڽ�һ���ڴ��������������Ϊָ����ֵ��
			boost::system::error_code ec;
			std::size_t length = socket->read_some(boost::asio::buffer(data, max_length), ec);
			if (ec == boost::asio::error::eof) {//�Զ˹ر�
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
		socket_ptr socket(new tcp::socket(io_context));//����socket������ָ�� �������ָ��ʱҲ�ᴴ��socket
		acceptor.accept(*socket);//����
		//session(socket);
		auto t = std::make_shared<std::thread>(std::bind(session, socket));
		//auto t = std::make_shared<std::thread>(session, socket);
		//auto t = std::make_shared<std::thread>(session);//�����̵߳�����ָ�� 
		//
		//thread_set.insert(t);//�߳�����ָ�� set���� ����֮�� forѭ������֮�� t���ᱻ����ָ������
	}
}

/*
* 1 ͬ����д��ȱ�����ڶ�д�������ģ�����ͻ��˶Զ˲��������ݷ�������read�����������ģ��⽫���·��������������ȴ�״̬��
  2 ����ͨ�������µ��߳�Ϊ�����ɵ����Ӵ����д������һ�����̿��ٵ��߳������޵ģ�ԼΪ2048���̣߳�
    ��Linux��������ͨ��unlimit����һ�����̿��ٵ��߳����������̹߳���Ҳ�ᵼ���л����ĵ�ʱ��Ƭ�϶ࡣ
  3 �÷������Ϳͻ���ΪӦ��ʽ��ʵ�ʳ���Ϊȫ˫��ͨ��ģʽ�����ͺͽ���Ҫ�����ֿ���
  4 �÷������Ϳͻ���δ����ճ������
  ��������������������������Ϳͻ��˴��ڵ����⣬Ϊ����������⣬�����ڽ���������������������ƺ͸Ľ�����Ҫ���첽��д�Ľ�����������
  ��Ȼͬ����д�ķ�ʽҲ�����ŵ㣬����ͻ������������࣬���ҷ����������Բ��ߵĳ���������ʹ��ͬ����д�ķ�ʽ��ʹ��ͬ����д�ܼ򻯱����Ѷȡ�
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