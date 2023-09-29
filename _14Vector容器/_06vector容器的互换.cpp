#include <iostream>
using namespace std;
#include <vector>
#include <algorithm>

//实现两个容器内元素进行互换
//swap(vec)

void printVector6(vector<int>& v) {
	for (vector<int>::iterator it = v.begin(); it != v.end(); it++)
	{
		cout << *it << " ";
	}
	cout << endl;
}

//基本用法 交换两个容器的数据
void test6_1() {
	vector<int> v1;
	for (int i = 0; i < 5; i++)
	{
		v1.push_back(i);
	}

	vector<int> v2;
	for (int i = 5; i < 10; i++)
	{
		v2.push_back(i);
	}

	cout << "交换前" << endl;
	cout << "v1:";
	printVector6(v1);
	cout << "v1:";
	printVector6(v2);

	cout << "交换后" << endl;
	v1.swap(v2);
	cout << "v1:";
	printVector6(v1);
	cout << "v1:";
	printVector6(v2);

}

//使用案例 收缩内存 如果一个容器开辟了很多的空间，但只使用了很小的一部分 则可收缩内存
void test6_2() {
	vector<int> v1;
	for (int i = 0; i < 10000; i++)
	{
		v1.push_back(i);
	}

	cout << "v1 的容量" << v1.capacity() << endl;
	cout << "v1 的大小" << v1.size() << endl;

	v1.resize(3);
	cout << "v1 的容量" << v1.capacity() << endl;
	cout << "v1 的大小" << v1.size() << endl;

	vector<int>(v1).swap(v1);//创建出来的临时对象会被系统自动回收
	cout << "v1 的容量" << v1.capacity() << endl;
	cout << "v1 的大小" << v1.size() << endl;

}

int main6() {

	test6_2();

	system("pause");
	return 0;
}