#include <iostream>
using namespace std;

int main08() {

	int num1 = 10;
	int num2 = 20;
	int result = 0;
//算数运算符
	// +
	result = num1 + num2;
	cout << result << endl;

	// - 
	result = num1 - num2;
	cout << result << endl;

	// * 
	result = num1 * num2;
	cout << result << endl;

	// / 除数不能为0
	result = num1 / 3;//两个正数相除 结果是整数
	cout << result << endl;

	// ++ 自增
	cout << num1++ << endl;//先使用 再++
	cout << ++num1 << endl;//先++ 再使用
	// -- 自减
	cout << num1-- << endl;
	cout << --num1 << endl;

	// % 求余 基于除法 除数不能为0
	cout <<"取余10 % 3："<< 10 % 3 << endl;
	//基于除法 除数不能为0
	//num1 = num1 % 0;

	//小数不能取余数
	//num2 = 3.14 % 0.2f;
	
//赋值运算符
	int a = 10;

	// 赋值 =
	a = 100;
	cout << a << endl;

	// += 加等于
	a = 10;
	a += 2;
	cout << a << endl;

	// -=减等于
	a = 10;
	a -= 2;
	cout << a << endl;

	// *= 乘等于
	a = 10;
	a *= 2;
	cout << a << endl;

	// /= 除等于
	a = 10;
	a /= 2;
	cout << a << endl;

	// %= 余等于
	a = 10;
	a %= 3;
	cout << a << endl;

//比较运算符
	int b = 10;
	int c = 2;

	// 等于 ==
	cout << "10 = 2 :" << (b == c) << endl;
	//不等于 !=
	cout << "10 != 2 :" << (b != c) << endl;
	// 小于 <
	cout << "10 < 2 :" << (b < c) << endl;
	// 大于 >
	cout << "10 > 2 :" << (b > c) << endl;
	// 小于等于 <=
	cout << "10 <= 2 :" << (b <= c) << endl;
	// 大于等于 >=
	cout << "10 >= 2 :" << (b >= c) << endl;

//逻辑运算符

	bool b1 = true;
	bool b2 = false;
	// && 
	cout << "true逻辑与false：" << (b1 && b2) << endl;
	// ||
	cout << "true逻辑或false：" << (b1 || b2) << endl;
	// !
	cout << "false逻辑非：" << (!b1 ) << endl;
	cout << "false逻辑非：" << (!b2 ) << endl;

	system("pause");
	return 0;
}