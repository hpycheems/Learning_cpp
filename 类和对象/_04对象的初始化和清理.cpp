#include <iostream>
using namespace std;
#include<string>

//对象的初始化和清理
//	构造函数和析构函数
// 构造函数：用于创建对象时为对象的成员属性赋值，由编译器自动调用，无需手动调用
// 析构函数：对象销毁前系统自动调用，执行一些清理工作
// C++类的 规则 创建时一定会调用构造函数， 释放是一定调用析构函数

class Animal {
public:
	//构造函数
	//没有返回值也不写void
	//函数名与类名相同
	//构造函数可以有参数，可以发生重载
	// 自动调用 只调用一次
	Animal() {
		cout << "Animal的构造函数" << endl;
	}
	//析构函数
	// 没有返回值 不写void
	// 函数名和类名相同 在名称前加~
	// 析构函数不可以有参数
	// 程序在销毁对象前自动调用析构函数，无需手动调用，而且只调用一次
	~Animal() {
		cout << "Animal的析构函数" << endl;
	}
};

// 构造和析构函数都必须有实现，如果没有实现，编译器会提供与一个空实现的构造和析构
void test01() {
	Animal a;
}

int main4() {

	Animal* a = new Animal();
	delete a;

	system("pause");
	return 0;
}