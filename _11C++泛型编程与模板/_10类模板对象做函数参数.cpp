#include <iostream>
using namespace std;

//��ģ���������������
template<class T1, class T2>
class Person {
public:
	Person(T1 name, T2 age):m_Name(name),m_Age(age){}
	void Show() {
		cout << m_Name << " " << m_Age << endl;
	}
	T1 m_Name;
	T2 m_Age;
};

// ָ����������
void printPerson1(Person<string , int > &p){
	p.Show();
}

void test10_1() {
	Person<string, int> p("�����", 100);
	printPerson1(p);
}

// ����ģ�ͻ�
template<class T1, class T2>
void printPerson2(Person<T1, T2 >& p) {
	p.Show();
}
void test10_2() {
	Person<string, int> p("��˽�", 90);
	printPerson2(p);
}

// ������ģ�廯
template<class T>
void printPerson3(T & p) {
	p.Show();
}
void test10_3() {
	Person<string, int> p("��ɮ", 40);
	printPerson3(p);
}

int main10() {
	test10_1();
	test10_2();
	test10_3();
	system("pause");
	return 0;
}