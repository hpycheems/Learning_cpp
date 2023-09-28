#include <iostream>
using namespace std;
#include <map>

/*
简介： 高效率 高性能
	map中所有元素都是pair
	pair中第一个元素为key（）键值，起到索引作用，第二个元素为value（实值）
	所有元素都会根据元素的键值自动排序
本质：
	map\multimap属于关联容器，底层结构是用二叉树实现
优点：
	可以根据key值快速找到value值
map和multimap区别：
	map不允许容器中有重复key值元素
	multimap允许容器中有重复key值元素
*/

/*
map构造和赋值：
	
*/

void test1_1() {

	//默认构造
	map<int, int> m;

	m.insert(pair<int, int>(1, 10));
	m.insert(pair<int, int>(3, 30));
	m.insert(pair<int, int>(2, 20));
	m.insert(pair<int, int>(4, 40));

	for (map<int,int>::iterator it = m.begin(); it != m.end(); it++)
	{
		cout << "key = " << it->first << " Value = " << (*it).second << endl;
	}
	cout << endl;

	//拷贝构造
	map<int, int> m2(m);
	for (map<int, int>::iterator it = m2.begin(); it != m2.end(); it++)
	{
		cout << "key = " << it->first << " Value = " << (*it).second << endl;
	}
	cout << endl;


	//赋值
	map<int, int> m3;
	m3 = m2;
	for (map<int, int>::iterator it = m3.begin(); it != m3.end(); it++)
	{
		cout << "key = " << it->first << " Value = " << (*it).second << endl;
	}
}

int main1() {

	test1_1();

	system("pause");
	return 0;
}