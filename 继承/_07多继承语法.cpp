#include <iostream>
using namespace std;
#include <string>
// C++������һ����̳ж����
// �﷨�� class �������̳з�ʽ ����1���̳з�ʽ������2
// �������г���ͬ����Ա �����ֶ�����

class Base1 {
public :
	Base1() {
		m_A = 100;
	}

	int m_A;
};
class Base2 {
public:
	Base2() {
		m_A = 200;
	}

	int m_A;
};

class Son : public Base1, public Base2 {
public:

	Son() {
		m_C = 300;
		m_D = 400;
	}

	int m_C;
	int m_D;
};

void test7_1() {
	Son s;
	cout << "Base1 m_A = " << s.Base1::m_A << endl;
	cout << "Base2 m_A = " << s.Base2::m_A << endl;
}

int main7() {

	test7_1();
	system("pause");
	return 0;
}