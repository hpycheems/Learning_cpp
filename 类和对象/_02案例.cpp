#include <iostream>
using namespace std;
#include<string>
//立方体类设计

class Cube {
private:
	int m_L;
	int m_W;
	int m_H;
public:
	Cube(int l, int w, int h) :m_L(l), m_W(w), m_H(h) {}
	void setL(int l) {
		m_L = l;
	}
	int getL() {
		return m_L;
	}
	void setW(int w) {
		m_W = w;
	}
	int getW() {
		return m_W;
	}
	void setH(int h) {
		m_H = h;
	}
	int getH() {
		return m_H;
	}
	//计算面积
	int calculateS() {
		return 2 * (m_L * m_W + m_L * m_H + m_W * m_H);
	}
	//计算体积
	int calculateV() {
		return m_L * m_W * m_H;
	}
	//利用成员函数判断两个立方体是否相等
	bool isSameByClass(Cube& c){
		if (m_H == c.getH() &&
			m_L == c.getL() &&
			m_W == c.getW())
		{
			return true;
		}
		return false;
		return false;
	}
};

//利用全局函数判断两个立方体是否相等
bool isSame(Cube &c1, Cube &c2) {
	if (c1.getH() == c2.getH() &&
		c1.getL() == c2.getL() &&
		c1.getW() == c2.getW()) 
	{
		return true;
	}
	return false;
}
int main2() {

	Cube c(10, 10, 10);
	cout << "立方体的面积：" << c.calculateS() << endl;
	cout << "立方体的体积：" << c.calculateV() << endl;

	Cube c1(10, 20, 30);
	bool res = isSame(c, c1);
	if (res) {
		cout << "C1 与 C相等" << endl;
	}
	else {
		cout << "C1 与 C不相等" << endl;
	}

	Cube c2(10, 10, 10);
	res = c2.isSameByClass(c);
	if (res) {
		cout << "C2 与 C相等" << endl;
	}
	else {
		cout << "C2 与 C不相等" << endl;
	}
	system("pause");
	return 0;
}