#include <iostream>
using namespace std;
#include <vector>
#include <algorithm>

/*
set_union: 求两个集合的并集
原型：
	set_union(iterator beg1, iterator end1, iterator beg2, iterator end2, iterator dest);
	注意：两个集合必须是有序序列
	dest：目标容器开始迭代器
*/


void test19_1() {
	vector<int> v;
	vector<int> v1;
	for (int i = 0; i < 10; i++)
	{
		v.push_back(i);
		v1.push_back(i + 5);
	}

	vector<int> vTarget;
	//开辟 空间 ，特殊情况： 两个容器都没有 相同的元素
	vTarget.resize(v.size() + v1.size());

	vector<int>::iterator pos = 
		set_union(v.begin(), v.end(), v1.begin(), v1.end(), vTarget.begin());
	for (vector<int>::iterator it = vTarget.begin(); it != pos; it++)
	{
		cout << *it << " ";
	}
	cout << endl;

}

int main19() {

	test19_1();

	system("pause");
	return 0;
}