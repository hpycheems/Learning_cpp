#include<iostream>
using namespace std;
#include<string>
//关系运算符重载
// 让两个自定义类型对象进行比较

class Person {
public :
	Person(string name, int age) {
		m_Name = name;
		m_Age = age;
	}

	bool operator==(Person & p) {
		if (m_Name == p.m_Name && m_Age == p.m_Age) {
			return true;
		}
		return false;
	}

	bool operator!=(Person& p) {
		if (m_Name == p.m_Name && m_Age == p.m_Age) {
			return false;
		}
		return true;
	}

	string m_Name;
	int m_Age;

};

void test5_1() {
	Person p1("Tom", 18);
	Person p2("Jerry", 18);

	if (p1 == p2) {
		cout << "p1 和 p2 是相等的!" << endl;
	}
	else {
		cout << "p1 和 p2 是不相等的!" << endl;
	}

	if (p1 != p2) {
		cout << "p1 和 p2 是不相等的!" << endl;
	}
	else {
		cout << "p1 和 p2 是相等的!" << endl;
	}
}

int main5() {

	test5_1();
	system("pause");
	return 0;
}