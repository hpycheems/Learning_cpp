#include <iostream>
using namespace std;
#include <vector>
#include <algorithm>
/*
count_if: ������ͳ��Ԫ�ظ���
ԭ�ͣ�
	count_if(iterator beg, iterator end,_Pred)
	������ͳ��Ԫ�س��ִ���
*/

class Greate5 {
public:
	bool operator()(int val) {
		return val > 5;
	}
};

//������������
void test7_1() {

	vector<int> v;
	for (int i = 0; i < 10; i++)
	{
		v.push_back(i);
	}

	int num = count_if(v.begin(), v.end(), Greate5());
	cout << "����5��Ԫ�ظ���Ϊ" << num << endl;

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
//�Զ�����������
void test7_2() {

	vector<Person1> v;

	Person1 p1("����", 30);
	Person1 p2("����", 30);
	Person1 p3("�ŷ�", 30);
	Person1 p4("����", 25);

	v.push_back(p1);
	v.push_back(p2);
	v.push_back(p3);
	v.push_back(p4);

	int num = count_if(v.begin(),v.end(), AgeGreate20());
	cout << "�������20�ĸ���" << num << endl;
}
int main7() {

	test7_2();

	system("pause");
	return 0;
}