#include<iostream>
using namespace std;
#include <vector>
#include <algorithm>

void func1_1(int val) {
	cout << val << endl;
}

int main1() {
	//创建一个vector容器，数组
	vector<int> v;

	//向容器中插入数据
	v.push_back(10);
	v.push_back(20);
	v.push_back(30);
	v.push_back(40);

	//vector<int>::iterator vBegin = v.begin();//返回迭代器 这个迭代器指向容器的第一个元素
	//vector<int>::iterator vEnd = v.end();//返回迭代器 这个迭代器指向容器的最后一个元素的下一个位置
	//vector<int>::iterator 拿到vector<int>这种类型的迭代器
	
	//第一种遍历方法
	//while (vBegin != vEnd) {
	//	cout << *vBegin << endl;
	//	vBegin++;
	//}

	//第二种遍历方法
	for (vector<int>::iterator it = v.begin(); it != v.end(); it++)
	{
		cout << *it << endl;
	}

	//第三种变量方式
	for_each(v.begin(), v.end(), func1_1);

	system("pause");
	return 0;
}