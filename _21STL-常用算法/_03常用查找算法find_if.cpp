#include <iostream>
using namespace std;
#include <vector>
#include <algorithm>

/*
find_if: 按条件查找元素
原型：
find_if(iterator beg, iterator end,_Pred);
_Pred 谓词(1元谓词，2元谓词)
找到返回指定位置迭代器，找不到返回结束迭代器
*/

class GreateFive {
public :
	bool operator()(int val) {
		return val > 3;
	}
};
//内置数据类型
void test3_1() {
	vector<int> v;

	for (int i = 0; i < 5; i++)
	{
		v.push_back(i);
	}

	vector<int>::iterator it = find_if(v.begin(), v.end(), GreateFive());
	if (it != v.end()) {
		cout << *it << endl;
	}
	else {
		cout << "未能找到元素" << endl;
	}

}
class Person {
public:

	Person(string name, int age) :m_Name(name), m_Age(age) {}

	string m_Name;
	int m_Age;
};
class Create20 {
public:
	bool operator()(const Person & p) {
		return p.m_Age > 30;
	}
};
//自定义数据类型
void test3_2() {
	vector<Person> v;

	Person p1("赵云", 25);
	Person p2("关羽", 39);
	Person p3("卧龙", 30);
	Person p4("凤雏", 40);

	v.push_back(p1);
	v.push_back(p2);
	v.push_back(p3);
	v.push_back(p4);

	vector<Person>::iterator it = find_if(v.begin(), v.end(), Create20());
	if (it != v.end()) {
		cout <<it->m_Name<<" "<< it->m_Age << endl;
	}
	else {
		cout << "未能找到元素" << endl;
	}
}

int main3() {
	test3_2();
	system("pause");
	return 0;
}