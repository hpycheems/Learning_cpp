#include <iostream>
using namespace std;
//C++另一中编程思想称为 泛型编程，主要利用的技术就是模板
//C++提供两种模板机制：函数模板和类模板

//模板不可以直接使用，它只是一个框架
//模板的通用并不是万能

//函数模板语法
//函数模板作用：建立一个通用函数，其函数返回值类型和形参类型可以不具体定制，用一个虚拟的类型来代表。
// 语法：template<typename T> 函数声明或定义
// template -- 声明创建模板
// tempname -- 表示其后面的符号是一种数据类型，可用class代替
// T -- 通用的数据类型，名称可以替换，通常为大写字母



template<typename T>
void mySwap(T& a, T& b) {
	T temp = a;
	a = b;
	b = temp;
}

int main1() {

	int a = 10;
	int b = 20;
	//自动推到
	mySwap(a, b);

	cout << "a = " << a << endl;
	cout << "b = " << b << endl;

	double d1 = 1.1;
	double d2 = 2.2;
	//显式指定类型
	mySwap<double>(d1, d2);

	cout << "d1 = " << d1 << endl;
	cout << "d2 = " << d2 << endl;

	system("pause");
	return 0;
}