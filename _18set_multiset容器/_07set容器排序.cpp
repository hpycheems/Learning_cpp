#include <iostream>
using namespace std;
#include <set>
#include <algorithm>

/*
set容器默认排序规则为从小到大，掌握如何改变排序规则

主要技术点：
利用仿函数，可以改变排序规则
*/

//仿函数
class MyCompare1 {
public:
	bool operator()(int val1, int val2) const {
		return val1 > val2;
	}
};
//普通函数
bool compareTest(const int val1, const int val2) {
	return val1 > val2;
}

void test7_1() {

	//在构造是传入 要实现的排序方式
	set<int, MyCompare1> s;

	s.insert(20);
	s.insert(10);
	s.insert(40);
	s.insert(30);
	s.insert(50);

	//这种方式也是不行的
	//sort(s.begin(), s.end(), compareTest);


	for (set<int>::iterator it = s.begin(); it != s.end(); it++)
	{
		cout << *it << " ";
	}
	cout << endl;
}

//自定义的数据类型都会指定排序规则

class Person {
public:
	Person(string name, int age) :m_Name(name), m_Age(age){}

	string m_Name;
	int m_Age;
};
class comparePerson {
public:
	bool operator()(const Person& p1, const Person &p2) const {
		return p1.m_Age > p2.m_Age;
	}
};

//自定义类型 排序
void test7_2() {
	set<Person, comparePerson> s;

	Person p1("卧龙", 25);
	Person p2("凤雏", 30);
	Person p3("赵云", 21);
	Person p4("关羽", 28);

	s.insert(p1);
	s.insert(p2);
	s.insert(p3);
	s.insert(p4);

	for (set<Person, comparePerson>::iterator it = s.begin(); it != s.end(); it++)
	{
		cout << it->m_Name << " " << it->m_Age << endl;
	}
}

int main() {

	test7_2();

	system("pause");
	return 0;
}