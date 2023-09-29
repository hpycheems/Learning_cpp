#include <iostream>
using namespace std;
#include <vector>
#include <algorithm>

/*
find：查找指定元素，找到返回指定元素的迭代器，找不到返回结束迭代器end()
原型：
find(iterator beg, iterator end, elem)
*/

// 内建数据类型
void test2_1() {
	vector<int> v;

	for (int i = 0; i < 5; i++)
	{
		v.push_back(i);
	}

	vector<int>::iterator it = find(v.begin(), v.end(), 10);
	if (it != v.end()) {
		cout << "找到元素" << *it << endl;
	}
	else {
		cout << "未能找到元素" << endl;
	}

}

class Person {
public :

	Person(string name, int age) :m_Name(name),m_Age(age){}

	bool operator==(const Person & p) {
		if (this->m_Name == p.m_Name && this->m_Age == p.m_Age) {
			return true;
		}
		return false;
	}

	string m_Name;
	int m_Age;
};
//自定义数据类型
void test2_2() {
	vector<Person> v;

	Person p1("赵云", 25);
	Person p2("关羽", 39);
	Person p3("卧龙", 30);
	Person p4("凤雏", 40);

	v.push_back(p1);
	v.push_back(p2);
	v.push_back(p3);
	v.push_back(p4);

	vector<Person>::iterator it = find(v.begin(), v.end(), Person("卧龙", 30));
	if (it != v.end()) {
		cout << "查找到：" << it->m_Name << " " << it->m_Age << endl;
	}
	else {
		cout << "未能找到元素" << endl;
	}

}

int main2() {

	test2_2();
	system("pause");
	return 0;
}