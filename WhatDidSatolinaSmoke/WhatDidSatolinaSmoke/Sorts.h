#ifndef SORTS_H
#define SORTS_H
#include "Base.h"
#include <ctime>
#include <chrono>
template<typename T>
void WriteArray(std::ofstream& fout, T* array, int32_t size)
{
	for (int32_t i{}; i < size; ++i)
	{
		fout << std::setprecision(10) << array[i] << '\t';
	}
	fout << '\n';
}
template<typename T>
void ShowArray(T* array, int32_t size)
{
	for (int32_t i{}; i < size; ++i)
	{
		std::cout << std::setprecision(10) << array[i] << '\t';
	}
	std::cout << '\n';
}
template <typename T>
void BubbleSort(T* a, int32_t size, bool sort)
{
	ShowArray(a, size);
	bool swap{ false };
	if (sort)
	{
		for (int32_t i{}; i < size; ++i)
		{
			swap = false;
			for (int32_t j{}; j < size - i - 1; ++j)
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
			ShowArray(a, size);
		}
		ShowArray(a, size);
	}
	else
	{
		for (int32_t i{}; i < size; ++i)
		{
			for (int32_t j{}; j < size - i - 1; ++j)
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
			ShowArray(a, size);
		}
		ShowArray(a, size);
	}
}

