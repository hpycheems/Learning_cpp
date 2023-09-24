#include <iostream>
using namespace std;

//普通函数与函数模板的区别：
// 普通函数调用时可以发生自动类型转换（隐式类型转换）

void func(int a, int b) {
	int temp = a;
	a = b;
	b = temp;
}


// 函数模板调用时，如果利用自动类型推导，不会发生隐式类型转换

// 如果利用显式指定类型的方式，可以发生隐式类型转换
template<class T>
void func1(T a, T b) {
	T temp = a;
	a = b;
	b = temp;
}

void test4_1() {
	int a = 10;
	int b = 20;
	char c = 'c';
	func(a, c);//隐式类型转换

	//func1(a, c);//报错 ，自动推导类型不能发生类隐式型转换
	func1<int>(a, c);//正确
}

int main4() {
	test4_1();
	system("pause");
	return 0;
}