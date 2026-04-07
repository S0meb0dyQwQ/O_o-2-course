#include <iostream>
#include "Base.h"
int main()
{
	try {
		std::ifstream fin_num("Numbers.txt");
		std::ifstream fin_str("Strings.txt");
		std::ofstream fout("result.txt");
		int32_t amount{ };
		int32_t array[100];
		FillArray(fin_num, array, amount);
		int32_t* allNumbers = new int32_t[amount];
		MakeCopy(array, allNumbers, amount);
		SortCopy(allNumbers, amount);
		std::string allSurnames[100];
		int32_t counter{};
		MakeSurnames(fin_str, allSurnames, counter);
		SortByAlphabet( allSurnames, counter);
		Employee employees[100];
		MakeEmployeesSurnames(employees, allSurnames, counter);
		MakeEmployeesChildren(employees, allNumbers, counter, amount);
		myQuickSort(employees, amount);
		WriteInEmployees(fout, employees, counter);
	}
	catch (std::logic_error& e)
	{
		std::cout << e.what();
	}
	return 0;
}