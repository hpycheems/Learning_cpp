#include <iostream>
using namespace std;
#include<string>
class Person {
public :
	//this 指针的本质是指针常量 指针的指向不可修改，指针指向的值可修改
	//Person * const this;
	//在成员函数后面加const，修饰的是this指针，让指针指向的值不可修改
	void showPerson() const {
		//m_Age = 10;
		m_B = 20;
		//this = NULL;
	}

	void func() {}

	int m_Age;
	mutable int m_B;// 特殊变量，即使在常函数中，也可修改，加上关键字mutable
};
//常函数
// 成员函数后加const 
void test4_1() {
	Person p;
	p.showPerson();
}
//常对象
void test4_2() {
	const Person p;//在对象前加const 变为常对象
	//p.m_Age = 100;
	p.m_B = 100;//该属性为特殊值，在常对象下也可进行修改
	p.showPerson();
	//p.func();常对象 不可以调用普通成员函数
}

int main4() {

	test4_1();
	system("pause");
	return 0;
}