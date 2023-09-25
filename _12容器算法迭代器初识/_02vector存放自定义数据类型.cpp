#include<iostream>
using namespace std;
#include <vector>

class Person {
public:
	Person(string name, int age):m_Age(age),m_Name(name) {}

	string m_Name;
	int m_Age;
};

void test2_1() {

	vector<Person> v;

	Person p1("a", 10);
	Person p2("b", 20);
	Person p3("c", 30);
	Person p4("d", 40);
	Person p5("e", 50);

	v.push_back(p1);
	v.push_back(p2);
	v.push_back(p3);
	v.push_back(p4);
	v.push_back(p5);

	//遍历 vecotr中存放的是数据的指针
	for (vector<Person>::iterator it = v.begin(); it != v.end(); it++)
	{
		cout << "名字： " << it->m_Name << " 年龄：" << it->m_Age << endl;
	}

}
void test2_2() {

	vector<Person*> v;

	Person p1("a", 10);
	Person p2("b", 20);
	Person p3("c", 30);
	Person p4("d", 40);
	Person p5("e", 50);

	v.push_back(&p1);
	v.push_back(&p2);
	v.push_back(&p3);
	v.push_back(&p4);
	v.push_back(&p5);

	//遍历 vecotr中存放的是数据的指针
	for (vector<Person*>::iterator it = v.begin(); it != v.end(); it++)
	{
		cout << "::名字： " << (*it)->m_Name << " 年龄：" << (*it)->m_Age << endl;
	}

}

int main2() {

	//test2_1();
	test2_2();
	system("pause");
	return 0;
}