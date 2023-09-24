#include <iostream>
using namespace std;

template<class T1, class T2>
class Person {

public:
	Person(T1 name, T2 age);
	void func();
	T1 m_Name;
	T2 m_Age;
};
//模板类构造函数类外实现
template<class T1, class T2>
Person<T1, T2>::Person(T1 name, T2 age) {

}
//模板类成员函数类外实现
template<class T1, class T2>
void Person<T1, T2>::func() {

}

int main12() {


	system("pause");
	return 0;
}