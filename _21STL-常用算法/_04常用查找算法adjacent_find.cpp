#include <iostream>
using namespace std;
#include <vector>
#include <algorithm>

/*
adjacent_find：查找相邻重复元素
原型
adjacent_find(iterator beg, iterator end);
查找相邻重复元素，返回相邻元素的第一个位置的迭代器
adjacent_find
*/

void test4_1() {

	vector<int > v;

	v.push_back(0);
	v.push_back(0);
	v.push_back(1);
	v.push_back(3);
	v.push_back(0);
	v.push_back(3);
	//v.push_back(3);

	vector<int>::iterator it = adjacent_find(v.begin(), v.end());

	if (it != v.end()) {
		cout << "查找到重复相邻元素" << *it << endl;
	}
	else {
		cout << "未查找到重复相邻元素" << endl;
	}
}

int main() {
	test4_1();

	system("pause");
	return 0;
}