#include <iostream>
using namespace std;
#include<string>
class Person {
public :
	//this ָ��ı�����ָ�볣�� ָ���ָ�򲻿��޸ģ�ָ��ָ���ֵ���޸�
	//Person * const this;
	//�ڳ�Ա���������const�����ε���thisָ�룬��ָ��ָ���ֵ�����޸�
	void showPerson() const {
		//m_Age = 10;
		m_B = 20;
		//this = NULL;
	}

	void func() {}

	int m_Age;
	mutable int m_B;// �����������ʹ�ڳ������У�Ҳ���޸ģ����Ϲؼ���mutable
};
//������
// ��Ա�������const 
void test4_1() {
	Person p;
	p.showPerson();
}
//������
void test4_2() {
	const Person p;//�ڶ���ǰ��const ��Ϊ������
	//p.m_Age = 100;
	p.m_B = 100;//������Ϊ����ֵ���ڳ�������Ҳ�ɽ����޸�
	p.showPerson();
	//p.func();������ �����Ե�����ͨ��Ա����
}

int main4() {

	test4_1();
	system("pause");
	return 0;
}