#include <iostream>
using namespace std;
#include <vector>
#include <algorithm>
#include <functional>
#include <numeric>

/*
fill: 向容器中填充指定的元素
原型：
	fill(iterator beg, iterator end, value);
	value 填充值
*/

void test17_1() {

	vector<int> v;
	v.resize(10, 1);

	//后期重写填充容器
	fill(v.begin(), v.end(), 1000);
	for (vector<int>::iterator it = v.begin(); it != v.end(); it++)
	{
		cout << *it << " ";
	}
	cout << endl;
}

int main17() {
	test17_1();
	system("pause");
	return 0;
}