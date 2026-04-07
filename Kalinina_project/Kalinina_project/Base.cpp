#define _CRT_SECURE_NO_WARNINGS
#include "Base.h"
void FindNum(char** mtr_char, int32_t size, int32_t* numbers) 
{
	for (int32_t i{ 1}; i <= size; ++i)
	{
		char* copy = new char[strlen(mtr_char[i]) + 1];
		strcpy(copy, mtr_char[i]);
		char* token = strtok(copy, " ");
		char* num = new char[strlen(mtr_char[i]) + 1];
		strcpy(num, "");
		token = strtok(NULL, " ");
		strcpy(num, token);
		numbers[i - 1] = atoi(num);
	}
}
void SortNums(char** mtr_char, int32_t size, int32_t* numbers)
{
	bool no_swap{ true };
	for (int32_t i{}; i < size; ++i)
	{
		for (int32_t k{}; k < size - i - 1; ++i)
		{
			if (numbers[k] > numbers[k + 1])
			{
				std::swap(numbers[k], numbers[k + 1]);
				std::swap(mtr_char[k + 1], mtr_char[k + 2]);
				no_swap = false;
			}
		}
		if (no_swap)
		{
			break;
		}
	}
}
int32_t CountSumm(int32_t size, int32_t* numbers) 
{
	int32_t summ{};
	for (int32_t i{}; i < size; ++i)
	{
		summ += numbers[i];
	}
	return summ;
}