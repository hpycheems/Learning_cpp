#include <iostream>
using namespace std;

//如果函数模板和普通函数都可以调用，优先调用普通函数
//可以通过空模板参数列表 强制调用 函数模板
//函数模板可以发生函数重载
//如果函数模板可以产生更好的匹配，优先调用函数模板

void myPrint(int a, int b)
{
	cout << "普通函数调用！" << endl;
}

template<class T>
void myPrint(T a, T b) {
	cout << "模板函数调用！" << endl;
}

template<class T>
void myPrint(T a, T b,T c) {
	cout << "模板重载函数调用！" << endl;
}

void test5_1() {
	int a = 10;
	int b = 20;
	//myPrint(a, b);//如果函数模板和普通函数都可以调用，优先调用普通函数

	//myPrint<>(a, b);//可以通过空模板参数列表 强制调用 函数模板

	//myPrint(a, b, 100);//函数模板可以发生函数重载

	char c = 'c';
	char d = 'd';
	myPrint(c, d);///如果函数模板可以产生更好的匹配，优先调用函数模板
}

int main5() {

	test5_1();
	system("pause");
	return 0;
}