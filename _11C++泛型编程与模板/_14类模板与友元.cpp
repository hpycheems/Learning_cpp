#include <iostream>
using namespace std;

template<class T1, class T2>
class Person1;

template<class T1, class T2>
void func1(Person1<T1, T2> p) {
	cout << "����ʵ�֡�������" << p.m_Name << " " << p.m_Age << endl;
}

template<class T1, class T2>
class Person1{
	//ȫ�ֺ�������ʵ��
	friend void func(Person1<T1,T2> &p) {
		cout << p.m_Name << " " << p.m_Age << endl;
	}

	//ȫ�ֺ�������ʵ��
	//�м� ���Ͽ�ģ������б� ������Ϊ��ͬȫ�ֺ���
	friend void func1<>(Person1<T1, T2> p);
public:
	Person1(T1 name, T2 age);
private:
	T1 m_Name;
	T2 m_Age;
};

template<class T1, class T2>
Person1<T1,T2>::Person1(T1 name,T2 age){
	this->m_Age = age;
	this->m_Name = name;
}

void test14_1() {

	Person1<string, int> p("Tom", 19);
	func(p);
}
void test14_2() {
	Person1<string, int> p("Tom", 19);
	func1(p);
}

int main14() {
	test14_1();
	test14_2();
	system("pause");
	return 0;
}
