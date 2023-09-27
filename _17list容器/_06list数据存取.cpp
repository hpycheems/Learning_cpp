#include <iostream>
using namespace std;
#include <list>

/*
front(); 返回第一个元素
back(); 返回最后一个元素
*/


void test6_1() {

	list<int> l;
	l.push_back(10);
	l.push_back(20);
	l.push_back(30);
	//l[0] 不可以用【】访问list容器中的元素
	//l.at(0) 不可以用at方式访问list容器中的元素

	//原因是list本身是链式结构，不是用连续线性空间存储数据，迭代器也是不支持随机访问的

	cout << "第一个元素:" << l.front() << endl;
	cout << "最后一个元素:" << l.back() << endl;

	list<int>::iterator it = l.begin();
	it++;//支持双向
	it--;

	// it = it + 1; 不支持随机访问
}

int main6() {
	test6_1();
	system("pause");
	return 0;
}