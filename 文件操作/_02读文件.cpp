#include <iostream>
using namespace std;
#include <fstream>
#include <string>

//����is_open���������ж��ļ��Ƿ�򿪳ɹ�

void test2_1() {

	// ����ͷ�ļ�

	// ��������������
	ifstream ifs;

	// ���ļ�
	ifs.open("test.txt", ios::in);
	if (!ifs.is_open()) {
		cout << "�ļ���ʧ��" << endl;
		return;
	}

	// ������
	// ��ʽ1
	//char buf[1024] = { 0 };
	//while (ifs >> buf) {
	//	cout << buf << endl;
	//}

	//��ʽ2
	//char buf[1024] = { 0 };
	//while (ifs.getline(buf, sizeof(buf))) {
	//	cout << buf << endl;
	//}

	//��ʽ3
	string str;
	while (getline(ifs, str))
	{
		cout << str << endl;
	}
	
	//��ʽ4 ��ʹ��
	//char c;
	//while ((c = ifs.get()) != EOF) {
	//	cout << c << endl;
	//}
	
	// �ر��ļ�
	ifs.close();
}

int main2() {
	test2_1();
	system("pause");
	return 0;
}