#ifndef BASE_H
#define BASE_H
#include <iostream>
class Point2D 
{
protected:
	int x;
	int y;
public:
	Point2D(int = 0, int = 0);
	virtual~Point2D() = default;
	Point2D(const Point2D&);
	Point2D(Point2D&&);
	Point2D& operator = (const Point2D&);
	Point2D& operator = (Point2D&&);
	Point2D operator += (const Point2D);
	Point2D operator + (const Point2D);
	Point2D operator - (const Point2D);
	friend Point2D operator - (const Point2D&);
	friend std::ostream& operator <<(std::ostream&, const Point2D);
};
#endif