#include <iostream>
#include <thread>

void thread_work(std::string str) {
	std::cout << str << "\n";
}

class thread_backworld {
public:
	void operator()() {
		std::cout << "仿函数 子线程调用\n";
	}
};

int main() {
	//线程的简单使用
	std::string str = "hello world!";
	std::thread t1(thread_work, str);
	t1.join();

	//线程调用仿函数 也可以（（thread_backworld()））
	std::thread t2{thread_backworld()};
	t2.join();

	//lambda表达式
	std::thread t3([](std::string str) {
		std::cout << "str is " << str << "\n";
		}, str);
	t3.join();


	//detach注意事项

}
void oops() {
	//在子线程中使用局部变量，
	//当使用detach管理子线程时，主线程结束会把资源回收，从而导致程序出错
}
void use_join() {
	//因此使用join等待子线程完成
}

void catch_exception() {
	
	try {
	
	}
	catch (std::exception& e) {
		//当主线程发生异常，必须要让子线程结束再抛出异常
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

//自动守卫
void auto_guard() {
	int some_local_state = 0;
	std::thread t([]() {});
	thread_guard g(t);
	//能够确保执行右花括号的时候 线程是退出了的
}

void print_str(int i, std::string const& s) {
	
}

//尽量不要使用隐式转换
void danger_oops(int som_param) {
	char buffer[1024];
	sprintf(buffer, "%i", som_param);
	//在线程内部将char const* 转化为std::string
	//指针常量 char const* 指针本身不能变
	//常量指针 const char* 指向的内容不能变
	std::thread t(print_str, 3, buffer);
	t.detach();
}
void safe_oops(int some_param) {
	char buffer[1024];
	sprintf(buffer, "%i", some_param);
	std::thread t(print_str, 3, std::string(buffer));
	t.detach();
}

//绑定
void change_param(int& param) {
	param++;
}

void ref_oops(int some_param) {
	std::cout << "before change, param is" << some_param << "\n";
	//需要使用引用显示转换
	std::thread t(change_param, std::ref(some_param));
	t.join();

}