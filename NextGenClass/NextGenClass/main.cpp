#include "Base.h"
#include "Nextgen.h"
int main() 
{
	Point2D a(3, 5);
	Point2D b(8, 3);
	std::cout << a;
	std::cout << a - b;
	Point3D k(0, 1, 3);
	Point3D l(9, 0, 2);
	std::cout << k + l<< '\n';

	Point2D** arr = new Point2D * [5];
	arr[0] = new Point2D (2, 7);
	arr[1] = &a;
	arr[2] = &b;
	arr[3] = new Point3D(2, 7, 10);
	arr[4] = &l;
	for (int i{}; i < 5; ++i)
	{
		std::cout << typeid(*arr[i]).name()<<'\n';
	}
	return 0;
}