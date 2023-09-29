#include <iostream>
using namespace std;
#include <algorithm>
#include <vector>

/*
set_intersection: 求两个容器的交集
原型：
	set_intersection(interator beg1,iterator end1, interator beg2, iterator end2,iterator desc);
	注意：***两个集合必须是有序序列***
	dest 目标容器开始迭代器
*/


void test18_1() {

	vector<int> v;
	vector<int> v1;
	for (int i = 0; i < 10; i++)
	{
		v.push_back(i);
		v1.push_back(i + 5);
	}

	vector<int> vTarget;
	//vTarget 需要开辟空间
	// 开辟的空间大小为 两个容器中最小的那个
	vTarget.resize(min(v.size(), v1.size()));

	//需要合并后 返回的迭代器作为结束条件，不然会把目标容器全部打印出来
	vector<int>::iterator pos = set_intersection(v.begin(), v.end(), v1.begin(), v1.end(), vTarget.begin());
	for (vector<int>::iterator it = vTarget.begin(); it != pos; it++)
	{
		cout << *it << " ";
	}
	cout << endl;

}
int main18() {
	test18_1();
	system("pause");
	return 0;
}