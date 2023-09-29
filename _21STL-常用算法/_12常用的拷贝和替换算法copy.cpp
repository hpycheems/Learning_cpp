#include <iostream>
using namespace std;
#include <vector>
#include <algorithm>
#include <functional>

/*
copy: 将容器内指定范围的元素拷贝到另一个容器中
原型：
	copy(iterator beg, iterator end, iterator dest);
	dest 目标起始迭代器
*/
void printFunc4(int val) {
	cout << val << " ";
}
void test12_1() {

	vector<int> v1;
	for (int i = 0; i < 5; i++)
	{
		v1.push_back(i);
	}

	vector<int> v2;
	v2.resize(v1.size());//提前给目标容器开辟空间
	copy(v1.begin(), v1.end(), v2.begin());
	for_each(v2.begin(), v2.end(), printFunc4);
}


int main12() {
	
	test12_1();

	system("pause");
	return 0;
}