#include <iostream>
using namespace std;
//ģ�岢�������ܵģ���Щ�ض��������ͣ���Ҫ���廯��ʽ������ʵ��
// ���þ��廯ģ�壬 ���Խ���Զ������͵�ͨ�û�
// ѧϰģ�岢����Ϊ��дģ�壬 ������STL�ܹ�����ϵͳ�ṩ��ģ��
class Person {
public:
	Person(string name, int age) :m_Name(name), m_Age(age) {}

	string m_Name;
	int m_Age;
};

template<class T>
bool myConpare(T a, T b){
	if (a == b) {
		return true;
	}
	else {
		return false;
	}
}

template<> bool myConpare(Person a, Person b) {
	if(a.m_Age == b.m_Age){
		return true;
	}
	else {
		return false;
	}
}



void test6_1() {
	int a = 10;
	int b = 10;
	bool ref = myConpare(a, b);
	if (ref) {
		cout << "a == b" << endl;
	}
	else {
		cout << "a != b" << endl;
	}
}

void test6_2() {
	Person p1("Tom", 10);
	Person p2("Tom", 11);
	bool ref = myConpare(p1, p2);
	if (ref) {
		cout << "p1 == p2" << endl;
	}
	else {
		cout << "p1 != p2" << endl;
	}
}

int main6() {
	test6_1();
	test6_2();
	system("pause");
	return 0;
}