#include <iostream>
using namespace std;
#include<string>
// 成员变量 和 成员函数 分开存储

class Person {
	int m_A; // 非静态成员变量， 属于类的对象上
	int m_C;
	static int m_B;//静态成员变量， 不属于类对象上
	void func() {}//非静态成员函数， 不属于类对象上
	static void func1() {}//静态成员函数，不属于类对象上
};

int Person::m_B = 100;

void test1_1() {
	Person p;
	//空对象占用内存空间为1
	//C++编译器会给每个空对象也分配一个字节空间，为了区分对象占内存的位置
	//每个空对象也应该有一个独一无二的内存地址
	cout << "空对象所占用的内存大小：" << sizeof(p) << endl;
}

void test1_2() {
	Person p;
	cout << "对象所占用的内存大小：" << sizeof(p) << endl;
}

int main1() {

	//test1_1();

	test1_1();

	system("pause");
	return 0;
}