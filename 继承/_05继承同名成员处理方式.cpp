#include <iostream>
using namespace std;
#include <string>
//�̳���ͬ����Ա����ʽ
// ���ͨ�����������ʵ�������ͬ������ ��Ҫ Base::ͬ������

class Base1 {
public :
	Base1() {
		m_A = 100;
	}

	void func() {
		cout << "base func()��������" << endl;
	}

	void func(int a){
		cout << "base func(int a)��������" << endl;
	}

	int m_A;
};

class Son :public Base1 {
public :
	Son() {
		m_A = 200;
	}
	void func() {
		cout << "son func()��������" << endl;
	}

	int m_A;
};

void test5_1() {
	Son s;
	// ���������д���ͬ������ʱ���������ֱ��ʹ��ͬ�����ԣ����ص��������е�����
	cout << "m_A = " << s.m_A << endl;
	// �����������Ҫ���ʸ�������ͬ������ʱ����Ҫ���ϸ���������
	cout << "m_A = " << s.Base1::m_A << endl;
}

void test5_2() {
	Son s;
	// ���������д���ͬ������ʱ���������ֱ����ͬ�����������õ�����������ĺ���
	s.func();
	//�����������Ҫ���ø�������ͬ������ʱ����Ҫ���ϸ���������
	s.Base1::func();

	// �������д���ͬ�븸��ͬ���ĺ���ʱ������ĺ������ᱻ���أ�ֻ��ͨ�����������������
	s.Base1::func(100);
}

int main5() {

	//test5_1();

	test5_2();

	system("pause");
	return 0;
}