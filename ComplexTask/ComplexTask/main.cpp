#include "Base.h"
int main()
{
	try {
		Complex a;
		std::cin >> a;
		Complex b(4, 9);
		Complex d(a);
		std::cout << d << '\n';
		std::cout << a + b << '\n';
		std::cout << a * d << '\n';
		std::cout << a / d << '\n';
		std::cout << a.opposite() << '\n';
		std::cout << a.reverse() << '\n';
		std::cout << a.module() << '\n';
		std::cout << a.argument() << '\n';
		std::cout << a.sqrtcomplex() << '\n';
	}
	catch (std::invalid_argument& a)
	{
		std::cout << a.what();
	}
	return 0;
}