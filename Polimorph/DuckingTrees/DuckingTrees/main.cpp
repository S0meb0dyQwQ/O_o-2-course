#include "Tree.h"
#include "ForestTree.h"
#include "FruitTree.h"
#include "Container.h"
int main() 
{
	try {
		std::ifstream fin("Trees.txt");
		CheckInputFile(fin);
		int size{ CountSize(fin) };
		Container array{ size };
		MakeArrayFromFile(fin, array);
		array.Print();
		std::cout << "there are fruit trees: " << array.CountFruit() << '\n';
		std::cout << "there are forest trees: " << array.CountForest() << '\n';
		std::cout << "there are coniferous trees: " << array.CountConiferous() << '\n';
		std::cout << "there are deciduous trees: " << array.CountDeciduous() << '\n';
		array.PrintSorted();
	}
	catch (std::invalid_argument& e) 
	{
		std::cout << e.what();
	}
	catch (std::ios_base::failure& e)
	{
		std::cout << e.what();
	}
	return 0;
}