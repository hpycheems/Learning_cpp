#include <iostream>
using namespace std;
#include <string>

// �̳���ͬ���ľ�̬��Ա�������������ν��з��ʣ�

//��̬��Ա�ͷǾ�̬��Ա����ʽ��һ����

class Base1 {
public :

	static void func() {
		cout << "base static void func()" << endl;
	}
	static void func(int a) {
		cout << "base static void func(int a)" << endl;
	}

	static int m_A;
};
int Base1::m_A = 100;

class Son :public Base1{
public :
	static void func() {
		cout << "Son static void func()" << endl;
	}

	static int m_A;

};
int Son::m_A = 200;

void test6_1() {
	Son s;
	cout << "������÷�ʽ��" << endl;
	cout << "son �� m_A = " << s.m_A << endl;
	cout << "base �� m_A = " << s.Base1::m_A << endl;
	
	cout << "�������÷�ʽ" << endl;
	cout << "son �� m_A = " << Son::m_A << endl;
	//��һ��:: ����ͬ������ʽ���ʣ� �ڶ���::������ʸ�����������
	cout << "base �� m_A = " << Son::Base1::m_A << endl;
}

void test6_2() {
	Son s;
	cout << "������÷�ʽ" << endl;
	s.func();
	s.Base1::func();

	cout << "�������÷�ʽ" << endl;
	Son::func();
	Son::Base1::func();

	Son::Base1::func(100);
}

int main6() {

	//test6_1();
	test6_2();
	system("pause");
	return 0;
}