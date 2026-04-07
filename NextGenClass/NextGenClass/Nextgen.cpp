#include "Nextgen.h"
Point3D:: Point3D(int a, int b, int c): Point2D(a,b), z(c){}
Point3D::Point3D(const Point2D& dot, int c) :Point2D(dot), z(c) {}
Point3D::Point3D(const Point3D& dot):Point2D(dot), z(dot.z){}
Point3D:: Point3D(Point3D&& dot):Point2D(dot), z(dot.z)
{
	dot.z = 0;
}
Point3D& Point3D:: operator = (const Point3D& dot)
{
	if (this != &dot)
	{
		Point2D::operator=(dot);
		z = dot.z;
	}
	return *this;
}
Point3D& Point3D:: operator = (Point3D&& dot)
{
	if (this != &dot)
	{
		Point2D::operator=(dot);
		z = dot.z;
		dot.z = 0;
	}
	return *this;
}
Point3D Point3D:: operator + (const Point3D& dot)const
{
	return Point3D(x + dot.x, y + dot.y, z + dot.z);
}
Point3D Point3D:: operator += (const Point3D& dot) 
{
	return *this = *this + dot;
}
std::ostream& operator <<(std::ostream& cout, const Point3D dot)
{
	return cout  <<static_cast<Point2D>(dot)<<"\b, " << ", " << dot.z << ")";
}