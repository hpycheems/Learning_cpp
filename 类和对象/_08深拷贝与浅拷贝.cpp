#include <iostream>
using namespace std;
#include<string>

// �����ǳ����
// ǳ�������򵥵ĸ�ֵ���� (�������ṩ�Ŀ����������ǳ����)
// ������ڶ�����������ռ䣬���п��� (�Զ��忽�����죬�����ڶ��п��ٿռ�)
// ����������ڶ������ٵģ�һ��Ҫ�Լ��ṩ�������캯������ֹǳ��������������
class Person_2 {
public :
	int m_Age;
	int* m_Height;
	Person_2() {
		cout << "Person_2 ��Ĭ�Ϲ��캯��" << endl;
	}
	Person_2(int age) {
		m_Age = age;
		m_Height = new int(160);
		cout << "Person_2 ���вι��캯��" << endl;
	}

	//��ν��ǳ���� �Լ����忽������ ��ָ��ָ��ͬ�Ķѵ�ַ
	Person_2(const Person_2 & p) {
		m_Age = p.m_Age;
		//m_Height = p.m_Height;// ������Ĭ���ṩ�Ĵ���
		m_Height = new int(*p.m_Height);

		cout << "Person_2 ���п����캯��" << endl;
	}

	~Person_2() {
		//���������ٵ��������ͷŲ���
		if (m_Height != NULL) {
			delete m_Height;
			m_Height = NULL;
		}
		cout << "Person_2 ����������" << endl;
	}
};

void test_1() {
	Person_2 p1(18);
	Person_2 p2(p1);

	cout << "p1 �����䣺" << p1.m_Age << "p1 ����ߣ�" << *p1.m_Height << endl;
	cout << "p2 �����䣺" << p2.m_Age << "p2 ����ߣ�" << *p2.m_Height << endl;
}

int main8() {

	test_1();

	system("pause");
	return 0;
}