#include <iostream>
using namespace std;

//标识符命名规则
//1.不能是关键字
//2.由字母、数字、下划线
//3.第一个字符只能是字母或下划线
//4.区分大小写
int main06() {

	int abc = 1;
	
	int _abc = 2;

	//int 12ac = 20;

	int A = 30;
	int a = 40;
	// 见名知意
	int num1 = 10;
	int num2 = 20;
	int sum = num1 + num2;
	cout << sum << endl;

	system("pause");
	return 0;
}