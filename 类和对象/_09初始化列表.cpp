#include <iostream>
using namespace std;
#include<string>

class Person_3 {
public :
	int m_A;
	int m_B;
	int m_C;
	//��ͳ��ʽ��ʼ��
	//Person_3(int a,int b,int c) {
	//	m_A = a;
	//	m_B = b;
	//	m_C = c;
	//}

	// ��ʼ���б�ʽ
	Person_3(int a, int b, int c) : m_A(a), m_B(b), m_C(c) {}
};

void test_2() {
	Person_3 p1(30,20,10);
	cout << p1.m_A << endl;
	cout << p1.m_B << endl;
	cout << p1.m_C << endl;
}

int main9() {

	test_2();

	system("pause");
	return 0;
}