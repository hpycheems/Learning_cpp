#include <iostream>
using namespace std;
#include <list>
#include <algorithm>

//�������е�Ԫ�ط�ת���Լ��������е����ݽ�������

/*
reverse() ��ת
sort() ����
*/
void printList7(list<int>& l) {
	for (list<int>::iterator it = l.begin(); it != l.end(); it++)
	{
		cout << *it << " ";
	}
	cout << endl;
}
bool myCompare(int val1, int val2) {
	return val1 > val2;

}
void test7_1() {

	list<int> l;
	l.push_back(20);
	l.push_back(10);
	l.push_back(30);
	l.push_back(50);
	l.push_back(40);
	cout << "��תǰ��" << endl;
	printList7(l);

	l.reverse();
	cout << "��ת��" << endl;
	printList7(l);

}

void test7_2() {
	list<int> l;
	l.push_back(20);
	l.push_back(10);
	l.push_back(30);
	l.push_back(50);
	l.push_back(40);
	cout << "����ǰ" << endl;
	// ���в�֧��������ʵ�����,�������ñ�׼�㷨
	// ��֧��������ʵ��������������ڲ����ṩ��ӦһЩ�㷨
	//sort(l.begin(), l.end());
	printList7(l);

	cout << "�����" << endl;
	l.sort(myCompare);//Ĭ�Ͻ������� �Լ��ṩ�ȽϺ��� ��������ʽ
	printList7(l);


}

int main7() {


	test7_2();
	system("pause");
	return 0;
}