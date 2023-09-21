#include <iostream>
using namespace std;
#include <string>
//继承方式
// 公共继承 父类中的私有属性不可访问、公共属性为公共继承、保护属性为保护继承
// 保护继承 父类中的私有属性不可访问、公共属性和保护属性为保护继承
// 私有继承 父类中的私有属性不可访问、公共属性和保护属性为私有继承
class Base {
public:
	int m_A;
protected:
	int m_B;
private :
	int m_C;
};

class Sum1 :public Base {
public :
	void func() {
		m_A = 100; //父类中公共访问权限的属性，到子类中访问权限不变
		m_B = 100; //父类中保护访问权限的属性，到子类中访问权限不变
		// m_C = 100; 父类中私有属性，子类不可访问
	}
};

class Sum2 : protected Base {
public :
	void func() {
		m_A = 100; //父类中公共访问权限的属性，到子类中访问权限变为保护
		m_B = 100; //父类中公共访问权限的属性，到子类中访问权限不变
		// m_C = 100; 父类中私有属性，子类不可访问
	}
};

class Sum3 : private Base {
public :
	void func() {
		m_A = 100;	//父类中公共访问权限的属性，到子类中访问权限变为私有
		m_B = 100;	//父类中公共访问权限的属性，到子类中访问权限变为私有
		// m_C = 100；父类中私有属性，子类不可访问
	}
};
class GrandSum3 : public Sum3 {
public:
	void function() {
		//m_A = 100; 侧面证实了 权限变为私有
		//m_B = 100;
	}
};

int main2() {



	system("pause");
	return 0;
}