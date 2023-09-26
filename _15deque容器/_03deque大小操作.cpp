#include<iostream>
using namespace std;
#include <deque>

void printDeque3(const deque<int>& d) {
	for (deque<int>::const_iterator it = d.begin(); it != d.end(); it++)
	{
		cout << *it << " ";
	}
	cout << endl;
}
void test3_1() {
	deque<int> d;
	for (int i = 0; i < 10; i++)
	{
		d.push_back(i);
	}
	printDeque3(d);

	if (d.empty()) {
		cout << "d 为空" << endl;
	}
	else {
		cout << "d 不为空" << endl;
		cout << "d 的大小" << d.size() << endl;
	}

	//d.resize(15);
	d.resize(15,1);
	printDeque3(d);

	d.resize(5);
	printDeque3(d);


}

int main3() {

	test3_1();

	system("pause");
	return 0;
}