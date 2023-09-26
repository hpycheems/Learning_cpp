#include <iostream>
using namespace std;
#include <vector>
#include <algorithm>

//单端数组 在数组的尾端进行插入删除
//数组是静态空间，vector可以动态扩展

//动态扩展
//不是在原空间之后连续接新空间，而是找更大的空间，然后拷贝数据到新空间，然后释放久空间

//vector容器的迭代器是支持随机访问的迭代器


//vector的构造
/*
vector<T> v;
vector(v.begin(), v.end());
vector(n,elem); //构造函数将n个elem拷贝给本身
vector(const vector &vec);
*/

void printVector(vector<int>& v) {
	for (vector<int>::iterator it= v.begin() ; it != v.end(); it++)
	{
		cout << *it << " ";
	}
	cout << endl;
}

void test1_1() {
	vector<int> v1;
	for (size_t i = 0; i < 10; i++)
	{
		v1.push_back(i);
	}
	printVector(v1);

	vector<int>v2(v1.begin(), v1.end());
	printVector(v2);

	vector<int>v3(10, 100);
	printVector(v3);

	vector<int> v4(v3);
	printVector(v4);
}

int main1() {

	test1_1();

	system("pause");
	return 0;
}