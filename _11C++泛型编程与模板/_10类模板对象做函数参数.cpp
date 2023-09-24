#include <iostream>
using namespace std;

//类模板对象做函数参数
template<class T1, class T2>
class Person {
public:
	Person(T1 name, T2 age):m_Name(name),m_Age(age){}
	void Show() {
		cout << m_Name << " " << m_Age << endl;
	}
	T1 m_Name;
	T2 m_Age;
};

// 指定传入类型
void printPerson1(Person<string , int > &p){
	p.Show();
}

void test10_1() {
	Person<string, int> p("孙悟空", 100);
	printPerson1(p);
}

// 参数模型化
template<class T1, class T2>
void printPerson2(Person<T1, T2 >& p) {
	p.Show();
}
void test10_2() {
	Person<string, int> p("猪八戒", 90);
	printPerson2(p);
}

// 整个类模板化
template<class T>
void printPerson3(T & p) {
	p.Show();
}
void test10_3() {
	Person<string, int> p("唐僧", 40);
	printPerson3(p);
}

int main10() {
	test10_1();
	test10_2();
	test10_3();
	system("pause");
	return 0;
}