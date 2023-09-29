#include <iostream>
using namespace std;
#include <set>

//区别
// set不可以插入重复数据，而multiset可以
// set插入数据的同时会返回插入结果，表示插入是否成功
// multiset不会检查数据，因此可以插入重复数据


void test5_1() {
	set<int> s;
	//返回队组 
	pair<set<int>::iterator, bool> res = s.insert(10);

	if (res.second) {
		cout << "第一次插入成功" << endl;
	}
	else {
		cout << "第一次插入不成功" << endl;
	}

	res = s.insert(10);
	if (res.second) {
		cout << "第二次插入成功" << endl;
	}
	else {
		cout << "第二次插入不成功" << endl;
	}

	multiset<int> ms;
	//允许插入重复元素
	ms.insert(10);
	//返回迭代器 指向插入的数据
	multiset<int> :: iterator res1 = ms.insert(10);
	cout << *res1 << endl;

	for (multiset<int>::iterator it = ms.begin(); it != ms.end(); it++)
	{
		cout << *it << " ";
	}cout << endl;
}

int main5() {
	test5_1();
	system("pause");
	return 0;
}