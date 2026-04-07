#include "Class.h"

int main()
{
	try
	{
		List L;
		/*int x = L.Top();
		std::cout << x << '\n';
		L.ListPrint();*/
		//L.ForEach(Print);
		L.InsertFirst(10);
		L.InsertFirst(20);
		L.InsertFirst(30);
		L.InsertSorted(8);
		//L.ListPrint();
		//List M = L;
		//std::cout << "list M" << '\n';
		//M.ListPrint();
		////M.ForEach(Print);
		//int a = L.Top();
		//std::cout << "Element at the top of list = ";
		//std::cout << a << '\n';
		//if (L.DeleteFirst())
		//{
		//	std::cout << "after delete" << '\n';
		//	L.ListPrint();
		//}
		//else
		//{
		//	std::cout << "list is empty" << '\n';
		//}
		//L.InsertFirst(40);
		//L.ListPrint();
	}
	catch (const char* msg) { std::cerr << msg; }
}