#include <iostream>
using namespace std;


#include "myArray.hpp"

void printIntArray(MyArray<int>& a) {
	for (int i = 0; i < a.getSize(); i++)
	{
		cout << a[i] << endl;
	}
}

void test15_1() {
	
	MyArray<int> a(5);

	for (int i = 0; i < 5; i++)
	{
		a.Push_Back(i);
	}

	printIntArray(a);
	cout << "a �Ĵ�С �� " << a.getSize() << endl;
	cout << "a ������ �� " << a.getCapaciity() << endl;

	MyArray<int> b(a);
	b.Pop_Bakc();
	printIntArray(b);
	cout << "b �Ĵ�С �� " << b.getSize() << endl;
	cout << "b ������ �� " << b.getCapaciity() << endl;
}

class Person {
public :
	Person() {}
	Person(string name,int age):m_Age(age),m_Name(name){}

	string m_Name;
	int m_Age;
};

void printPeronsArray(MyArray<Person>& p) {
	for (int i = 0; i < p.getSize(); i++)
	{
		cout << p[i].m_Name << " " << p[i].m_Age << endl;
	}
}

void test5_2() {
	MyArray<Person> p(10);

	Person p1("�����", 900);
	Person p2("��˽�", 800);
	Person p3("��ɮ", 40);
	Person p4("������", 400);
	Person p5("ɳɮ", 700);

	p.Push_Back(p1);
	p.Push_Back(p2);
	p.Push_Back(p3);
	p.Push_Back(p4);
	p.Push_Back(p5);
	printPeronsArray(p);
	cout << "p �Ĵ�С �� " << p.getSize() << endl;
	cout << "p ������ �� " << p.getCapaciity() << endl;

}

int main() {
	//test15_1();
	test5_2();

	system("pause");
	return 0;
}