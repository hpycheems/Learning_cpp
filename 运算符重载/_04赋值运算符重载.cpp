#include<iostream>
using namespace std;
#include<string>
//��ֵ���������
// C++���������ٸ�һ�������4������
// 1 Ĭ�Ϲ��캯��
// 2 Ĭ����������
// 3 Ĭ�Ͽ������캯��
// 4 ��ֵ�����operator=,�����Խ��п���

//������Ĭ���ṩ�ĸ�ֵ��������� ��һ��ǳ�����Ĳ���
//����������ǳ����

class Person {
public :
	Person(int age){
		m_Age = new int(age);
	}

	//���ڱ�����Ĭ���ṩ�ĸ�ֵ������� ǳ���� ������Ҫ�Լ�ʵ�����
	Person& operator =(Person &p) {
		//���ж��Ƿ��������ڶ�������������ͷŸɾ���Ȼ�������
		//if (m_Age != NULL) {
		//	delete m_Age;
		//	m_Age = NULL;
		//}
		//m_Age = new int(*p.m_Age);

		//��������������� ��ֵ������
		*this->m_Age = *p.m_Age;
		return *this;
	}


	~Person() {

		if (m_Age != NULL) {
			delete m_Age;
			m_Age = NULL;
		}

	}
	int* m_Age;
};


void test4_1() {
	Person p1(18);

	Person p2(20);

	Person p3(30);

	p3 = p2 = p1;

	cout << "P1 ������ ��" << *p1.m_Age << endl;

	cout << "P2 ������ ��" << *p2.m_Age << endl;

	cout << "P3 ������ ��" << *p3.m_Age << endl;
}

int main4() {

	test4_1();

	system("pause");
	return 0;
}