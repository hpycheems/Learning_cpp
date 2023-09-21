#include <iostream>
using namespace std;

//1.break
//2.continue
//3.goto
int main11() {

//barak
	int num = 0;
	switch (num)
	{
	case 0:
		cout << "0" << endl;
		break;
	case 1:
		cout << "1" << endl;
		break;
	default:
		cout << "default" << endl;
		break;
	}

// continu
	for (int i = 0; i < 10; i++) {
		if (i % 2 == 0) {
			continue;
		}
		cout << i << endl;
	}

// goto

	
	cout << "1.xxx" << endl;

	cout << "2.xxx" << endl;

	goto ME;

	cout << "3.xxx" << endl;

	cout << "4.xxx" << endl;

ME:

	cout << "5.xxx" << endl;

	system("pause");
	return 0;
}