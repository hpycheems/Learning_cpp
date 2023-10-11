#include <iostream>
using namespace std;


//6void swap01(int a, int b) {
//	int temp = a;
//	a = b;
//	b = temp;
//}

void swap02(int* num1, int* num2) {
	int temp = *num1;
	*num1 = *num2;
	*num2 = temp;
}

void swap03(int &num1, int &num2) {
	int temp = num1;
	num1 = num2;
	num2 = temp;
}


int& test01() {
	int a = 10;
	return a;
}

int& test02() {
	static int a = 10;//静态变量 ，放在全局区
	return a;
}

void shpwValue(const int &val){
	cout << val << endl;
}


// 引用
// 给变量起别名
// 语法： 数据类型 &别名 = 原名

int main2() {

// 基本用法
	int a = 10;
	int c = 20;
	int& numbera = a;

	cout << numbera << endl;

// 注意事项
	// 引用必须要初始化
	// 初始化后不可修改
	// int& b;//必须要初始化
	numbera = c;//赋值操作 不是更改引用 而是更改引用所指向的数据
	cout << a << endl;
	cout << numbera << endl;
	cout << c << endl;

//引用作函数参数
	//函数传参时，可以利用引用技术让形参修饰实参
	// 优点：可以简化指针修改
	cout << "++++++++++" << endl;
	int num1 = 10;
	int num2 = 20;

	//swap01(num1, num2);
	//cout << num1 << endl;
	//cout << num2 << endl;
	cout << "++++++++++" << endl;
	swap02(&num1, &num2);
	cout << num1 << endl;
	cout << num2 << endl;

	cout << "++++++++++" << endl;
	int num3 = 10;
	int num4 = 20;
	swap03(num3, num4);
	cout << num3 << endl;
	cout << num4 << endl;

// 引用做函数的返回值
	// 不要返回局部变量的引用 因为局部变量内存会在函数执行完毕后被回收
	cout << "==========================" << endl;
	int& ref = test01();
	cout << ref << endl;
	cout << ref << endl;

	// 函数的调用可以作为左值
	int& ref2 = test02();
	cout << ref2 << endl;
	cout << ref2 << endl;
	test02() = 100;
	cout << ref2 << endl;
	cout << ref2 << endl;

// 引用的本质 内部实现是一个指针常量
	cout << "==========================" << endl;
	int number = 20;

	//自动转换成 int * const ref = &a；指针常量指针指向不可修改，也说明为什么引用不可更改
	int& numberRef = number;
	numberRef = 30;//内部发现numberRef是引用，自动转换为：*numberRef = 20

	cout << number << endl;
	cout << numberRef << endl;

// 常量引用 修饰形参 防止误操作
	cout << "==========================" << endl;
	// 编译器将代码修改 int temp =10，const int & ref = temp
	const int& ref11 = 10;
	//ref11 = 20;//加上const 之后不可修改
	int number11 = 30;
	shpwValue(number11);
	cout << number11 << endl;


	system("pause");
	return 0;
}