#include <iostream>
using namespace std;

//����������
int Sum(int arr[]);

//����
// ����ֵ���� ������ �����б�
int Funcion() {
	cout << "My First Function!" << endl;
	return 0;
}

void Swap(int num1, int num2) {
	int temp = num1;
	num1 = num2;
	num2 = temp;
}
		//�β�
int Add(int num1, int num2) {
	return num1 + num2;
}

//������ʽ
void Func1() {}
void Func4(int num1) {}
int Func2() {
	return 0;
}
int Func3(int num1) {
	return 0;
}

int main13() {

	//��������
	Funcion();

	// ʵ��
	int a = 10;
	int b = 20;
	
	cout << Add(a, b) << endl;


// ֵ���� �βθı䲻��Ӱ��ʵ��
	int num1 = 20;
	int num2 = 10;
	Swap(num1, num2);
	cout << "num1:" << num1 << endl;
	cout << "num2:" << num2 << endl;

// ���ô���



	system("pause");
	return 0;
}

//�����Ķ���
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