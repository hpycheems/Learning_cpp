#include <iostream>
using namespace std;


//6void swap01(int a, int b) {
//	int temp = a;
//	a = b;
//	b = temp;
//}

void swap02(int* num1, int* num2) {
	int temp = *num1;
	*num1 = *num2;
	*num2 = temp;
}

void swap03(int &num1, int &num2) {
	int temp = num1;
	num1 = num2;
	num2 = temp;
}


int& test01() {
	int a = 10;
	return a;
}

int& test02() {
	static int a = 10;//��̬���� ������ȫ����
	return a;
}

void shpwValue(const int &val){
	cout << val << endl;
}


// ����
// �����������
// �﷨�� �������� &���� = ԭ��

int main2() {

// �����÷�
	int a = 10;
	int c = 20;
	int& numbera = a;

	cout << numbera << endl;

// ע������
	// ���ñ���Ҫ��ʼ��
	// ��ʼ���󲻿��޸�
	// int& b;//����Ҫ��ʼ��
	numbera = c;//��ֵ���� ���Ǹ������� ���Ǹ���������ָ�������
	cout << a << endl;
	cout << numbera << endl;
	cout << c << endl;

//��������������
	//��������ʱ�������������ü������β�����ʵ��
	// �ŵ㣺���Լ�ָ���޸�
	cout << "++++++++++" << endl;
	int num1 = 10;
	int num2 = 20;

	//swap01(num1, num2);
	//cout << num1 << endl;
	//cout << num2 << endl;
	cout << "++++++++++" << endl;
	swap02(&num1, &num2);
	cout << num1 << endl;
	cout << num2 << endl;

	cout << "++++++++++" << endl;
	int num3 = 10;
	int num4 = 20;
	swap03(num3, num4);
	cout << num3 << endl;
	cout << num4 << endl;

// �����������ķ���ֵ
	// ��Ҫ���ؾֲ����������� ��Ϊ�ֲ������ڴ���ں���ִ����Ϻ󱻻���
	cout << "==========================" << endl;
	int& ref = test01();
	cout << ref << endl;
	cout << ref << endl;

	// �����ĵ��ÿ�����Ϊ��ֵ
	int& ref2 = test02();
	cout << ref2 << endl;
	cout << ref2 << endl;
	test02() = 100;
	cout << ref2 << endl;
	cout << ref2 << endl;

// ���õı��� �ڲ�ʵ����һ��ָ�볣��
	cout << "==========================" << endl;
	int number = 20;

	//�Զ�ת���� int * const ref = &a��ָ�볣��ָ��ָ�򲻿��޸ģ�Ҳ˵��Ϊʲô���ò��ɸ���
	int& numberRef = number;
	numberRef = 30;//�ڲ�����numberRef�����ã��Զ�ת��Ϊ��*numberRef = 20

	cout << number << endl;
	cout << numberRef << endl;

// �������� �����β� ��ֹ�����
	cout << "==========================" << endl;
	// �������������޸� int temp =10��const int & ref = temp
	const int& ref11 = 10;
	//ref11 = 20;//����const ֮�󲻿��޸�
	int number11 = 30;
	shpwValue(number11);
	cout << number11 << endl;


	system("pause");
	return 0;
}