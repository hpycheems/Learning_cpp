#include <iostream>
using namespace std;
// 多态使用的时候，如果子类中有属性开辟到堆，那么父类指针在释放时无法调用到子类的析构代码

// 父类指针在析构时候 不会调用子类中析构函数，导致子类如果有堆区属性，出现内存泄露

// 解决方式：将父类中的析构函数改为虚析构或纯虚析构

// 前提： 父类指针指向子类对象

//虚析构和纯虚析构共性
// 可以解决父类指针释放子类对象
// 都需要有具体的函数实现

//虚析构和纯虚析构区别：
// 如果是纯虚析构，该类属于抽象类，无法实例化对象
// 
// 纯虚析构 需要声明也需要实现

class Animal1
{
public :
	Animal1() {
		cout << " Animal 的构造调用" << endl;
	}

	//虚析构
	//virtual ~Animal1() {
	//	cout << " Animal 的析构调用" << endl;
	//}
	
	//纯虚析构
	virtual ~Animal1() = 0;

	// 纯虚函数
	virtual void speak() = 0;

};
// 纯虚析构 需要声明 也需要实现
Animal1::~Animal1() {
	cout << " Animal 的存虚析构调用" << endl;
}


class Cat1 :public Animal1{
public:
	Cat1(string name) {
		m_Name = new string(name);
		cout << "Cat 构造函数调用 " << endl;
	}
	void speak() {
		cout << *m_Name << "猫在说话" << endl;
	}

	~Cat1() {
		if (m_Name != NULL) {
			delete m_Name;
			m_Name = NULL;
		}
		cout << "Cat 的析构调用" << endl;
	}

	string* m_Name;
};

void test5_1() {
	Animal1* c = new Cat1("Tom");

	c->speak();
	delete c;
}


int main5() {

	test5_1();

	system("pause");
	return 0;
}