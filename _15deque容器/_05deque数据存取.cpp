#include<iostream>
using namespace std;
#include <deque>

void test5_1() {
	deque<int > d;
	for (int i = 0; i < 5; i++)
	{
		d.push_back(i);
	}

	//ͨ����������
	for (int i = 0; i < d.size(); i++)
	{
		cout << d[i] << " ";
	}
	cout << endl;

	//ͨ��at����
	for (int i = 0; i < d.size(); i++)
	{
		cout << d.at(i) << " ";
	}
	cout << endl;

	cout << "��һ��Ԫ��" << d.front() << endl;
	cout << "���һ��Ԫ��" << d.back() << endl;
}

int main5() {
	test5_1();
	system("pause");
	return 0;
}