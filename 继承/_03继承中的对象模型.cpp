#include <iostream>
using namespace std;
#include <string>
//�Ӹ���̳й����ĳ�Ա����Щ������������У�
// ���������еķǾ�̬��Ա���Զ��ᱻ����̳���ȥ
// ������˽�г�Ա���� �Ǳ��������������ˣ� ��˷��ʲ���������ȷʵ���̳���ȥ��

// ���ÿ�����Ա������ʾ����(Developer Command Prompt for vs)�鿴����ģ��
// �鿴����
// cl /d1 reportSingleClassLayout���� �ļ���

class Base {
public :
	int m_A;
protected:
	int m_B;
private :
	int m_C;
};

class Sum :public Base {
	int m_D;
};

void test3_1() {

	cout << "size of =" << sizeof(Sum) << endl;
}

int main3() {
	test3_1();
	system("pause");
	return 0;
}