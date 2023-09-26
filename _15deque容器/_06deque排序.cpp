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

	//排序 默认序列规则 从小到大， 升序
	//对于支持随机访问的迭代器的容器，都可以利用sort算法直接对其进行排序
	//vector容器也可以利用 sort进行排序
	sort(d.begin(), d.end());

	printDeque6(d);
}

int main6() {
	test6_1();
	system("pause");
	return 0;
}