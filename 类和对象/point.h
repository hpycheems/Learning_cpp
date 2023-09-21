#pragma once
class Point {
public:
	Point(int x, int y);
	int getX();
	void setX(int x);
	int getY();
	void setY(int y);
private:
	int m_X;
	int m_Y;
};
