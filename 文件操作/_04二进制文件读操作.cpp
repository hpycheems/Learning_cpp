#include <iostream>
using namespace std;
#include <fstream>

class Person {
public:

	char m_Name[64];
	int m_Age;
};

//�ļ����������󣬿���ͨ��read�������Զ����Ʒ�ʽ��ȡ����

void test4_1() {
	//����ͷ�ļ�
	//��������������
	ifstream ifs("person.txt", ios::in | ios::binary);
	if (!ifs.is_open()) {
		cout << "�ļ���ʧ��" << endl;
	}

	//������
	Person p;
	ifs.read((char*)&p, sizeof(Person));
	cout << "���� :" << p.m_Name << "����" << p.m_Age << endl;

}

int main() {
	test4_1();
	system("pause");
	return 0;
}