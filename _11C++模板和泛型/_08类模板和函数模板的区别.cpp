#include <iostream>
using namespace std;
template<class NameType, class AgeType = int>
class Person {
public:
	Person(NameType name, AgeType age) :m_Name(name), m_Age(age) {}
	void Show() {
		cout << m_Name << " " << m_Age << endl;
	}
	NameType m_Name;
	AgeType m_Age;
};

//��ģ��û���Զ������Ƶ�ʹ�÷�ʽ
void test8_1() {
	// Person p1("�����", 999);
	Person<string, int> p1("�����", 999);
	p1.Show();

}
//��ģ����ģ������б��п�����Ĭ�ϲ���
void test8_2() {
	Person<string> p2("��˽�", 900);
	p2.Show();
}

int main8() {
	test8_1();
	test8_2();
	system("pause");
	return 0;
}