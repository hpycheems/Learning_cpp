#include <iostream>
using namespace std;

// 1. ˳��ṹ
// 2. ѡ��ṹ
// 3. ѭ���ṹ
int main09() {

//ѡ��ṹ
	//����if���
	int score = 0;
	cout << "���������:" << endl;
	//cin >> score;
	if (score > 600) {
		//cout << "��������600" << endl;
	}

	// if else
	//cin >> score;
	if (score > 600) {
		//cout << "��������600" << endl;
	}
	else {
		//cout << "����С��600" << endl;
	}
	// if elseif else
	if (score > 600) {
		cout << "��������600" << endl;
	}
	else if (score > 500) {
		cout << "��������500" << endl;
	}
	else {
		cout << "����С��500" << endl;
	}

	//Ƕ��
	if (true) {
		if (false) {

		}
		else {

		}
	}

	//����
	int a, b, c;
	cout << "������A��������" << endl;
	cin >> a;
	cout << "������B��������" << endl;
	cin >> b;
	cout << "������C��������" << endl;
	cin >> c;

	if (a > b) {
		if (a > c) {// A ��

		}
		else {// C ��
			
		}
	}
	else {
		if (b > c) {// B ��

		}
		else {// C ��

		}
	}

// ��Ŀ�����
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