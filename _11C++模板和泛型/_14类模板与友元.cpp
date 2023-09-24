#include <iostream>
using namespace std;

template<class T1, class T2>
class Person1;

template<class T1, class T2>
void func1(Person1<T1, T2> p) {
	cout << "类外实现————" << p.m_Name << " " << p.m_Age << endl;
}

template<class T1, class T2>
class Person1{
	//全局函数内类实现
	friend void func(Person1<T1,T2> &p) {
		cout << p.m_Name << " " << p.m_Age << endl;
	}

	//全局函数类外实现
	//切记 加上空模板参数列表 不加则为不同全局函数
	friend void func1<>(Person1<T1, T2> p);
public:
	Person1(T1 name, T2 age);
private:
	T1 m_Name;
	T2 m_Age;
};

template<class T1, class T2>
Person1<T1,T2>::Person1(T1 name,T2 age){
	this->m_Age = age;
	this->m_Name = name;
}

void test14_1() {

	Person1<string, int> p("Tom", 19);
	func(p);
}
void test14_2() {
	Person1<string, int> p("Tom", 19);
	func1(p);
}

int main14() {
	test14_1();
	test14_2();
	system("pause");
	return 0;
}
