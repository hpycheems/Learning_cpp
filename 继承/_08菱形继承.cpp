#include <iostream>
using namespace std;
#include <string>
//菱形继承概念：
// 两个派生类继承同一个基类
// 又有一个类同时继承两个派生类
// 这种继承被称为菱形继承，或钻石继承

// 利用虚继承来解决菱形继承的问题


// vbptr v- virtual b-base prt - pointer 虚基类指针 指向 vbtable（虚基类表）

// 菱形继承带来的主要问题是子类继承两份相同的数据，导致两份资源浪费以及毫无意义
// 利用虚继承可以解决菱形继承问题
class Animal{
public :
	int m_Age;
};

class Sheep:virtual public Animal {

};
class Tuo : virtual public Animal{

};

class SheepTuo : public Sheep, public Tuo {

};

void test8_1() {

	SheepTuo st;
	st.Sheep::m_Age = 18;
	st.Tuo::m_Age = 28;

	cout << "st.Sheep::m_Age =" << st.Sheep::m_Age << endl;
	cout << "st.Sheep::m_Age =" << st.Tuo::m_Age << endl;
	cout << "st.m_Age =" << st.m_Age << endl;
}

int main8() {
	test8_1();
	system("pause");
	return 0;
}