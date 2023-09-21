#include<iostream>
using namespace std;
#include<string>
//函数调用运算符重载
// 函数调用运算符（）也可以重载
// 由于重载后使用的方式非常像函数的调用，因此称为仿函数
// 仿函数没有固定写法，非常灵活

class MyPrint {
public :
	//仿函数 ()操作符重载 
	void operator()(string text) {
		cout << text << endl;
	}

};

void test6_1() {
	MyPrint m;
	m("Hello World!");

}
//仿函数没有固定写法，非常灵活

class MyAdd {
public:
	int operator()(int num1, int num2) {
		return num1 + num2;
	}
};

void test6_2() {
	MyAdd m;
	int ref = m(10, 20);
	cout << ref << endl;

	//匿名函数对象
	cout << MyAdd()(20, 30) << endl;
}

int main6() {

	//test6_1();

	test6_2();

	system("pause");
	return 0;
}