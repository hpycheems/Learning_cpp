#include <iostream>
using namespace std;

//�������ģ�����ͨ���������Ե��ã����ȵ�����ͨ����
//����ͨ����ģ������б� ǿ�Ƶ��� ����ģ��
//����ģ����Է�����������
//�������ģ����Բ������õ�ƥ�䣬���ȵ��ú���ģ��

void myPrint(int a, int b)
{
	cout << "��ͨ�������ã�" << endl;
}

template<class T>
void myPrint(T a, T b) {
	cout << "ģ�庯�����ã�" << endl;
}

template<class T>
void myPrint(T a, T b,T c) {
	cout << "ģ�����غ������ã�" << endl;
}

void test5_1() {
	int a = 10;
	int b = 20;
	//myPrint(a, b);//�������ģ�����ͨ���������Ե��ã����ȵ�����ͨ����

	//myPrint<>(a, b);//����ͨ����ģ������б� ǿ�Ƶ��� ����ģ��

	//myPrint(a, b, 100);//����ģ����Է�����������

	char c = 'c';
	char d = 'd';
	myPrint(c, d);///�������ģ����Բ������õ�ƥ�䣬���ȵ��ú���ģ��
}

int main5() {

	test5_1();
	system("pause");
	return 0;
}