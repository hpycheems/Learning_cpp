#include "circle.h"

Circle::Circle(int r, Point center) :m_R(r), m_Center(center) {}
int Circle::get_R() {
	return m_R;
}
void Circle::set_R(int r) {
	m_R = r;
}
Point Circle::getCenter() {
	return m_Center;
}
void Circle::setCenter(Point center) {
	m_Center = center;
}
