#include "Base.h"
int main()
{
	std::ifstream fin("in.txt");
	std::ofstream fout("out.txt");
	try {
		CheckInputFile(fin);
		CheckOutputFile(fout);
		char type;
		ChooseType(type);
		switch (type)
		{
		case '1':
		{
			int32_t size{ };
			size = CountNum(fin);
			double* array = new double[size];
			FillArrayFromFile(fin, array, size);
			std::cout << "ok, i found your array:\n";
			ShowArray(array, size);
			double* copy{ new double[size] };
			RewriteCopy(array, copy, size);
			bool sort{};
			std::cout << "u maid be in shock but u'll see 6 identical versions of sorted array\n...don't be scared\n";
			InputSortType(sort);

			std::cout << "ok, here is quick sort\n";
			QuickSort(copy, 0, size - 1, sort);
			ShowArray(copy, size);
			std::cout << "and here is insertion sort\n";
			RewriteCopy(array, copy, size);
			InsertionSort(copy, size, sort);
			ShowArray(copy, size);
			std::cout << "now it is selection sort\n";
			RewriteCopy(array, copy, size);
			SelectionSort(copy, size, sort);
			ShowArray(copy, size);
			std::cout << "Hey! here is merge sort\n";
			RewriteCopy(array, copy, size);
			MergeSort(copy, 0, size - 1, sort);
			ShowArray(copy, size);
			std::cout << "old good bubble sort (modefied)\n";
			RewriteCopy(array, copy, size);
			BubbleSort(copy, size, sort);
			ShowArray(copy, size);
			std::cout << "and finally... here is qsort(he works different)\n";
			RewriteCopy(array, copy, size);
			qsort(copy, size, sizeof(double), Compare);
			ShowArray(copy, size);
			delete[] array;
			delete[] copy;
			break;
		}
		case '2':
			try
			{
				std::cout << "ok, you want to input array by yourself, sooo...\n";
				int32_t size{};
				InputSize(size);
				double* array{ new double[size] };
				FillArray(array, size);
				double* copy{ new double[size] };
				RewriteCopy(array, copy, size);
				bool sort{};
				std::cout << "u maid be in shock but u'll see 6 identical versions of sorted array\n...don't be scared\n";
				InputSortType(sort);

				std::cout << "don't worry everything went good. Info in out.txt";
				fout << "remember your old array?\n";
				WriteArray(fout, copy, size);
				fout << "ok, here is quick sort\n";
				QuickSort(copy, 0, size - 1, sort);
				WriteArray(fout, copy, size);
				fout << "and here is insertion sort\n";
				RewriteCopy(array, copy, size);
				InsertionSort(copy, size, sort);
				WriteArray(fout, copy, size);
				fout << "now it is selection sort\n";
				RewriteCopy(array, copy, size);
				SelectionSort(copy, size, sort);
				WriteArray(fout, copy, size);
				fout << "Hey! here is merge sort\n";
				RewriteCopy(array, copy, size);
				MergeSort(copy, 0, size - 1, sort);
				WriteArray(fout, copy, size);
				fout << "old good bubble sort (modefied)\n";
				RewriteCopy(array, copy, size);
				BubbleSort(copy, size, sort);
				WriteArray(fout, copy, size);
				fout << "and finally... here is qsort(he works different)\n";
				RewriteCopy(array, copy, size);
				qsort(copy, size, sizeof(double), Compare);
				WriteArray(fout, copy, size);
				delete[] array;
				delete[] copy;
			}
			catch (std::invalid_argument& e)
			{
				std::cout << e.what();
			}
			break;
		case '3':
		{
			int32_t size{ };
			size = CountNum(fin);
			double* array = new double[size];
			FillArrayFromFile(fin, array, size);
			std::cout << "ok, i found your array:\n";
			ShowArray(array, size);
			double* copy{ new double[size] };
			RewriteCopy(array, copy, size);
			bool sort{};
			std::cout << "u maid be in shock but u'll see 6 identical versions of sorted array\n...don't be scared\n";
			InputSortType(sort);

			std::cout << "don't worry everything went good. Info in out.txt";
			fout << "remember your old array?\n";
			WriteArray(fout, copy, size);
			fout << "ok, here is quick sort\n";
			QuickSort(copy, 0, size - 1, sort);
			WriteArray(fout, copy, size);
			fout << "and here is insertion sort\n";
			RewriteCopy(array, copy, size);
			InsertionSort(copy, size, sort);
			WriteArray(fout, copy, size);
			fout << "now it is selection sort\n";
			RewriteCopy(array, copy, size);
			SelectionSort(copy, size, sort);
			WriteArray(fout, copy, size);
			fout << "Hey! here is merge sort\n";
			RewriteCopy(array, copy, size);
			MergeSort(copy, 0, size - 1, sort);
			WriteArray(fout, copy, size);
			fout << "old good bubble sort (modefied)\n";
			RewriteCopy(array, copy, size);
			BubbleSort(copy, size, sort);
			WriteArray(fout, copy, size);
			fout << "and finally... here is qsort(he works different)\n";
			RewriteCopy(array, copy, size);
			qsort(copy, size, sizeof(double), Compare);
			WriteArray(fout, copy, size);
			delete[] array;
			delete[] copy;
			break;
		}
		default:
			std::cout << "you have only 1,2 and 3 options";
		}
	}
	catch (std::ios_base::failure& e) 
	{
		std::cout << e.what();
	}
	return 0;
}