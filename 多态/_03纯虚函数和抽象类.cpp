#include <iostream>
using namespace std;
//在多态中， 通常父类中虚函数的实现是毫无意义的，主要都是调用子类重写的内容
// 因此可以将虚函数改为纯虚函数
// 语法： virtual 返回值类型 函数名 （参数列表） = 0；
// 当类中有了纯虚函数，这个类也称为抽象类

//特点
// 无法实例化对象
// 子类必须重写父类中的纯虚函数，否则子类也为抽象类
class Base {
public:
	virtual void func() = 0;
};

class Son :public Base {
public:
	void func() {

	}
};

void test3_1() {

	// Base b; 抽象类无法实例化对象
	// Son s; 子类必须重写父类中的纯虚函数，否则子类也为抽象类
	Son s; // 子类重写父类纯虚函数后 可实例化
}

int main3() {

	test3_1();

	system("pause");
	return 0;
}