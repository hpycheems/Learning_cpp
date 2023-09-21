#include "point.h"
Point::Point(int x, int y) :m_X(x), m_Y(y) {}
int Point::getX() {
	return m_X;
}
void Point::setX(int x) {
	m_X = x;
}
int Point::getY() {
	return m_Y;
}
void Point::setY(int y) {
	m_Y = y;
}
