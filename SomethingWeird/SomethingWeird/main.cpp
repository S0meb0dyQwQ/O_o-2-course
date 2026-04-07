#include "Base.h"
int main()
{
	try {
		Fraction a;
		Fraction d(0.123);
		std::cout << d;
		double f{ 0.9 };
		d / f;
	}
	catch (std::logic_error& e) 
	{
		std::cout << e.what();
	}
	return 0;
}