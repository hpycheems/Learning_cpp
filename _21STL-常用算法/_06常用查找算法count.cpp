#include <iostream>
using namespace std;
#include <vector>
#include <algorithm>

/*
count: ͳ��Ԫ�ظ���
ԭ�ͣ�
	count(iterator beg, iterator end, value);
	ͳ��Ԫ�س��ִ���
*/

//������������ 
void test6_1() {
	vector<int> v;
	v.push_back(0);
	v.push_back(1);
	v.push_back(0);
	v.push_back(2);
	v.push_back(0);
	v.push_back(3);

	int num = count(v.begin(), v.end(), 0);
	cout << "v��0�ĸ���Ϊ" << num << endl;
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
//�Զ�����������
void test6_2() {
	vector<Person1> v;

	Person1 p1("����", 30);
	Person1 p2("����", 30);
	Person1 p3("�ŷ�", 30);
	Person1 p4("����", 25);
		  
	v.push_back(p1);
	v.push_back(p2);
	v.push_back(p3);
	v.push_back(p4);
	Person1 p("����", 30);
	int num = count(v.begin(), v.end(), p);
	cout << "������ͬ�����" << num << " ��" << endl;


}


int main6() {

	//test6_1();
	test6_2();
	system("pause");
	return 0;
}