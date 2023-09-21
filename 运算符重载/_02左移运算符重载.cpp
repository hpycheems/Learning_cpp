#include<iostream>
using namespace std;
#include<string>
//左移运算符重载 用于输出对象

class Person {
	friend ostream& operator<<(ostream& cout, Person& p);
public :
	Person(int a, int b) {
		m_A = a;
		m_B = b;
	}
	//利用成员函数重载 左移运算符 p.operator<<(cout) 简化版 p << cout
	//不会利用成员函数重载 << 运算符，因为无法实现 cout 在左侧
	//void operator<<(cout) {
	//
	//}

private :
	int m_A;
	int m_B;
};
// 全局函数重载左移 << 运算符重载
ostream& operator<<(ostream & cout, Person &p) {
	cout << "m_A = " << p.m_A << " m_B = " << p.m_B;
	return cout;
}

void test2_1() {
	Person p(10, 10);


	cout << p << endl;
}

int main2() {
	test2_1();
	system("pause");
	return 0;
}