template <typename T>
void CombSort(T* a, int32_t size, bool sort)
{
	ShowArray(a, size);
	int32_t step{ size *4/5};
	bool swap{ false };
	if (sort)
	{
		while (step > 1 || swap) {
			if (step < 1)
			{
				step = 1;
				swap = false;
			}
			for (int32_t i{}; i + step < size; ++i)
			{
					if (a[i] > a[i + step])
					{
						std::swap(a[i], a[i + step]);
						swap = true;
					}
			}
			ShowArray(a, size);
			step = step *4/5;
		}
	}
	else
	{
		while (step > 1 || swap) {
			if (step < 1)
			{
				step = 1;
				swap = false;
			}
			for (int32_t i{}; i + step < size; ++i)
			{
				if (a[i] < a[i + step])
				{
					std::swap(a[i], a[i + step]);
					swap = true;
				}
			}
			ShowArray(a, size);
			step = step * 4 / 5;
		}
	}
}
template<typename T>
void InsertionSort(T* a, int32_t size, bool sort)
{
	ShowArray(a, size);
	for (int32_t i{ 1 }; i < size; i++)
	{
		int32_t j{ i - 1 };
		if (sort)
		{
			while (j >= 0 && a[j] > a[j + 1])
			{
				std::swap(a[j], a[j + 1]);
				--j;
				ShowArray(a, size);
			}
		}
		else
		{
			while (j >= 0 && a[j] < a[j + 1])
			{
				std::swap(a[j], a[j + 1]);
				--j;
				ShowArray(a, size);
			}
		}
	}
}
template<typename T>
int32_t FindSmalFromBegin(T* a, int32_t i, int32_t n)
{
	int32_t position{ i };
	for (int32_t k{ i }; k < n; ++k)
	{
		if (a[k] < a[position])
			position = k;
	}
	return position;
}
template<typename T>
int32_t FindSmalFromEnd(T* a, int32_t i, int32_t n)
{
	int32_t position{ i };
	for (int32_t k{}; k <= i; ++k)
	{
		if (a[k] < a[position])
			position = k;
	}
	return position;
}
template<typename T>
void SelectionSort(T* a, int32_t size, bool sort)
{
	ShowArray(a, size);
	if (sort)
	{
		for (int32_t i{ 0 }; i < size; ++i)
		{
			int32_t small_position{ FindSmalFromBegin(a, i, size) };
			std::swap(a[i], a[small_position]);
			ShowArray(a, size);
		}
	}
	else
	{
		for (int32_t i{ size - 1 }; i >= 0; --i)
		{
			int32_t small_position{ FindSmalFromEnd(a, i, size) };
			std::swap(a[i], a[small_position]);
			ShowArray(a, size);
		}
	}
}
template<typename T>
int32_t Divide(T* a, int32_t start, int32_t sup_elem, bool sort)
{
	int32_t i{ start };
	if (sort)
	{
		while (i < sup_elem)
		{
			if (a[i] > a[sup_elem] && i == sup_elem - 1)
			{
				std::swap(a[i], a[sup_elem]);
				--sup_elem;
			}
			else if (a[i] > a[sup_elem])
			{
				std::swap(a[sup_elem - 1], a[sup_elem]);
				std::swap(a[i], a[sup_elem]);
				--sup_elem;
			}
			else
			{
				++i;
			}
		}
	}
	else
	{
		while (i < sup_elem)
		{
			if (a[i] < a[sup_elem] && i == sup_elem - 1)
			{
				std::swap(a[i], a[sup_elem]);
				--sup_elem;
			}
			else if (a[i] < a[sup_elem])
			{
				std::swap(a[sup_elem - 1], a[sup_elem]);
				std::swap(a[i], a[sup_elem]);
				--sup_elem;
			}
			else
			{
				++i;
			}
		}
	}
	return sup_elem;
}
template<typename T>
void QuickSort(T* a, int32_t start, int32_t end, bool sort, int32_t size)
{
	if (start < end)
	{
		int32_t sup_elem = Divide(a, start, end, sort);;
		ShowArray(a, size);
		QuickSort(a, start, sup_elem - 1, sort, size);
		QuickSort(a, sup_elem + 1, end, sort, size);
	}
}
template<typename T>
void Merge(T* a, int32_t start, int32_t end, int32_t mid, bool sort)
{
	T* merge_array{ new T[end + 1] };
	int32_t i{ start };
	int32_t k{ start };
	int32_t j{ mid + 1 };
	if (sort) {
		while (i <= mid && j <= end)
		{
			if (a[i] < a[j])
			{
				merge_array[k++] = a[i++];
			}
			else
			{
				merge_array[k++] = a[j++];
			}
		}

		while (i <= mid)
		{
			merge_array[k++] = a[i++];
		}

		while (j <= end)
		{
			merge_array[k++] = a[j++];
		}

		for (i = start; i < k; ++i)
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
				merge_array[k++] = a[i++];
			}
			else
			{
				merge_array[k++] = a[j++];
			}
		}

		while (i <= mid)
		{
			merge_array[k++] = a[i++];
		}

		while (j <= end)
		{
			merge_array[k++] = a[j++];
		}

		for (i = start; i < k; ++i)
		{
			a[i] = merge_array[i];
		}
	}
}
template<typename T>
void MergeSort(T* a, int32_t start, int32_t end, bool sort, int32_t size)
{
	int32_t mid{};
	if (start < end)
	{

		mid = (start + end) / 2;
		MergeSort(a, start, mid, sort, size);
		MergeSort(a, mid + 1, end, sort, size);
		Merge(a, start, end, mid, sort);
		ShowArray(a, size);
	}
}
template<typename T>
void CocktailSort(T* a, int32_t size, bool sort)
{
	ShowArray(a, size);
	int32_t left{};
	int32_t right{ size };
	bool swap{ true };
	if (sort) {
		while (swap)
		{
			swap = false;
			for (int32_t i{ left }; i < right - 1; ++i)
			{
				if (a[i] > a[i + 1])
				{
					std::swap(a[i], a[i + 1]);
					swap = true;
				}
			}
			ShowArray(a, size);
			--right;
			for (int32_t i{ right }; i > left; --i)
			{
				if (a[i] < a[i - 1])
				{
					std::swap(a[i], a[i - 1]);
					swap = true;
				}
			}
			++left;
			ShowArray(a, size);
		}
	}
	else
	{
		while (swap)
		{
			swap = false;
			for (int32_t i{ left }; i < right - 1; ++i)
			{
				if (a[i] < a[i + 1])
				{
					std::swap(a[i], a[i + 1]);
					swap = true;
				}
			}
			ShowArray(a, size);
			--right;
			for (int32_t i{ right }; i > left; --i)
			{
				if (a[i] > a[i - 1])
				{
					std::swap(a[i], a[i - 1]);
					swap = true;
				}
			}
			ShowArray(a, size);
			++left;
		}
	}
}
template <typename T>
T FindMin(T* a, int32_t size)
{
	T min = a[0];
	for (int32_t i{}; i < size; ++i) 
	{
		if (a[i] < min)
		{
			min = a[i];
		}
	}
	return min;
}
template <typename T>
T FindMax(T* a, int32_t size)
{
	T max = a[0];
	for (int32_t i{}; i < size; ++i)
	{
		if (a[i] > max)
		{
			max = a[i];
		}
	}
	return max;
}
template <typename T>
void CountSort(T*& a, int32_t size, bool sort)
{
	ShowArray(a, size);
	T min{ FindMin(a,size) };
	T max{ FindMax(a,size) };
	int32_t range{ static_cast<int32_t>(max) + 1 };
	T* counter = new T[range];
	for (int32_t i{}; i < range; ++i)
	{
		counter[i] = 0;
	}
	for (int32_t i{}; i < size; ++i)
	{
		counter[static_cast<int32_t>(a[i])]++;
	}
	int32_t k{};
	if (sort) {
		for (int32_t i{}; i < range; ++i)
		{
			while (counter[i] > 0)
			{
				--counter[i];
				a[k++] = i;
				ShowArray(a, size);
			}
		}
	}
	else
	{
		for (int32_t i{range - 1}; i > 0; --i)
		{
			while (counter[i] > 0)
			{
				--counter[i];
				a[k++] = i ;
				ShowArray(a, size);
			}
		}
	}
}
template <class T>
bool IsSorted(T* arr, int32_t size)
{
	for (int32_t i{ 1 }; i < size; ++i) 
	{
		if (arr[i - 1] > arr[i])
		{
			return false;
		}
	}
	return true;
}
template <class T>
void ShuffleElements(T* arr, int32_t size)
{
	int32_t j{};
	T temp{};

	for (int32_t i{}; i < size; ++i)
	{
		j = rand() % size;
		temp = arr[i];
		arr[i] = arr[j];
		arr[j] = temp;
	}
}
template <class T>
void BogoSort(T* arr, int32_t size, bool sort)
{
	if (sort) 
	{
		srand(static_cast<unsigned>(time(0)));
		ShowArray(arr, size);
		while (!IsSorted(arr, size))
		{
			ShuffleElements(arr, size);
			ShowArray(arr, size);
		}
	}
	else
	{
		srand(static_cast<unsigned>(time(0)));
		ShowArray(arr, size);
		while (IsSorted(arr, size))
		{
			ShuffleElements(arr, size);
			ShowArray(arr, size);
		}
	}
}
#endif