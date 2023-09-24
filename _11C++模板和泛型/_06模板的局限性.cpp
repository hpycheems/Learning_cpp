#include <iostream>
using namespace std;
//模板并不是万能的，有些特定数据类型，需要具体化方式做特殊实现
// 利用具体化模板， 可以解决自定义类型的通用化
// 学习模板并不是为了写模板， 而是在STL能够运用系统提供的模板
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