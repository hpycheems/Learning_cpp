#include <iostream>
using namespace std;
#include <vector>
#include <algorithm>
#include <functional>
#include <numeric>

/*
accumulate: 计算区间内 容器元素累计总和
原型：
	accumulate(iterator beg, iterator end, value)
	value 起始值
*/

void test16_1() {

	vector<int> v;
	for (int i = 1; i <= 100; i++)
	{
		v.push_back(i);
	}

	//参数3 起始累加值
 	int sum = accumulate(v.begin(), v.end(), 1);
	cout << "从1加到100为" << sum << endl;
}
int main16() {

	test16_1();
	system("pause");
	return 0;
}