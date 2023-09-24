#include <iostream>
using namespace std;
//¿‡ƒ£∞Â
template<class NameType, class AgeType> 
class Person {
public:
	Person(NameType name, AgeType Age):m_Name(name),m_Age(Age) {}

	NameType m_Name;
	AgeType m_Age;
};

void test7_1() {
	Person<string, int> p1("÷Ì∞ÀΩ‰", 1000);

	cout << p1.m_Name << " " << p1.m_Age << endl;
}

int main7() {
	test7_1();

	system("pause");
	return 0;
}