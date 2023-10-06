#include <iostream>
using namespace std;
#include <string>
//继承中构造和析构的顺序
// 子类继承父类后， 当创建子类对象， 也会调用父类的构造函数

// 先构造父类 再构造子类
// 析构与构造相反

class Base {
public:
	Base() {
		cout << "Base 的构造！" << endl;
	}
	~Base() {
		cout << "Base 的析构！" << endl;
	}
};

class Sum :public Base {
public:
	Sum() {
		cout << "Sum 的构造！" << endl;
	}
	~Sum() {
		cout << "Sum 的析构！" << endl;
	}
};

void test4_1() {
	Sum s;
}

int main() {
	test4_1();

	system("pause");
	return 0;
}