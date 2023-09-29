#include <iostream>
using namespace std;
#include <vector>
#include <algorithm>

/*

set_difference: 求两个集合的差集
原型：
	set_difference(iterator beg1, iterator end1, iterator beg2, iterator end2, iterator dest);
	两个集合必须是有序序列
	dest 目标容器开始迭代器
	*/

void test20_1() {

	vector<int> v1;
	vector<int> v2;
	for (int i = 0; i < 10; i++)
	{
		v2.push_back(i);
		v1.push_back(i + 5);
	}

	vector<int> vTarget;
	//开辟空间
	//特殊情况，两个集合都不存在交集 开辟空间最大的那个
	vTarget.resize(max(v1.size(), v2.size()));//56.08

	vector<int> ::iterator pos = set_difference(v1.begin(), v1.end(), v2.begin(), v2.end(), vTarget.begin());
	for (vector<int>::iterator it = vTarget.begin(); it != pos; it++)
	{
		cout << *it << " ";
	}
	cout << endl;
}

int main() {


	test20_1();
	system("pause");
	return 0;
}
