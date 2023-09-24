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

//类模板没有自动类型推导使用方式
void test8_1() {
	// Person p1("孙悟空", 999);
	Person<string, int> p1("孙悟空", 999);
	p1.Show();

}
//类模板在模板参数列表中可以有默认参数
void test8_2() {
	Person<string> p2("猪八戒", 900);
	p2.Show();
}

int main8() {
	test8_1();
	test8_2();
	system("pause");
	return 0;
}