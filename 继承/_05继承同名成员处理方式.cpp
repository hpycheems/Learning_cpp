#include <iostream>
using namespace std;
#include <string>
//继承中同名成员处理方式
// 如果通过子类对象访问到父类中同名属性 需要 Base::同名属性

class Base1 {
public :
	Base1() {
		m_A = 100;
	}

	void func() {
		cout << "base func()函数调用" << endl;
	}

	void func(int a){
		cout << "base func(int a)函数调用" << endl;
	}

	int m_A;
};

class Son :public Base1 {
public :
	Son() {
		m_A = 200;
	}
	void func() {
		cout << "son func()函数调用" << endl;
	}

	int m_A;
};

void test5_1() {
	Son s;
	// 当父子类中存在同名属性时，子类对象直接使用同名属性，返回的是子类中的属性
	cout << "m_A = " << s.m_A << endl;
	// 当子类对象想要访问父类对象的同名属性时，需要加上父类作用域
	cout << "m_A = " << s.Base1::m_A << endl;
}

void test5_2() {
	Son s;
	// 当父子类中存在同名函数时，子类对象直调用同名函数，调用的是属于子类的函数
	s.func();
	//当子类对象想要调用父类对象的同名函数时，需要加上父类作用域
	s.Base1::func();

	// 当子类中存在同与父类同名的函数时，父类的函数都会被隐藏，只能通过添加作用域来调用
	s.Base1::func(100);
}

int main5() {

	//test5_1();

	test5_2();

	system("pause");
	return 0;
}