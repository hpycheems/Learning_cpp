#include <iostream>
using namespace std;
#include<string>
//��̬��Ա
// �ڳ�Ա�����ͳ�Ա����ǰ���Ϲؼ���static����Ϊ��̬��Ա
// ��̬��Ա����
// ��̬��Ա����

class Person_3 {
public:
	//��̬��Ա����
	//1 ���ж�����ͬһ������
	//2 ����׶ξͷ����ڴ�
	//3 ���������������ʼ������
	static int m_A;

	//��̬��Ա����
	// ���ж�����ͬһ������
	// ��̬��Ա����ֻ�ܷ��ʾ�̬��Ա����
	static void func() {
		m_B = 300;//��̬��Ա�������Է��ʾ�̬��Ա����
		cout << "func ��̬��Ա��������" << endl;
	}
private:
	//��̬��Ա����Ҳ�з���Ȩ��
	static int m_B;
	//��̬��Ա����Ҳ�з���Ȩ��
	void func1() {
		cout << "func1 ��̬��Ա��������" << endl;
	}
};

int Person_3::m_A = 100;// �����ʼ������
int Person_3::m_B = 200;

void test_4() {
	//Person_3 p;
	//cout << p.m_A << endl;

	//��̬��Ա�ķ��ʷ�ʽ 2��
	// �������
	Person_3 p1;
	cout << p1.m_A << endl;
	p1.func();

	// ��������
	cout << Person_3::m_A << endl;
	Person_3::func();

	// ������ʲ���˽�еĳ�Ա����
	//cout << Person_3::m_B << endl;
	//Person_3::func1();
}

int main11() {
	//Person_3::m_A = 99;
	test_4();
	system("pause");
	return 0;
}