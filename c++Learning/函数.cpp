#include <iostream>
using namespace std;

//函数的声明
int Sum(int arr[]);

//函数
// 返回值类型 函数名 参数列表
int Funcion() {
	cout << "My First Function!" << endl;
	return 0;
}

void Swap(int num1, int num2) {
	int temp = num1;
	num1 = num2;
	num2 = temp;
}
		//形参
int Add(int num1, int num2) {
	return num1 + num2;
}

//常见样式
void Func1() {}
void Func4(int num1) {}
int Func2() {
	return 0;
}
int Func3(int num1) {
	return 0;
}

int main13() {

	//函数调用
	Funcion();

	// 实参
	int a = 10;
	int b = 20;
	
	cout << Add(a, b) << endl;


// 值传递 形参改变不会影响实参
	int num1 = 20;
	int num2 = 10;
	Swap(num1, num2);
	cout << "num1:" << num1 << endl;
	cout << "num2:" << num2 << endl;

// 引用传递



	system("pause");
	return 0;
}

//函数的定义
int Sum(int arr[])
{
	int sum = 0;
	int length = sizeof(arr) / sizeof(arr[0]);
	for (size_t i = 0; i < length; i++)
	{
		sum += arr[i];
	}
	return sum;
}