#include <iostream>
using namespace std;
//普通类中的成员函数一开始时就创建
//类模板中成员函数在调用时才去创建
class Person1 {
public:
	void func1() {

	}
};

class Person2 {
public :
	void func2() {

	}
};

template<class T>
class Person {
public:
	T obj;

	void func1() {
		obj.func1();
	}

	void func2() {
		obj.func2();
	}
};
void test9_1() {
	Person<Person2> p;
	//p.func1();
	p.func2();
}

int main9() {

	system("pause");
	return 0;
}