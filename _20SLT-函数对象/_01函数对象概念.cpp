#include<iostream>
using namespace std;

/*
概念：
 重载函数调用操作符的类，其对象常称为函数对象
 函数对象使用重载的（）时，行为类似函数调用，也叫仿函数
本质：
	函数对象是一个类，不是一个函数
	
仿函数非常灵活，可以作为参数

函数对象使用：
 特点：
	函数对象在使用时，可以像普通函数那样调用，也可以有参数，可以有返回值
	函数对象超出普通函数的概念，函数对象可以有自己的状态
	函数对象可以作为参数传递
*/

//函数对象在使用时，可以像普通函数那样调用，也可以有参数，可以有返回值
class MyAdd{
public:
	int operator()(int num1, int num2) {
		return num1 + num2;
	}
};
void test1_1() {

	MyAdd m;
	cout << m(10, 20) << endl;
}
//函数对象超出普通函数的概念，函数对象可以有自己的状态
class MyPrint {
public:
	MyPrint() {
		this->count = 0;
	}
	int count;
	void operator()(string text) {
		cout << text << endl;
		count++;
	}
};
void test1_2() {
	MyPrint m;
	m("hello ");
	m("hello ");
	m("hello ");
	m("hello ");
	cout << m.count << endl;
}
//函数对象可以作为参数传递

void doPrint(MyPrint& m, string text) {
	m(text);
}

void test1_3() {
	MyPrint m;
	doPrint(m, "C++");
}

int main1(){
	test1_1();
	test1_2();
	test1_3();
	system("pause");
	return 0;
}