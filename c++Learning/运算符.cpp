#include <iostream>
using namespace std;

int main08() {

	int num1 = 10;
	int num2 = 20;
	int result = 0;
//���������
	// +
	result = num1 + num2;
	cout << result << endl;

	// - 
	result = num1 - num2;
	cout << result << endl;

	// * 
	result = num1 * num2;
	cout << result << endl;

	// / ��������Ϊ0
	result = num1 / 3;//����������� ���������
	cout << result << endl;

	// ++ ����
	cout << num1++ << endl;//��ʹ�� ��++
	cout << ++num1 << endl;//��++ ��ʹ��
	// -- �Լ�
	cout << num1-- << endl;
	cout << --num1 << endl;

	// % ���� ���ڳ��� ��������Ϊ0
	cout <<"ȡ��10 % 3��"<< 10 % 3 << endl;
	//���ڳ��� ��������Ϊ0
	//num1 = num1 % 0;

	//С������ȡ����
	//num2 = 3.14 % 0.2f;
	
//��ֵ�����
	int a = 10;

	// ��ֵ =
	a = 100;
	cout << a << endl;

	// += �ӵ���
	a = 10;
	a += 2;
	cout << a << endl;

	// -=������
	a = 10;
	a -= 2;
	cout << a << endl;

	// *= �˵���
	a = 10;
	a *= 2;
	cout << a << endl;

	// /= ������
	a = 10;
	a /= 2;
	cout << a << endl;

	// %= �����
	a = 10;
	a %= 3;
	cout << a << endl;

//�Ƚ������
	int b = 10;
	int c = 2;

	// ���� ==
	cout << "10 = 2 :" << (b == c) << endl;
	//������ !=
	cout << "10 != 2 :" << (b != c) << endl;
	// С�� <
	cout << "10 < 2 :" << (b < c) << endl;
	// ���� >
	cout << "10 > 2 :" << (b > c) << endl;
	// С�ڵ��� <=
	cout << "10 <= 2 :" << (b <= c) << endl;
	// ���ڵ��� >=
	cout << "10 >= 2 :" << (b >= c) << endl;

//�߼������

	bool b1 = true;
	bool b2 = false;
	// && 
	cout << "true�߼���false��" << (b1 && b2) << endl;
	// ||
	cout << "true�߼���false��" << (b1 || b2) << endl;
	// !
	cout << "false�߼��ǣ�" << (!b1 ) << endl;
	cout << "false�߼��ǣ�" << (!b2 ) << endl;

	system("pause");
	return 0;
}