#include <iostream>
using namespace std;
//多态分为两类：
// 静态多态：函数重载 和 运算符重载属于静态多态，复用函数名
// 动态多态：派生类和虚函数实现运行时多态
//区别：
// 静态多态的函数地址早绑定 - 编译阶段确定函数地址
// 动态多态的函数地址晚绑定 - 运行阶段确定函数地址

// 父类引用接受子类对象（允许父子类型之间的类型转换）

//动态多态满足条件
// 1、有继承关系
// 2、子类重写父类的虚函数

//调用
// 父类的指针或引用 指向子类对象

//剖析 通过开发人员命令提示工具验证
// vfptr v-virtual f-function prt-pointer 虚函数（表）指针
// vftable v-virtual f-function table 虚函数表
// 当子类重写父类的虚函数
// 子类中的虚函数表，内部会替换成子类的重写函数地址

class Animal {
public :
	void speak() {
		cout << "动物 说话" << endl;
	}
	virtual void Speak() {
		cout << "动物 说话" << endl;
	}
};

class Cat :public Animal {
public :
	// 重写 ：返回值 函数名称 参数列表完全相同
	void speak() {
		this->Animal::speak();//Base::speck();
		cout << "猫 说话" << endl;
	}
	void Speak() {
		Animal::speak();
		cout << "猫 说话" << endl;
	}
};
class Dog :public Animal {
public:
	void Speak() {
		cout << "狗 说话" << endl;
	}
};

void doSpeak(Animal &animal) {
	animal.Speak();
}

//地址早绑定 在编译阶段确定函数地址
//如果想执行让猫说话，这个函数地址就不能提前绑定，需要在运行阶段绑定，地址晚绑定
void test1_1() {
	Cat cat;
	doSpeak(cat);

	//Dog dog;
	//doSpeak(dog);
}

int main1() {
	test1_1();
	system("pause");
	return 0;
}