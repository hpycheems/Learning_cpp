#include<iostream>
using namespace std;
#include<string>
//������������� �����������

class Person {
	friend ostream& operator<<(ostream& cout, Person& p);
public :
	Person(int a, int b) {
		m_A = a;
		m_B = b;
	}
	//���ó�Ա�������� ��������� p.operator<<(cout) �򻯰� p << cout
	//�������ó�Ա�������� << ���������Ϊ�޷�ʵ�� cout �����
	//void operator<<(cout) {
	//
	//}

private :
	int m_A;
	int m_B;
};
// ȫ�ֺ����������� << ���������
ostream& operator<<(ostream & cout, Person &p) {
	cout << "m_A = " << p.m_A << " m_B = " << p.m_B;
	return cout;
}

void test2_1() {
	Person p(10, 10);


	cout << p << endl;
}

int main2() {
	test2_1();
	system("pause");
	return 0;
}