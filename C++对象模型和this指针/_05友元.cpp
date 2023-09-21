#include <iostream>
using namespace std;
#include<string>
//友元
// 全局函数做友元
// 类做友元
// 成员函数做友元

class Building;

class GoodGay {
public:
	GoodGay();
	//void visit();

	void visit_1();
	void visit_2();
private:
	Building* building;
};

class Building {
	// 告诉编译器 goodGay全局函数是Building类的好朋友，可以访问类中私有内容
	friend void goodGay(Building& building);

	// 告诉编译器， GoodGay类是Building类的好朋友，可以访问到Building类的私有内容
	//friend class GoodGay;

	//告诉编译器 goodGay类中的visit_1成员函数是Building的好朋友， 可以访问私有内容
	friend 	void GoodGay::visit_1();

public :
	Building() {
		m_SittingRoom = "客厅";
		m_BedRoom = "卧室";
	}

	string m_SittingRoom;//客厅
private :
	string m_BedRoom;//卧室
};


GoodGay::GoodGay() {
	building = new Building;
}
//void GoodGay::visit() {
//	cout << "正在访问 ：" << building->m_SittingRoom<< endl;
//
//	cout << "正在访问 ：" << building->m_BedRoom<< endl;
//}

void GoodGay::visit_1() {
	cout << "正在访问 ：" << building->m_SittingRoom << endl;

	cout << "正在访问 ：" << building->m_BedRoom << endl;
}
void GoodGay::visit_2() {
	cout << "正在访问 ：" << building->m_SittingRoom << endl;
}


void goodGay(Building &building) {
	cout << "正在访问 ：" << building.m_SittingRoom << endl;

	cout << "正在访问 ：" << building.m_BedRoom << endl;
}

void test5_1() {
	Building b;
	goodGay(b);
}

void test5_2() {
	GoodGay g;
	//g.visit();
}

void test5_3() {
	GoodGay g;
	g.visit_1();
	g.visit_2();
}

int main5() {

	//test5_1();

	test5_3();

	system("pause");
	return 0;
}