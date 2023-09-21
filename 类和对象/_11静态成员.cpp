#include <iostream>
using namespace std;
#include<string>
//静态成员
// 在成员变量和成员函数前加上关键字static，称为静态成员
// 静态成员变量
// 静态成员函数

class Person_3 {
public:
	//静态成员变量
	//1 所有对象共享同一份数据
	//2 编译阶段就分配内存
	//3 类内声明，类外初始化操作
	static int m_A;

	//静态成员函数
	// 所有对象共享同一个函数
	// 静态成员函数只能访问静态成员变量
	static void func() {
		m_B = 300;//静态成员函数可以访问静态成员变量
		cout << "func 静态成员函数调用" << endl;
	}
private:
	//静态成员变量也有访问权限
	static int m_B;
	//静态成员函数也有访问权限
	void func1() {
		cout << "func1 静态成员函数调用" << endl;
	}
};

int Person_3::m_A = 100;// 类外初始化操作
int Person_3::m_B = 200;

void test_4() {
	//Person_3 p;
	//cout << p.m_A << endl;

	//静态成员的访问方式 2种
	// 对象访问
	Person_3 p1;
	cout << p1.m_A << endl;
	p1.func();

	// 类名访问
	cout << Person_3::m_A << endl;
	Person_3::func();

	// 类外访问不到私有的成员变量
	//cout << Person_3::m_B << endl;
	//Person_3::func1();
}

int main11() {
	//Person_3::m_A = 99;
	test_4();
	system("pause");
	return 0;
}