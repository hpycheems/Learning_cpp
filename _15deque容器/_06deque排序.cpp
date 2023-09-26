#include<iostream>
using namespace std;
#include <deque>
#include <algorithm>


void printDeque6(const deque<int>& d) {
	for (deque<int>::const_iterator it = d.begin(); it != d.end(); it++)
	{
		cout << *it << " ";
	}
	cout << endl;
}

void test6_1() {
	deque<int> d;
	d.push_front(10);
	d.push_front(20);
	d.push_front(30);
	d.push_front(100);
	d.push_front(200);
	d.push_front(300);

	printDeque6(d);

	//���� Ĭ�����й��� ��С���� ����
	//����֧��������ʵĵ�����������������������sort�㷨ֱ�Ӷ����������
	//vector����Ҳ�������� sort��������
	sort(d.begin(), d.end());

	printDeque6(d);
}

int main6() {
	test6_1();
	system("pause");
	return 0;
}