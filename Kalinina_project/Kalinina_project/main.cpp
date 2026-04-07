#define _CRT_SECURE_NO_WARNINGS
#include "Base.h"
#include<cstring>
#include<string>
int main()
{
	int32_t size{};

	std::cout << "input size \n";
	std::cin >> size;
	char** mtr_char = new char* [size];

	for (int32_t i{}; i < size + 1; ++i) 
	{
		mtr_char[i] = new char[300];
		strcpy(mtr_char[i], "");
		std::cin.getline(mtr_char[i], 300);
	}
	std::cin.ignore();
	int32_t* numbers = new int32_t[size];
	FindNum(mtr_char, size, numbers);
	SortNums(mtr_char, size, numbers);

	std::cout << "here is sorted words\n";
	for (int32_t i{1}; i <= size; ++i)
	{
		std::cout << mtr_char[i]<<'\n';
	}

	std::cout <<" here is summ " << CountSumm(size, numbers) << '\n';
	std::cout << "here is max " << numbers[size - 2] << '\n';
	std::cout <<"here is max " << numbers[0] << '\n';
	return 0;
}