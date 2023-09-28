#include<iostream>
using namespace std;
#include <vector>
#include <algorithm>
#include <functional>

/*
概念：
 STL内建了一些函数对象
分类：
	算数仿函数
	关系仿函数
	逻辑仿函数
用法：
	这些仿函数所产生的对象，用法和一般函数完全相同
	使用内建函数对象，需要引入头文件#include <functional>
*/

/*
算数仿函数：
 实现四则运算
 negate 一元仿函数 取反

 plus 二元仿函数 加法
 minus 减法
 multiplies 乘法
 divides 除法
 modulus 取模

关系仿函数：
	equal_to 等于
	not_equal_to 不等于
	greater 大于
	greater_equal 大于等于
	less 小于
	less_equal 小于等于

逻辑仿函数：
	logical_ont 非
	logical_or 或
	logical_and 与
*/
//negate 取反
void test3_1() {
	negate<int> n;
	cout << n(50) << endl;
}
//plus
void test3_2() {
	plus<int> p;
	cout << p(10, 20) << endl;
}

//关系仿函数
void test3_3() {
	vector<int> v;
	v.push_back(20);
	v.push_back(30);
	v.push_back(10);
	v.push_back(40);

	sort(v.begin(), v.end(), greater<int>());
	for (vector<int>::iterator it = v.begin(); it != v.end(); it++)
	{
		cout << *it << " ";
	}
	cout << endl;
}

//逻辑仿函数
void test3_4() {
	vector<bool> v;
	v.push_back(true);
	v.push_back(false);
	v.push_back(true);
	v.push_back(false);

	for (vector<bool>::iterator it = v.begin(); it != v.end(); it++)
	{
		cout << *it << " ";
	}
	cout << endl;

	vector<bool > v2;
	v2.resize(v.size());
	transform(v.begin(), v.end(), v2.begin(), logical_not<bool>());
	for (vector<bool>::iterator it = v2.begin(); it != v2.end(); it++)
	{
		cout << *it << " ";
	}
	cout << endl;
}

int main() {
	test3_1();
	test3_2();
	test3_3();
	test3_4();
	system("pause");
	return 0;
}