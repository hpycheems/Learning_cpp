#include <iostream>
using namespace std;
#include <ctime>

int main10() {

//循环结构
	//while()
	int n = 0;
	while (n < 10) {
		//cout << n << endl;
		n++;
	}

	//案例
	//添加随机种子 使每次随机的数不同
	srand((unsigned int)time(NULL));
	int randoNum = rand() % 100 + 1;// 生成 0-99的随机数
	cout << randoNum << endl;
	int num = 0;
	while (false)
	{
		cin >> num;
		if (num > randoNum) {
			cout << "大了" << endl;
		}
		else if(num < randoNum){
			cout << "小了" << endl;
		}
		else {
			cout << "对了" << endl;
			break;
		}
	}

	// do while（）
	int num1 = 0;
	do {
		cout << num << endl;
		num++;
	} while (num < 10);

	// 水仙花数
	int num2 = 100;
	do {
		int x = num2 % 10;
		int y = (num2 / 10) % 10;
		int z = num2 / 100;
		int sum = x * x * x + y * y * y + z * z * z;
		if (sum == num2)
		{
			cout << sum << endl;
		}
		num2++;
	} while (num2 < 1000);

	// for
	for (int i = 0; i < 10; i++) {
		cout << i << endl;
	}

	//敲桌子
	for (int i = 1; i <= 100; i++) {
		if (i % 7 == 0 || i % 10 == 7 || i / 10 == 7) {
			cout << "敲桌子" << endl;
		}
		else {
			cout << i << endl;
		}
	}

//循环嵌套
	//99乘法表
	for (int i = 1; i <= 9; i++) {
		for (int j = 1; j <= i; j++) {
			cout << j << "*" << i << "=" << i * j << "\t";
		}
		cout << endl;
	}

	system("pause");
	return 0;
}