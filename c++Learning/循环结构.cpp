#include <iostream>
using namespace std;
#include <ctime>

int main10() {

//ѭ���ṹ
	//while()
	int n = 0;
	while (n < 10) {
		//cout << n << endl;
		n++;
	}

	//����
	//���������� ʹÿ�����������ͬ
	srand((unsigned int)time(NULL));
	int randoNum = rand() % 100 + 1;// ���� 0-99�������
	cout << randoNum << endl;
	int num = 0;
	while (false)
	{
		cin >> num;
		if (num > randoNum) {
			cout << "����" << endl;
		}
		else if(num < randoNum){
			cout << "С��" << endl;
		}
		else {
			cout << "����" << endl;
			break;
		}
	}

	// do while����
	int num1 = 0;
	do {
		cout << num << endl;
		num++;
	} while (num < 10);

	// ˮ�ɻ���
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

	//������
	for (int i = 1; i <= 100; i++) {
		if (i % 7 == 0 || i % 10 == 7 || i / 10 == 7) {
			cout << "������" << endl;
		}
		else {
			cout << i << endl;
		}
	}

//ѭ��Ƕ��
	//99�˷���
	for (int i = 1; i <= 9; i++) {
		for (int j = 1; j <= i; j++) {
			cout << j << "*" << i << "=" << i * j << "\t";
		}
		cout << endl;
	}

	system("pause");
	return 0;
}