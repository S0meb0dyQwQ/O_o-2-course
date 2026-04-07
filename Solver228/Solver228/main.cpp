#include "Base.h"
#include "Linear.h"
#include "quadratic.h"
int main()
{
	try
	{
		Equation** array = new Equation*[5];
		array[0] = new Linear(2, 3);
		array[1] = new Quadratic(5, 1, 9);
		array[2] = new Linear(0, 10);
		array[3] = new Quadratic(9, 6, 1);
		array[4] = new Quadratic(-1, -4, -4);

		MakeEquationFileInfo(array);
		std::cout << "here those losers who have no roots\n";
		FindWhoHaveNoRoots(array);
		std::cout << "with endless amount of roots\n";
		std::cout << "there are: " << FindWithEndlessRoots(array)<<'\n';
		std::cout << "here sorted array\n";
		SortArrayBySenior(array);
		std::cout << "there are with sad smile(a < 0)\n";
		FindSadSmile(array);
		std::cout << "there full squares sorted by ascend\n";
		FindFullSquare(array);
		std::cout << "there b > a\n";
		FindSeniorLessB(array);

	}
	catch (std::invalid_argument& e)
	{
		std::cout << e.what();
	}
	return 0;
}