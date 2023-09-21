#include <iostream>
#define MAX 10 //定义宏常量
using namespace std;

int main04() {

	const int numa = 20;//定义普通常量

	cout << "a = " << numa << endl;
	cout <<  MAX << endl;

	//numa = 10;//常量只能在定义时赋值
	//MAX = 20；

	system("pause");
	return 0;
}