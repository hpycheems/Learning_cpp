#include <iostream>
using namespace std;

// 1. 顺序结构
// 2. 选择结构
// 3. 循环结构
int main09() {

//选择结构
	//单行if语句
	int score = 0;
	cout << "请输入分数:" << endl;
	//cin >> score;
	if (score > 600) {
		//cout << "分数大于600" << endl;
	}

	// if else
	//cin >> score;
	if (score > 600) {
		//cout << "分数大于600" << endl;
	}
	else {
		//cout << "分数小于600" << endl;
	}
	// if elseif else
	if (score > 600) {
		cout << "分数大于600" << endl;
	}
	else if (score > 500) {
		cout << "分数大于500" << endl;
	}
	else {
		cout << "分数小于500" << endl;
	}

	//嵌套
	if (true) {
		if (false) {

		}
		else {

		}
	}

	//案例
	int a, b, c;
	cout << "请输入A的重量：" << endl;
	cin >> a;
	cout << "请输入B的重量：" << endl;
	cin >> b;
	cout << "请输入C的重量：" << endl;
	cin >> c;

	if (a > b) {
		if (a > c) {// A 重

		}
		else {// C 重
			
		}
	}
	else {
		if (b > c) {// B 重

		}
		else {// C 重

		}
	}

// 三目运算符
	int num1 = 0 , num2 = 0;
	int max = 0;
	num1 > num2 ? max = num1 : max = num2;

//switch
	int num = 0;
	switch (num)
	{
		case 0:
			cout <<"0" << endl;
			break;
		case 1:
			cout << "1" << endl;
			break;
		default:
			cout << "default" << endl;
			break;
	}


	system("pause");
	return 0;
}