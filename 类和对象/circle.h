#pragma once
#include "point.h"
class Circle {
public:
	Circle(int r, Point center);
	int get_R();
	void set_R(int r);
	Point getCenter();
	void setCenter(Point center);
private:
	int m_R;
	Point m_Center;
};

