#include <iostream>
using namespace std;
#include <string>

// 继承中同名的静态成员在子类对像上如何进行访问？

//静态成员和非静态成员处理方式是一样的

class Base1 {
public :

	static void func() {
		cout << "base static void func()" << endl;
	}
	static void func(int a) {
		cout << "base static void func(int a)" << endl;
	}

	static int m_A;
};
int Base1::m_A = 100;

class Son :public Base1{
public :
	static void func() {
		cout << "Son static void func()" << endl;
	}

	static int m_A;

};
int Son::m_A = 200;

void test6_1() {
	Son s;
	cout << "对象调用方式！" << endl;
	cout << "son 下 m_A = " << s.m_A << endl;
	cout << "base 下 m_A = " << s.Base1::m_A << endl;
	
	cout << "类名调用方式" << endl;
	cout << "son 下 m_A = " << Son::m_A << endl;
	//第一个:: 代表同类名方式访问， 第二个::代表访问父类作用域下
	cout << "base 下 m_A = " << Son::Base1::m_A << endl;
}

void test6_2() {
	Son s;
	cout << "对象调用方式" << endl;
	s.func();
	s.Base1::func();

	cout << "类名调用方式" << endl;
	Son::func();
	Son::Base1::func();

	Son::Base1::func(100);
}

int main6() {

	//test6_1();
	test6_2();
	system("pause");
	return 0;
}