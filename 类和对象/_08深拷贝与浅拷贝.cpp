#include <iostream>
using namespace std;
#include<string>

// 深拷贝与浅拷贝
// 浅拷贝：简单的赋值操作 (编译器提供的拷贝构造就是浅拷贝)
// 深拷贝：在堆区重新申请空间，进行拷贝 (自定义拷贝构造，重新在堆中开辟空间)
// 如果属性有在堆区开辟的，一定要自己提供拷贝构造函数，防止浅拷贝带来的问题
class Person_2 {
public :
	int m_Age;
	int* m_Height;
	Person_2() {
		cout << "Person_2 的默认构造函数" << endl;
	}
	Person_2(int age) {
		m_Age = age;
		m_Height = new int(160);
		cout << "Person_2 的有参构造函数" << endl;
	}

	//如何解决浅拷贝 自己定义拷贝函数 让指针指向不同的堆地址
	Person_2(const Person_2 & p) {
		m_Age = p.m_Age;
		//m_Height = p.m_Height;// 编译器默认提供的代码
		m_Height = new int(*p.m_Height);

		cout << "Person_2 的有拷贝造函数" << endl;
	}

	~Person_2() {
		//将堆区开辟的数据做释放操作
		if (m_Height != NULL) {
			delete m_Height;
			m_Height = NULL;
		}
		cout << "Person_2 的析构函数" << endl;
	}
};

void test_1() {
	Person_2 p1(18);
	Person_2 p2(p1);

	cout << "p1 的年龄：" << p1.m_Age << "p1 的身高：" << *p1.m_Height << endl;
	cout << "p2 的年龄：" << p2.m_Age << "p2 的身高：" << *p2.m_Height << endl;
}

int main8() {

	test_1();

	system("pause");
	return 0;
}