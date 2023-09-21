#include <iostream>
using namespace std;
#include<string>
//
// 每一个非静态成员函数只会诞生一份函数实例，即同类型对象会共用一块代码
// 问题：这一块代码是如何区分哪个对象调用自己的呢？
// C++通过提供特殊指针解决，this指针解决上述问题 ：
// this指针 指向 被调用的成员函数 所属对象

// this指针是隐含在每一个非静态成员函数内的一种指针
// this指针不需要定义，直接使用即可

//this 指针的用途：
// 当形参和成员变量同名时，可用this指针来区分
// 在类的非静态成员函数中返回对象本身，可使用return *this

class Person {
public:
	Person(int age) {
		this->age = age;
	}

	Person& PersonAddAge(const Person & p) {
		age += p.age;
		cout << this << endl;
		return *this;
	}

	int age;
};

// this指针解决名称冲突
void test2_1() {
	Person p(20);
	cout << "p的年龄为：" << p.age << endl;
}
//返回对象本身用*this
void test2_2() {
	Person p1(10);
	Person p2(10);
	//链式编程思想
	p2.PersonAddAge(p1).PersonAddAge(p1).PersonAddAge(p1);
	cout << "p2的年龄:" << p2.age<<endl;
}
int main2() {
	//test2_1();

	test2_2();
	system("pause");
	return 0;
}