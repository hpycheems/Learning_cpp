#include <iostream>
using namespace std;

//函数的默认参数
int func(int a, int b = 20, int c = 30) {
	return a + b + c;
}
//1 如果某个位置已经有了默认参数，那么从这个位置往后，都必须有默认值
//int func1(int a, int b = 10, int c) {
//	return a + b + c;
//}

//2 如果函数声明有默认参数，函数实现不能有默认参数 二义性
// 声明和实现只能有一个存在默认参数
int func2(int a, int b);
int func2(int a = 10, int b = 10) {
	return a + b;
}

//函数的占位参数
void func3(int a, int) {// 目前的占位参数还用不到
	cout << "this is func3" << endl;
}
void func4(int a, int = 10) {// 目前的占位参数还用不到
	cout << "this is func4" << endl;
}


//3 函数重载
	// 同一作用域下
	// 函数名相同
	// 函数参数类型不同，或个数不同 或顺序不同
  //函数返回值不可作为重载条件
void func5() {
	cout << "func5 调用" << endl;
}

void func5(int a) {
	cout << "func5 调用" << a << endl;
}
void func5(double a) {
	cout << "func5 调用" << a << endl;
}
void func5(double a, int b) {
	cout << "func5 调用" << a << endl;
}
void func5(int a, double b) {
	cout << "func5 调用" << a << endl;
}
void func5(float a, double b) {
	cout << "func5(float a, double b) 调用" << a << endl;
}
void func5(double a, float b) {
	cout << "func5(double a, float b) 调用" << a << endl;
}
	//注意事项：引用作为重载条件
	//			函数重载碰到默认参数
void func6(int& a) {
	cout << "func(int &a)调用" << endl;
}
void func6(const int& a) {
	cout << "func(const int& a)调用" << endl;
}

void func7(int a,int b = 10) {
	cout << "func7(int a,int b )调用" << endl;
}
void func7(int a) {
	cout << "func7(int a)调用" << endl;
}

// 函数提高
//	函数的默认参数
//  函数的占位参数
//  函数重载
int main3() {
	
// C++中，函数的形参列表中的参数可以有默认值
	cout << func(10,30) << endl;
	//如果某个位置已经有了默认参数，那么从这个位置往后，都必须有默认值
	//如果函数声明有默认参数，函数实现不能有默认参数
	cout << func2() << endl;

// C++中函数的形参列表里可以有占位参数，用来做占位，调用函数是必须填补该位置
	//语法 返回值类型 函数名 （数据类型）{}
	//占位参数还可以有默认参数
	cout << "===================" << endl;
	func3(10,10);
	func4(10);

// 函数名可以相同，提高复用性
	cout << "===================" << endl;
	func5();
	func5(1);
	func5(3.14, 3.14f);
//注意事项
	cout << "===================" << endl;
	int a = 10;
	func6(a);
	func6(20);

	//func7(10); 出现二义性，避免加默认参数
	func7(10, 10);

	system("pause");
	return 0;
}