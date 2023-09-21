#include<iostream>
using namespace std;
#include<string>
//赋值运算符重载
// C++编译器至少给一个类添加4个函数
// 1 默认构造函数
// 2 默认析构函数
// 3 默认拷贝构造函数
// 4 赋值运算符operator=,对属性进行拷贝

//编译器默认提供的赋值运算符重载 是一个浅拷贝的操作
//利用深拷贝解决浅拷贝

class Person {
public :
	Person(int age){
		m_Age = new int(age);
	}

	//由于编译器默认提供的赋值运算符是 浅拷贝 所以需要自己实现深拷贝
	Person& operator =(Person &p) {
		//先判断是否有属性在堆区，如果有先释放干净，然后再深拷贝
		//if (m_Age != NULL) {
		//	delete m_Age;
		//	m_Age = NULL;
		//}
		//m_Age = new int(*p.m_Age);

		//解引用自身的年龄 把值赋给它
		*this->m_Age = *p.m_Age;
		return *this;
	}


	~Person() {

		if (m_Age != NULL) {
			delete m_Age;
			m_Age = NULL;
		}

	}
	int* m_Age;
};


void test4_1() {
	Person p1(18);

	Person p2(20);

	Person p3(30);

	p3 = p2 = p1;

	cout << "P1 的年龄 ：" << *p1.m_Age << endl;

	cout << "P2 的年龄 ：" << *p2.m_Age << endl;

	cout << "P3 的年龄 ：" << *p3.m_Age << endl;
}

int main4() {

	test4_1();

	system("pause");
	return 0;
}