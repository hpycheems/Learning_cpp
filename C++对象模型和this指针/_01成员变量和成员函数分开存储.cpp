#include <iostream>
using namespace std;
#include<string>
// ��Ա���� �� ��Ա���� �ֿ��洢

class Person {
	int m_A; // �Ǿ�̬��Ա������ ������Ķ�����
	int m_C;
	static int m_B;//��̬��Ա������ �������������
	void func() {}//�Ǿ�̬��Ա������ �������������
	static void func1() {}//��̬��Ա�������������������
};

int Person::m_B = 100;

void test1_1() {
	Person p;
	//�ն���ռ���ڴ�ռ�Ϊ1
	//C++���������ÿ���ն���Ҳ����һ���ֽڿռ䣬Ϊ�����ֶ���ռ�ڴ��λ��
	//ÿ���ն���ҲӦ����һ����һ�޶����ڴ��ַ
	cout << "�ն�����ռ�õ��ڴ��С��" << sizeof(p) << endl;
}

void test1_2() {
	Person p;
	cout << "������ռ�õ��ڴ��С��" << sizeof(p) << endl;
}

int main1() {

	//test1_1();

	test1_1();

	system("pause");
	return 0;
}