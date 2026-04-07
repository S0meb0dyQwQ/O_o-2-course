#ifndef NEXTGEN_H
#define NEXTGEN_H
#include "Base.h"
class Point3D :public Point2D
{
private:
	int z;
public:
	Point3D(int = 0, int = 0, int = 0);
	Point3D(const Point2D&, int = 0);
	Point3D(const Point3D&);
	Point3D(Point3D&&);
	~Point3D() = default;
	Point3D& operator = (const Point3D&);
	Point3D& operator = (Point3D&&);
	Point3D operator + (const Point3D&)const;
	Point3D operator += (const Point3D&);
	friend std::ostream& operator <<(std::ostream&, const Point3D);
};
#endif