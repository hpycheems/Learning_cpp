#include <iostream>
using namespace std;
#include <fstream>
//�Զ����Ƶķ�ʽ���ļ����ж�д����
// �򿪷�ʽҪָ��Ϊ ios::binary

//д�ļ�
// �����Ʒ�ʽд�ļ���Ҫ������������ó�Ա����write
// ����ԭ�ͣ�ostream& write(const char * buffer, int len);
// �������ͣ��ַ�ָ��buffָ���ڴ���һ�δ洢�ռ䡣len�Ƕ�д���ֽ���

class Person {
public :

	char m_Name[64];
	int m_Age;
};

void test3_1() {
	Person person = {"����", 19};
	//����ͷ�ļ�
	//���������ļ�
	// ���ļ�
	ofstream ofs("person.txt", ios::out | ios::binary);

	//д����

	ofs.write((const char*)&person, sizeof(person));

	//�ر��ļ�
	ofs.close();

}

int main3() {

	test3_1();

	system("pause");
	return 0;
}