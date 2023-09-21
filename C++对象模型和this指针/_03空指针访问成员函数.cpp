#include <iostream>
using namespace std;
#include<string>

class Person {
public:
	void showPersonClass() {
		cout << "this is Person Class" << endl;
	}
	void showPersonAge() {

		if (this == NULL)
			return;

		//报错原因， this传入的是NULL
		cout << "this person age is" << this->m_Age << endl;
	}

	int m_Age;
};

void test3_1() {
	Person* p = NULL;//空指针访问成员函数
	p->showPersonClass();

	p->showPersonAge();
}

int main3() {
	test3_1();
	system("pause");
	return 0;
}