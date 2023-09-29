#include <iostream>
using namespace std;
#include <vector>
#include <algorithm>

/*
count: 统计元素个数
原型：
	count(iterator beg, iterator end, value);
	统计元素出现次数
*/

//内置数据类型 
void test6_1() {
	vector<int> v;
	v.push_back(0);
	v.push_back(1);
	v.push_back(0);
	v.push_back(2);
	v.push_back(0);
	v.push_back(3);

	int num = count(v.begin(), v.end(), 0);
	cout << "v中0的个数为" << num << endl;
}
class Person1 {
public:

	Person1(string name, int age) :m_Name(name), m_Age(age) {}

	bool operator == (const Person1& p) {
		if (this->m_Age == p.m_Age) {
			return true;
		}
		else {
			return false;
		}
	}

	string m_Name;
	int m_Age;
};
//自定义数据类型
void test6_2() {
	vector<Person1> v;

	Person1 p1("刘备", 30);
	Person1 p2("关羽", 30);
	Person1 p3("张飞", 30);
	Person1 p4("赵云", 25);
		  
	v.push_back(p1);
	v.push_back(p2);
	v.push_back(p3);
	v.push_back(p4);
	Person1 p("卧龙", 30);
	int num = count(v.begin(), v.end(), p);
	cout << "与卧龙同岁的有" << num << " 个" << endl;


}


int main6() {

	//test6_1();
	test6_2();
	system("pause");
	return 0;
}