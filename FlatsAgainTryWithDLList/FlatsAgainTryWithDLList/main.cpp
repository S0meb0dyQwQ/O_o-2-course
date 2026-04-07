#include <iostream>
#include "Base.h"
int main()
{
	try {
		std::ifstream fin("Catalog.txt");
		List catalog;
		catalog.MakeCatalog(fin);
		//catalog.InputCatalog();
		std::cout << "Hello client. Here is our flat exchange catalog\n";
		catalog.ListPrint();
		Flat a;
		std::cout << "Please, fill out the exchange application\n";
		InputFlat(a);
		CheckFlatInfo(a);
		catalog.FindGoodElement(a);
		std::cout << "Well done. Your application has been approved\n";
		catalog.ListPrint();
		return 0;
	}
	catch (std::invalid_argument& error)
	{
		std::cout << error.what();
	}
	catch (std::exception& error)
	{
		std::cout << error.what();
	}
}