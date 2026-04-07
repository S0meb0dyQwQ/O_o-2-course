#include "Base.h"
void ChooseType(char& type)
{
	std::cout << "choose: \n1) file -> console\n2) console -> file\n3) file -> file\n";
	std::cin >> type;
}
void InputSize(int32_t& size) 
{
	std::cout << "input size\n";
	std::cin >> size;
	if (size <= 0) 
	{
		throw std::invalid_argument("too small for array");
	}
}
void FillArray(double*& array, int32_t size)
{
	std::cout << "...and input elements of array\n";
	for (int32_t i{}; i < size; ++i) 
	{
		std::cin >> array[i];
	}
}
void RewriteCopy(double* array,double*& copy, int32_t size)
{
	for (int32_t i{}; i < size; ++i)
	{
		copy[i] = array[i];
	}
}
void InputSortType(bool& a)
{
	std::cout << "by the way, do you want to sort ascending(1) or descending(0)?\n";
	std::cin >> a;
}
void BubbleSort(double*& a, int32_t n, bool sort) 
{
	bool swap{ false };
	if (sort)
	{
		for (int32_t i{}; i < n; ++i)
		{
			for (int32_t j{}; j < n - i - 1; ++j)
			{
				if (a[j] > a[j + 1])
				{
					std::swap(a[j], a[j + 1]);
					swap = true;
				}
			}
			if (!swap)
			{
				break;
			}
		}
	}
	else
	{
		for (int32_t i{}; i < n; ++i)
		{
			for (int32_t j{}; j < n - i - 1; ++j)
			{
				if (a[j] < a[j + 1])
				{
					std::swap(a[j], a[j + 1]);
					swap = true;
				}
			}
			if (!swap)
			{
				break;
			}
		}
	}
}

int32_t FindSmallestPositionFromBeginning(double* a, int32_t i, int32_t n)
{
	int32_t position{ i };
	for (int32_t k{ i }; k < n; ++k)
	{
		if (a[k] < a[position])
			position = k;
	}
	return position;
}
int32_t FindSmallestPositionFromEnd(double* a, int32_t i, int32_t n)
{
	int32_t position{ i };
	for (int32_t k{ 0 }; k <= i; ++k)
	{
		if (a[k] < a[position])
			position = k;
	}
	return position;
}
void SelectionSort(double*& a, int32_t n, bool sort)
{
	if (sort)
	{
		for (int32_t i{ 0 }; i < n; ++i)
		{
			int32_t small_position{ FindSmallestPositionFromBeginning(a, i, n) };
			std::swap(a[i], a[small_position]);
		}
	}
	else 
	{
		for (int32_t i{ n - 1 }; i >= 0; --i)
		{
			int32_t small_position{ FindSmallestPositionFromEnd(a, i, n) };
			std::swap(a[i], a[small_position]);
		}
	}
}

void InsertionSort(double*& a, int32_t n, bool sort)
{
	if (sort)
	{
		for (int32_t i = 1; i < n; i++)
		{
			int32_t j = i - 1;
			while (j >= 0 && a[j] > a[j + 1])
			{
				std::swap(a[j], a[j + 1]);
				j--;
			}
		}
	}
	else
	{
		for (int32_t i = 1; i < n; i++)
		{
			int32_t j = i - 1;
			while (j >= 0 && a[j] < a[j + 1])
			{
				std::swap(a[j], a[j + 1]);
				j--;
			}
		}
	}
}

int32_t Separate(double* a, int32_t start, int32_t sup_elem, bool sort)
{
	if (sort)
	{
		int32_t i = start;
		while (i < sup_elem)
		{
			if (a[i] > a[sup_elem] && i == sup_elem - 1)
			{
				std::swap(a[i], a[sup_elem]);
				sup_elem--;
			}
			else if (a[i] > a[sup_elem])
			{
				std::swap(a[sup_elem - 1], a[sup_elem]);
				std::swap(a[i], a[sup_elem]);
				sup_elem--;
			}
			else
			{
				i++;
			}
		}
	}
	else 
	{
		int32_t i = start;
		while (i < sup_elem)
		{
			if (a[i] < a[sup_elem] && i == sup_elem - 1)
			{
				std::swap(a[i], a[sup_elem]);
				sup_elem--;
			}
			else if (a[i] < a[sup_elem])
			{
				std::swap(a[sup_elem - 1], a[sup_elem]);
				std::swap(a[i], a[sup_elem]);
				sup_elem--;
			}
			else
			{
				i++;
			}
		}
	}
	return sup_elem;
}
void QuickSort(double*& a, int32_t start, int32_t end, bool sort)
{
	if (start < end)
	{
		int32_t sup_elem = Separate(a, start, end, sort);

		QuickSort(a, start, sup_elem - 1, sort);
		QuickSort(a, sup_elem + 1, end, sort);
	}
}

void MergeSort(double*& a, int32_t start, int32_t end, bool sort)
{
	int32_t mid{};
	if (start < end) 
	{

		mid = (start + end) / 2;
		MergeSort(a, start, mid, sort);
		MergeSort(a, mid + 1, end, sort);
		Merge(a, start, end, mid, sort);
	}
}
void Merge(double*& a, int32_t start, int32_t end, int32_t mid, bool sort)
{
	double* merge_array{new double [end + 1]};
	int32_t i{ start };
	int32_t k{ start };
	int32_t j{ mid + 1 };
	if (sort) {
		while (i <= mid && j <= end)
		{
			if (a[i] < a[j]) 
			{
				merge_array[k] = a[i];
				k++;
				i++;
			}
			else
			{
				merge_array[k] = a[j];
				k++;
				j++;
			}
		}

		while (i <= mid) 
		{
			merge_array[k] = a[i];
			k++;
			i++;
		}

		while (j <= end)
		{
			merge_array[k] = a[j];
			k++;
			j++;
		}

		for (i = start; i < k; i++)
		{
			a[i] = merge_array[i];
		}
	}
	else 
	{
		while (i <= mid && j <= end)
		{
			if (a[i] > a[j])
			{
				merge_array[k] = a[i];
				k++;
				i++;
			}
			else
			{
				merge_array[k] = a[j];
				k++;
				j++;
			}
		}

		while (i <= mid)
		{
			merge_array[k] = a[i];
			k++;
			i++;
		}

		while (j <= end)
		{
			merge_array[k] = a[j];
			k++;
			j++;
		}

		for (i = start; i < k; i++)
		{
			a[i] = merge_array[i];
		}
	}
}

int Compare(const void* a, const void* b)
{
	return CountDigitAfterDot(*((double*)b)) - CountDigitAfterDot(*((double*)a));
}
size_t CountDigitAfterDot(double d)
{
	std::string number{ std::to_string(d) };
	size_t begin{ number.find_first_of('.') + 1 };
	size_t end{};
	size_t counter{};
	while (begin != std::string::npos)
	{
		end = number.find_first_of('0', begin);
		if (end == std::string::npos)
		{
			end = number.length();
		}
		counter += end - begin;
		begin = number.find_first_not_of('0', end);
	}
	return counter;
}
void ShowArray(double* array, int32_t size)
{
	for (int32_t i{}; i < size; ++i)
	{
		std::cout << std::setprecision(10)<< array[i]<< '\t';
	}
	std::cout << '\n';
}