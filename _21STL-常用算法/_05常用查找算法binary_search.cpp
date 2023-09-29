#include <iostream>
using namespace std;
#include <vector>
#include <algorithm>

/*
binary_search : 查找指定元素是否存在
原型：
	bool binary_search(iterator beg, iterator end, value)
	查到返回 true， 否则返回false
	主要：查找的序列要是有序的 否则 结果会出错
*/

void test5_1() {
	vector<int >v;
	for (int i = 0; i < 10; i++)
	{
		v.push_back(i);
	}
	v.push_back(2);
	bool ret = binary_search(v.begin(), v.end(), 9);
	if (ret) {
		cout << "查找到了" << endl;
	}
	else {
		cout << "未查找到" << endl;
	}
}

int main5() {
	test5_1();
	system("pause");
	return 0;
}