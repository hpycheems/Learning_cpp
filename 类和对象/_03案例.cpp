#include <iostream>
using namespace std;
#include<string>
#include "point.h"
#include "circle.h"

//class Point {
//public:
//	Point(int x, int y) :m_X(x), m_Y(y) {}
//	int getX() {
//		return m_X;
//	}
//	void setX(int x) {
//		m_X = x;
//	}
//	int getY() {
//		return m_Y;
//	}
//	void setY(int y) {
//		m_Y = y;
//	}
//private:
//	int m_X;
//	int m_Y;
//};

//class Circle {
//public:
//	Circle(int r, Point center) :m_R(r), m_Center(center) {}
//	int get_R() {
//		return m_R;
//	}
//	void set_R(int r) {
//		m_R = r;
//	}
//	Point getCenter() {
//		return m_Center;
//	}
//	void setCenter(Point center) {
//		m_Center = center;
//	}
//private:
//	int m_R;
//	Point m_Center;
//};

//点和圆的关系
void determinePointCircle(Circle &c, Point &p) {
	//计算距离
	float distance =
		(c.getCenter().getX() - p.getX()) * (c.getCenter().getX() - p.getX()) +
		(c.getCenter().getY() - p.getY()) * (c.getCenter().getY() - p.getY());
	float rDistance = c.get_R() * c.get_R();

	if (distance == rDistance) {
		cout << "点在圆上" << endl;
 	}
	else if (distance > rDistance) {
		cout << "点在圆外" << endl;
	}
	else {
		cout << "点在圆内" << endl;
	}
}

int main3() {
	Point p1(10,11);
	Circle c1(10,Point(10,0));
	determinePointCircle(c1, p1);

	system("pause");
	return 0;
}