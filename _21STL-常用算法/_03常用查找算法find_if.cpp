#include <iostream>
using namespace std;
#include <vector>
#include <algorithm>

/*
find_if: ����������Ԫ��
ԭ�ͣ�
find_if(iterator beg, iterator end,_Pred);
_Pred ν��(1Ԫν�ʣ�2Ԫν��)
�ҵ�����ָ��λ�õ��������Ҳ������ؽ���������
*/

class GreateFive {
public :
	bool operator()(int val) {
		return val > 3;
	}
};
//������������
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
		cout << "δ���ҵ�Ԫ��" << endl;
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
//�Զ�����������
void test3_2() {
	vector<Person> v;

	Person p1("����", 25);
	Person p2("����", 39);
	Person p3("����", 30);
	Person p4("���", 40);

	v.push_back(p1);
	v.push_back(p2);
	v.push_back(p3);
	v.push_back(p4);

	vector<Person>::iterator it = find_if(v.begin(), v.end(), Create20());
	if (it != v.end()) {
		cout <<it->m_Name<<" "<< it->m_Age << endl;
	}
	else {
		cout << "δ���ҵ�Ԫ��" << endl;
	}
}

int main3() {
	test3_2();
	system("pause");
	return 0;
}