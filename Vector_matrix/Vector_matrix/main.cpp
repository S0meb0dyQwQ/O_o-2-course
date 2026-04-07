#include "Base.h"
int main()
{
	try 
	{
		Matrix<char> a(3, 3, 3);
		std::cout << a<<'\n';
		Matrix<char>b(3, 3, 9);
		std::cout << b - a<<'\n';
		std::cout << b * a<<'\n';
		std::cin >>b;
		std::cout << b<<'\n';
		std::cout << b.Trans()<<'\n';
		std::cout << a.Identity(4);
	}
	catch (std::invalid_argument& e) 
	{
		std::cout << e.what();
	}
	return 0;
}