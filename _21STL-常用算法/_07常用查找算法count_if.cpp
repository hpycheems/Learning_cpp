#include <iostream>
using namespace std;
#include <vector>
#include <algorithm>
/*
count_if: 按条件统计元素个数
原型：
	count_if(iterator beg, iterator end,_Pred)
	按条件统计元素出现次数
*/

class Greate5 {
public:
	bool operator()(int val) {
		return val > 5;
	}
};

//内置数据类型
void test7_1() {

	vector<int> v;
	for (int i = 0; i < 10; i++)
	{
		v.push_back(i);
	}

	int num = count_if(v.begin(), v.end(), Greate5());
	cout << "大于5的元素个数为" << num << endl;

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
class AgeGreate20 {
public:
	bool operator()(const Person1 & p) {
		return p.m_Age > 20;
	}
};
//自定义数据类型
void test7_2() {

	vector<Person1> v;

	Person1 p1("刘备", 30);
	Person1 p2("关羽", 30);
	Person1 p3("张飞", 30);
	Person1 p4("赵云", 25);

	v.push_back(p1);
	v.push_back(p2);
	v.push_back(p3);
	v.push_back(p4);

	int num = count_if(v.begin(),v.end(), AgeGreate20());
	cout << "年龄大于20的个数" << num << endl;
}
int main7() {

	test7_2();

	system("pause");
	return 0;
}