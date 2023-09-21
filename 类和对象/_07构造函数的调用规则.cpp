#include <iostream>
using namespace std;
#include<string>

//构造函数调用规则
//默认情况下，c++编译器至少给一个类添加3个函数
// 1.默认构造函数 (无参，函数体为空)
// 2.无参构造函数 (无参，函数体为空)
// 3.默认拷贝构造函数，对属性进行拷贝

class Person_1 {
public :
	int m_Age;
	Person_1() {
		cout << "Person_1 的默认构造函数" << endl;
	}
	Person_1(int age) {
		m_Age = age;
		cout << "Person_1 的有参构造函数" << endl;
	}
	Person_1(const Person_1& p) {
		m_Age = p.m_Age;
		cout << "Person_1 的拷贝构造函数" << endl;
	}
	~Person_1() {
		cout << "Person_1 的析构函数" << endl;
	}
};

void func_1() {
	Person_1 p;
}
// 如果用户定义 有参构造函数，c++不在提供默认无参构造函数，但是会提供默认拷贝构造
// 如果用户定义 拷贝构造函数，c++不会再提供其他构造函数
void func_2() {
	Person_1 p;
	Person_1 p2(20);
	Person_1 p1(p2);
}

int main7() {

	//func_1();

	func_2();


	system("pause");
	return 0;
}