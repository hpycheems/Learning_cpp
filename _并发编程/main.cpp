#include <iostream>
#include <thread>

void thread_work(std::string str) {
	std::cout << str << "\n";
}

class thread_backworld {
public:
	void operator()() {
		std::cout << "�º��� ���̵߳���\n";
	}
};

int main() {
	//�̵߳ļ�ʹ��
	std::string str = "hello world!";
	std::thread t1(thread_work, str);
	t1.join();

	//�̵߳��÷º��� Ҳ���ԣ���thread_backworld()����
	std::thread t2{thread_backworld()};
	t2.join();

	//lambda���ʽ
	std::thread t3([](std::string str) {
		std::cout << "str is " << str << "\n";
		}, str);
	t3.join();


	//detachע������

}
void oops() {
	//�����߳���ʹ�þֲ�������
	//��ʹ��detach�������߳�ʱ�����߳̽��������Դ���գ��Ӷ����³������
}
void use_join() {
	//���ʹ��join�ȴ����߳����
}

void catch_exception() {
	
	try {
	
	}
	catch (std::exception& e) {
		//�����̷߳����쳣������Ҫ�����߳̽������׳��쳣
		throw;
	}
}

class thread_guard {
private:
	std::thread& _t;
public:
	explicit thread_guard(std::thread& t) :_t(t) {}
	~thread_guard() {
		if (_t.joinable()) {
			_t.join();
		}
	}

};

//�Զ�����
void auto_guard() {
	int some_local_state = 0;
	std::thread t([]() {});
	thread_guard g(t);
	//�ܹ�ȷ��ִ���һ����ŵ�ʱ�� �߳����˳��˵�
}

void print_str(int i, std::string const& s) {
	
}

//������Ҫʹ����ʽת��
void danger_oops(int som_param) {
	char buffer[1024];
	sprintf(buffer, "%i", som_param);
	//���߳��ڲ���char const* ת��Ϊstd::string
	//ָ�볣�� char const* ָ�뱾���ܱ�
	//����ָ�� const char* ָ������ݲ��ܱ�
	std::thread t(print_str, 3, buffer);
	t.detach();
}
void safe_oops(int some_param) {
	char buffer[1024];
	sprintf(buffer, "%i", some_param);
	std::thread t(print_str, 3, std::string(buffer));
	t.detach();
}

//��
void change_param(int& param) {
	param++;
}

void ref_oops(int some_param) {
	std::cout << "before change, param is" << some_param << "\n";
	//��Ҫʹ��������ʾת��
	std::thread t(change_param, std::ref(some_param));
	t.join();

}