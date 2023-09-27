#include <iostream>
using namespace std;
#include <list>
#include <algorithm>


class Person {
public:
	
	Person(string name, int age, int height) :m_Name(name),m_Age(age),m_Height(height){}

	string m_Name;
	int m_Age;
	int m_Height;
};

bool personCompare(Person p1, Person p2) {//自定义排序 方式
	if (p1.m_Age == p2.m_Age) {
		return p1.m_Height > p2.m_Height;
	}
	else {
		return p1.m_Age < p2.m_Age;
	}
}

void test8_1() {

	list<Person> l;

	Person p1("孙策", 35, 160);
	Person p2("关羽", 25, 200);
	Person p4("赵云", 25, 178);
	Person p5("卧龙", 45, 190);
	Person p3("刘备", 25, 170);
	Person p6("凤雏", 50, 168);

	l.push_back(p1);
	l.push_back(p2);
	l.push_back(p3);
	l.push_back(p4);
	l.push_back(p5);
	l.push_back(p6);

	for (list<Person>::iterator it = l.begin(); it != l.end(); it++)
	{
		cout << it->m_Name << " " << it->m_Age << " " << it->m_Height << endl;
	}

	l.sort(personCompare);
	cout << "++++++++++++" << endl;
	for (list<Person>::iterator it = l.begin(); it != l.end(); it++)
	{
		cout << it->m_Name << " " << it->m_Age << " " << it->m_Height << endl;
	}
}

int main() {

	test8_1();

	system("pause");
	return 0;
}