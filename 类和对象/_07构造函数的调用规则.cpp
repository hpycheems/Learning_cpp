#include <iostream>
using namespace std;
#include<string>

//���캯�����ù���
//Ĭ������£�c++���������ٸ�һ�������3������
// 1.Ĭ�Ϲ��캯�� (�޲Σ�������Ϊ��)
// 2.�޲ι��캯�� (�޲Σ�������Ϊ��)
// 3.Ĭ�Ͽ������캯���������Խ��п���

class Person_1 {
public :
	int m_Age;
	Person_1() {
		cout << "Person_1 ��Ĭ�Ϲ��캯��" << endl;
	}
	Person_1(int age) {
		m_Age = age;
		cout << "Person_1 ���вι��캯��" << endl;
	}
	Person_1(const Person_1& p) {
		m_Age = p.m_Age;
		cout << "Person_1 �Ŀ������캯��" << endl;
	}
	~Person_1() {
		cout << "Person_1 ����������" << endl;
	}
};

void func_1() {
	Person_1 p;
}
// ����û����� �вι��캯����c++�����ṩĬ���޲ι��캯�������ǻ��ṩĬ�Ͽ�������
// ����û����� �������캯����c++�������ṩ�������캯��
void func_2() {
	Person_1 p;
	Person_1 p2(20);
	Person_1 p1(p2);
}

int main7() {

	//func_1();

	func_2();


	system("pause");
	return 0;
}