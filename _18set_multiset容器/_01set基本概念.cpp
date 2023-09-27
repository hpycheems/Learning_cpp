#include <iostream>
using namespace std;
#include <set>

//简介： 所有元素都会在插入时自动被排序
//本质：set/multiset属于关联式容器，底层结构是用二叉树实现

//set和multiset区别：
// set不允许容器中有重复的元素
// multiset允许容器中有重复的元素

//构造函数

void printSet1(const set<int>& s) {
	for (set<int>::const_iterator it = s.begin(); it !=s.end(); it++)
	{
		cout << *it << " ";
	}
	cout << endl;
}

void test1_1() {

	set<int> s;
	s.insert(10);
	s.insert(40);
	s.insert(30);
	s.insert(20);
	s.insert(30);

	printSet1(s);

	set<int> s1(s);
	printSet1(s1);

	set<int> s3;
	s3 = s1;
	printSet1(s3);
}

int main1() {
	test1_1();
	system("pause");
	return 0;
}