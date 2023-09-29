#include <iostream>
using namespace std;
#include <set>
#include <algorithm>

/*
set����Ĭ���������Ϊ��С����������θı��������

��Ҫ�����㣺
���÷º��������Ըı��������
*/

//�º���
class MyCompare1 {
public:
	bool operator()(int val1, int val2) const {
		return val1 > val2;
	}
};
//��ͨ����
bool compareTest(const int val1, const int val2) {
	return val1 > val2;
}

void test7_1() {

	//�ڹ����Ǵ��� Ҫʵ�ֵ�����ʽ
	set<int, MyCompare1> s;

	s.insert(20);
	s.insert(10);
	s.insert(40);
	s.insert(30);
	s.insert(50);

	//���ַ�ʽҲ�ǲ��е�
	//sort(s.begin(), s.end(), compareTest);


	for (set<int>::iterator it = s.begin(); it != s.end(); it++)
	{
		cout << *it << " ";
	}
	cout << endl;
}

//�Զ�����������Ͷ���ָ���������

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

//�Զ������� ����
void test7_2() {
	set<Person, comparePerson> s;

	Person p1("����", 25);
	Person p2("���", 30);
	Person p3("����", 21);
	Person p4("����", 28);

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