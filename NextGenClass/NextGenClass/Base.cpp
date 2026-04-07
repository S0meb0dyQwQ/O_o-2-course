#include "Base.h"
Point2D::Point2D(int a, int b) 
{
	x = a;
	y = b;
}
Point2D::Point2D(const Point2D& dot)
{
	x = dot.x;
	y = dot.y;
}
Point2D::Point2D(Point2D&& dot)
{
	x = dot.x;
	dot.x = 0;
	y = dot.y;
	dot.y = 0;
}
Point2D& Point2D:: operator = (const Point2D& dot) 
{
	if (this != &dot)
	{
		x = dot.x;
		y = dot.y;
	}
	return *this;
}
Point2D& Point2D:: operator = (Point2D&& dot)
{
	if (this != &dot)
	{
		x = dot.x;
		dot.x = 0;
		y = dot.y;
		dot.y = 0;
	}
	return *this;
}
Point2D Point2D:: operator + (const Point2D dot)
{
	return Point2D(x + dot.x, y + dot.y);
}
std::ostream&  operator <<(std::ostream& cout, Point2D a)
{
	return cout << "(" << a.x << ", " << a.y << ")";
}
Point2D Point2D:: operator - (const Point2D dot) 
{
	return *this + (- dot);
}
Point2D operator - (const Point2D& a) 
{
	return Point2D(-a.x, -a.y);
}
Point2D Point2D:: operator += (const Point2D dot)
{
	return *this = *this + dot;
}