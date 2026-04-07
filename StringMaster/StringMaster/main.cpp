#include "Base.h"
int main() 
 {
	try
	{
		String a;
		String b(a);
		std::cout << a + b << '\n';
		std::cout << a[2] << '\n';
		std::cout << a.size() << '\n';
		a.reverse();
		String delims;
		std::cout << b.find(delims) << '\n';
		std::cout << b.substr(2, 4) << '\n';
		/*
		std::cout<< b << '\n';
		b.insert(3, delims);
		b.replace(3, 3, delims);
		std::cout << b << '\n';*/
		b.push_back('e');
		b.append(2, '+');
		std::cout << b.erase(4) << '\n';
	}
	catch(std::invalid_argument& e)
	{
		std::cout << e.what();
	}
	catch (std::out_of_range& e)
	{
		std::cout << e.what();
	}
	return 0;
}