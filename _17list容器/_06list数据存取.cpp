#include <iostream>
using namespace std;
#include <list>

/*
front(); ���ص�һ��Ԫ��
back(); �������һ��Ԫ��
*/


void test6_1() {

	list<int> l;
	l.push_back(10);
	l.push_back(20);
	l.push_back(30);
	//l[0] �������á�������list�����е�Ԫ��
	//l.at(0) ��������at��ʽ����list�����е�Ԫ��

	//ԭ����list��������ʽ�ṹ���������������Կռ�洢���ݣ�������Ҳ�ǲ�֧��������ʵ�

	cout << "��һ��Ԫ��:" << l.front() << endl;
	cout << "���һ��Ԫ��:" << l.back() << endl;

	list<int>::iterator it = l.begin();
	it++;//֧��˫��
	it--;

	// it = it + 1; ��֧���������
}

int main6() {
	test6_1();
	system("pause");
	return 0;
}