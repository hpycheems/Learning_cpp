#include <iostream>
using namespace std;
#include <vector>
#include <algorithm>

/*
find������ָ��Ԫ�أ��ҵ�����ָ��Ԫ�صĵ��������Ҳ������ؽ���������end()
ԭ�ͣ�
find(iterator beg, iterator end, elem)
*/

// �ڽ���������
void test2_1() {
	vector<int> v;

	for (int i = 0; i < 5; i++)
	{
		v.push_back(i);
	}

	vector<int>::iterator it = find(v.begin(), v.end(), 10);
	if (it != v.end()) {
		cout << "�ҵ�Ԫ��" << *it << endl;
	}
	else {
		cout << "δ���ҵ�Ԫ��" << endl;
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
//�Զ�����������
void test2_2() {
	vector<Person> v;

	Person p1("����", 25);
	Person p2("����", 39);
	Person p3("����", 30);
	Person p4("���", 40);

	v.push_back(p1);
	v.push_back(p2);
	v.push_back(p3);
	v.push_back(p4);

	vector<Person>::iterator it = find(v.begin(), v.end(), Person("����", 30));
	if (it != v.end()) {
		cout << "���ҵ���" << it->m_Name << " " << it->m_Age << endl;
	}
	else {
		cout << "δ���ҵ�Ԫ��" << endl;
	}

}

int main2() {

	test2_2();
	system("pause");
	return 0;
}