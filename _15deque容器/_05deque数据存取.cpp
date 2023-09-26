#include<iostream>
using namespace std;
#include <deque>

void test5_1() {
	deque<int > d;
	for (int i = 0; i < 5; i++)
	{
		d.push_back(i);
	}

	//通过【】访问
	for (int i = 0; i < d.size(); i++)
	{
		cout << d[i] << " ";
	}
	cout << endl;

	//通过at访问
	for (int i = 0; i < d.size(); i++)
	{
		cout << d.at(i) << " ";
	}
	cout << endl;

	cout << "第一个元素" << d.front() << endl;
	cout << "最后一个元素" << d.back() << endl;
}

int main5() {
	test5_1();
	system("pause");
	return 0;
}