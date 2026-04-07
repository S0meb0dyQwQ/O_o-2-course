#include "Base.h"
#include "Sorts.h"
void WorkFromConsole()
{
	std::ofstream fout("Screen.txt");
	int32_t size{ 300 };
	int32_t* digits = new int[size];
	double* snakes = new double[size];
	char* symbols = new char[size];
	std::string* words = new std::string[size];
	std::string word;
	Student* peoples = new Student[size];
	bool answer{ true };
	std::cout << "what do u want to play with?\n 1) int 2) double 3) char 4) string 5) Students\n";
	int32_t choose{};
	std::cin >> choose;
	bool sort{};
	std::cout << "Choose type of sort 1) ascending 2) descending\n";
	std::cin >> sort;
	switch (choose)
	{
	case 1:
		std::cout << " input size: ";
		std::cin >> size;
		InputArray(digits, size);
		std::cout << "do u want to touch bubble?";
		std::cin >> answer;
		if (answer)
		{
			auto start = std::chrono::high_resolution_clock::now();
			BubbleSort(digits, size, sort);
			auto end = std::chrono::high_resolution_clock::now();
			std::chrono::duration<double> time = end - start;
			std::cout << "Sort worked: " << time.count() << "seconds\n";
			WriteArray(fout, digits, size);
			fout << "Sort worked: " << time.count() << "seconds\n";
		}
		std::cout << "do u want to touch combi?";
		std::cin >> answer;
		if (answer)
		{
			auto start = std::chrono::high_resolution_clock::now();
			CombSort(digits, size, sort);
			auto end = std::chrono::high_resolution_clock::now();
			std::chrono::duration<double> time = end - start;
			std::cout << "Sort worked: " << time.count() << "seconds\n";
			WriteArray(fout, digits, size);
			fout << "Sort worked: " << time.count() << "seconds\n";
		}
		std::cout << "do u want to touch insertion?";
		std::cin >> answer;
		if (answer)
		{
			auto start = std::chrono::high_resolution_clock::now();
			InsertionSort(digits, size, sort);
			auto end = std::chrono::high_resolution_clock::now();
			std::chrono::duration<double> time = end - start;
			std::cout << "Sort worked: " << time.count() << "seconds\n";
			WriteArray(fout, digits, size);
			fout << "Sort worked: " << time.count() << "seconds\n";
		}
		std::cout << "do u want to touch selection?";
		std::cin >> answer;
		if (answer)
		{
			auto start = std::chrono::high_resolution_clock::now();
			SelectionSort(digits, size, sort);
			auto end = std::chrono::high_resolution_clock::now();
			std::chrono::duration<double> time = end - start;
			std::cout << "Sort worked: " << time.count() << "seconds\n";
			WriteArray(fout, digits, size);
			fout << "Sort worked: " << time.count() << "seconds\n";
		}
		std::cout << "do u want to touch quick?";
		std::cin >> answer;
		if (answer)
		{
			auto start = std::chrono::high_resolution_clock::now();
			QuickSort(digits, 0, size - 1, sort, size);
			auto end = std::chrono::high_resolution_clock::now();
			std::chrono::duration<double> time = end - start;
			std::cout << "Sort worked: " << time.count() << "seconds\n";
			WriteArray(fout, digits, size);
			fout << "Sort worked: " << time.count() << "seconds\n";
		}
		std::cout << "do u want to touch merge?";
		std::cin >> answer;
		if (answer)
		{
			ShowArray(digits, size);
			auto start = std::chrono::high_resolution_clock::now();
			MergeSort(digits, 0, size - 1, sort, size);
			auto end = std::chrono::high_resolution_clock::now();
			std::chrono::duration<double> time = end - start;
			std::cout << "Sort worked: " << time.count() << "seconds\n";
			WriteArray(fout, digits, size);
			fout << "Sort worked: " << time.count() << "seconds\n";
		}
		std::cout << "do u want to touch cocktail?";
		std::cin >> answer;
		if (answer)
		{
			auto start = std::chrono::high_resolution_clock::now();
			CocktailSort(digits, size, sort);
			auto end = std::chrono::high_resolution_clock::now();
			std::chrono::duration<double> time = end - start;
			std::cout << "Sort worked: " << time.count() << "seconds\n";
			WriteArray(fout, digits, size);
			fout << "Sort worked: " << time.count() << "seconds\n";
		}
		std::cout << "do u want to touch count?";
		std::cin >> answer;
		if (answer)
		{
			auto start = std::chrono::high_resolution_clock::now();
			CountSort(digits, size, sort);
			auto end = std::chrono::high_resolution_clock::now();
			std::chrono::duration<double> time = end - start;
			std::cout << "Sort worked: " << time.count() << "seconds\n";
			WriteArray(fout, digits, size);
			fout << "Sort worked: " << time.count() << "seconds\n";
		}
		std::cout << "do u want to touch boggo?";
		std::cin >> answer;
		if (answer)
		{
			auto start = std::chrono::high_resolution_clock::now();
			BogoSort(digits, size, sort);
			auto end = std::chrono::high_resolution_clock::now();
			std::chrono::duration<double> time = end - start;
			std::cout << "Sort worked: " << time.count() << "seconds\n";
			WriteArray(fout, digits, size);
			fout << "Sort worked: " << time.count() << "seconds\n";
		}
		break;
	case 2:
		std::cout << " input size: ";
		std::cin >> size;
		InputArray(snakes, size);
		std::cout << "do u want to touch bubble?";
		std::cin >> answer;
		if (answer)
		{
			auto start = std::chrono::high_resolution_clock::now();
			BubbleSort(snakes, size, sort);
			auto end = std::chrono::high_resolution_clock::now();
			std::chrono::duration<double> time = end - start;
			std::cout << "Sort worked: " << time.count() << "seconds\n";
			WriteArray(fout, snakes, size);
			fout << "Sort worked: " << time.count() << "seconds\n";
		}
		std::cout << "do u want to touch combi?";
		std::cin >> answer;
		if (answer)
		{
			auto start = std::chrono::high_resolution_clock::now();
			CombSort(snakes, size, sort);
			auto end = std::chrono::high_resolution_clock::now();
			std::chrono::duration<double> time = end - start;
			std::cout << "Sort worked: " << time.count() << "seconds\n";
			WriteArray(fout, snakes, size);
			fout << "Sort worked: " << time.count() << "seconds\n";
		}
		std::cout << "do u want to touch insertion?";
		std::cin >> answer;
		if (answer)
		{
			auto start = std::chrono::high_resolution_clock::now();
			InsertionSort(snakes, size, sort);
			auto end = std::chrono::high_resolution_clock::now();
			std::chrono::duration<double> time = end - start;
			std::cout << "Sort worked: " << time.count() << "seconds\n";
			WriteArray(fout, snakes, size);
			fout << "Sort worked: " << time.count() << "seconds\n";
		}
		std::cout << "do u want to touch selection?";
		std::cin >> answer;
		if (answer)
		{
			auto start = std::chrono::high_resolution_clock::now();
			SelectionSort(snakes, size, sort);
			auto end = std::chrono::high_resolution_clock::now();
			std::chrono::duration<double> time = end - start;
			std::cout << "Sort worked: " << time.count() << "seconds\n";
			WriteArray(fout, snakes, size);
			fout << "Sort worked: " << time.count() << "seconds\n";
		}
		std::cout << "do u want to touch quick?";
		std::cin >> answer;
		if (answer)
		{
			auto start = std::chrono::high_resolution_clock::now();
			QuickSort(snakes, 0, size - 1, sort, size);
			auto end = std::chrono::high_resolution_clock::now();
			std::chrono::duration<double> time = end - start;
			std::cout << "Sort worked: " << time.count() << "seconds\n";
			WriteArray(fout, snakes, size);
			fout << "Sort worked: " << time.count() << "seconds\n";
		}
		std::cout << "do u want to touch merge?";
		std::cin >> answer;
		if (answer)
		{
			auto start = std::chrono::high_resolution_clock::now();
			MergeSort(snakes, 0, size - 1, sort, size);
			auto end = std::chrono::high_resolution_clock::now();
			std::chrono::duration<double> time = end - start;
			std::cout << "Sort worked: " << time.count() << "seconds\n";
			WriteArray(fout, snakes, size);
			fout << "Sort worked: " << time.count() << "seconds\n";
		}
		std::cout << "do u want to touch cocktail?";
		std::cin >> answer;
		if (answer)
		{
			auto start = std::chrono::high_resolution_clock::now();
			CocktailSort(snakes, size, sort);
			auto end = std::chrono::high_resolution_clock::now();
			std::chrono::duration<double> time = end - start;
			std::cout << "Sort worked: " << time.count() << "seconds\n";
			WriteArray(fout, snakes, size);
			fout << "Sort worked: " << time.count() << "seconds\n";
		}
		std::cout << "do u want to touch boggo?";
		std::cin >> answer;
		if (answer)
		{
			auto start = std::chrono::high_resolution_clock::now();
			BogoSort(snakes, size, sort);
			auto end = std::chrono::high_resolution_clock::now();
			std::chrono::duration<double> time = end - start;
			std::cout << "Sort worked: " << time.count() << "seconds\n";
			WriteArray(fout, snakes, size);
			fout << "Sort worked: " << time.count() << "seconds\n";
		}
		break;
	case 3:
		std::cout << " input size: ";
		std::cin >> size;
		InputArray(symbols, size);
		std::cout << "do u want to touch bubble?";
		std::cin >> answer;
		if (answer)
		{
			auto start = std::chrono::high_resolution_clock::now();
			BubbleSort(symbols, size, sort);
			auto end = std::chrono::high_resolution_clock::now();
			std::chrono::duration<double> time = end - start;
			std::cout << "Sort worked: " << time.count() << "seconds\n";
			WriteArray(fout, symbols, size);
			fout << "Sort worked: " << time.count() << "seconds\n";
		}
		std::cout << "do u want to touch combi?";
		std::cin >> answer;
		if (answer)
		{
			auto start = std::chrono::high_resolution_clock::now();
			CombSort(symbols, size, sort);
			auto end = std::chrono::high_resolution_clock::now();
			std::chrono::duration<double> time = end - start;
			std::cout << "Sort worked: " << time.count() << "seconds\n";
			WriteArray(fout, symbols, size);
			fout << "Sort worked: " << time.count() << "seconds\n";
		}
		std::cout << "do u want to touch insertion?";
		std::cin >> answer;
		if (answer)
		{
			auto start = std::chrono::high_resolution_clock::now();
			InsertionSort(symbols, size, sort);
			auto end = std::chrono::high_resolution_clock::now();
			std::chrono::duration<double> time = end - start;
			std::cout << "Sort worked: " << time.count() << "seconds\n";
			WriteArray(fout, symbols, size);
			fout << "Sort worked: " << time.count() << "seconds\n";
		}
		std::cout << "do u want to touch selection?";
		std::cin >> answer;
		if (answer)
		{
			auto start = std::chrono::high_resolution_clock::now();
			SelectionSort(symbols, size, sort);
			auto end = std::chrono::high_resolution_clock::now();
			std::chrono::duration<double> time = end - start;
			std::cout << "Sort worked: " << time.count() << "seconds\n";
			WriteArray(fout, symbols, size);
			fout << "Sort worked: " << time.count() << "seconds\n";
		}
		std::cout << "do u want to touch quick?";
		std::cin >> answer;
		if (answer)
		{
			auto start = std::chrono::high_resolution_clock::now();
			QuickSort(symbols, 0, size - 1, sort, size);
			auto end = std::chrono::high_resolution_clock::now();
			std::chrono::duration<double> time = end - start;
			std::cout << "Sort worked: " << time.count() << "seconds\n";
			WriteArray(fout, symbols, size);
			fout << "Sort worked: " << time.count() << "seconds\n";
		}
		std::cout << "do u want to touch merge?";
		std::cin >> answer;
		if (answer)
		{
			auto start = std::chrono::high_resolution_clock::now();
			MergeSort(symbols, 0, size - 1, sort, size);
			auto end = std::chrono::high_resolution_clock::now();
			std::chrono::duration<double> time = end - start;
			std::cout << "Sort worked: " << time.count() << "seconds\n";
			WriteArray(fout, symbols, size);
			fout << "Sort worked: " << time.count() << "seconds\n";
		}
		std::cout << "do u want to touch cocktail?";
		std::cin >> answer;
		if (answer)
		{
			auto start = std::chrono::high_resolution_clock::now();
			CocktailSort(symbols, size, sort);
			auto end = std::chrono::high_resolution_clock::now();
			std::chrono::duration<double> time = end - start;
			std::cout << "Sort worked: " << time.count() << "seconds\n";
			WriteArray(fout, symbols, size);
			fout << "Sort worked: " << time.count() << "seconds\n";
		}
		std::cout << "do u want to touch count?";
		std::cin >> answer;
		if (answer)
		{
			auto start = std::chrono::high_resolution_clock::now();
			CountSort(symbols, size, sort);
			auto end = std::chrono::high_resolution_clock::now();
			std::chrono::duration<double> time = end - start;
			std::cout << "Sort worked: " << time.count() << "seconds\n";
			WriteArray(fout, symbols, size);
			fout << "Sort worked: " << time.count() << "seconds\n";
		}
		std::cout << "do u want to touch boggo?";
		std::cin >> answer;
		if (answer)
		{
			auto start = std::chrono::high_resolution_clock::now();
			BogoSort(symbols, size, sort);
			auto end = std::chrono::high_resolution_clock::now();
			std::chrono::duration<double> time = end - start;
			std::cout << "Sort worked: " << time.count() << "seconds\n";
			WriteArray(fout, symbols, size);
			fout << "Sort worked: " << time.count() << "seconds\n";
		}
		break;
	case 4:
		std::cout << " input size: ";
		std::cin >> size;
		std::cout << "...and input elements of array\n";
		std::cin.ignore();
		for (int32_t i{}; i < size; ++i)
		{
			getline(std::cin, word);
			words[i] = word;
		}
		std::cout << "do u want to touch bubble?";
		std::cin >> answer;
		if (answer)
		{
			auto start = std::chrono::high_resolution_clock::now();
			BubbleSort(words, size, sort);
			auto end = std::chrono::high_resolution_clock::now();
			std::chrono::duration<double> time = end - start;
			std::cout << "Sort worked: " << time.count() << "seconds\n";
			WriteArray(fout, words, size);
			fout << "Sort worked: " << time.count() << "seconds\n";
		}
		std::cout << "do u want to touch combi?";
		std::cin >> answer;
		if (answer)
		{
			auto start = std::chrono::high_resolution_clock::now();
			CombSort(words, size, sort);
			auto end = std::chrono::high_resolution_clock::now();
			std::chrono::duration<double> time = end - start;
			std::cout << "Sort worked: " << time.count() << "seconds\n";
			WriteArray(fout, words, size);
			fout << "Sort worked: " << time.count() << "seconds\n";
		}
		std::cout << "do u want to touch insertion?";
		std::cin >> answer;
		if (answer)
		{
			auto start = std::chrono::high_resolution_clock::now();
			InsertionSort(words, size, sort);
			auto end = std::chrono::high_resolution_clock::now();
			std::chrono::duration<double> time = end - start;
			std::cout << "Sort worked: " << time.count() << "seconds\n";
			WriteArray(fout, words, size);
			fout << "Sort worked: " << time.count() << "seconds\n";
		}
		std::cout << "do u want to touch selection?";
		std::cin >> answer;
		if (answer)
		{
			auto start = std::chrono::high_resolution_clock::now();
			SelectionSort(words, size, sort);
			auto end = std::chrono::high_resolution_clock::now();
			std::chrono::duration<double> time = end - start;
			std::cout << "Sort worked: " << time.count() << "seconds\n";
			WriteArray(fout, words, size);
			fout << "Sort worked: " << time.count() << "seconds\n";
		}
		std::cout << "do u want to touch quick?";
		std::cin >> answer;
		if (answer)
		{
			auto start = std::chrono::high_resolution_clock::now();
			QuickSort(words, 0, size - 1, sort, size);
			auto end = std::chrono::high_resolution_clock::now();
			std::chrono::duration<double> time = end - start;
			std::cout << "Sort worked: " << time.count() << "seconds\n";
			WriteArray(fout, words, size);
			fout << "Sort worked: " << time.count() << "seconds\n";
		}
		std::cout << "do u want to touch merge?";
		std::cin >> answer;
		if (answer)
		{
			auto start = std::chrono::high_resolution_clock::now();
			MergeSort(words, 0, size - 1, sort, size);
			auto end = std::chrono::high_resolution_clock::now();
			std::chrono::duration<double> time = end - start;
			std::cout << "Sort worked: " << time.count() << "seconds\n";
			WriteArray(fout, words, size);
			fout << "Sort worked: " << time.count() << "seconds\n";
		}
		std::cout << "do u want to touch cocktail?";
		std::cin >> answer;
		if (answer)
		{
			auto start = std::chrono::high_resolution_clock::now();
			CocktailSort(words, size, sort);
			auto end = std::chrono::high_resolution_clock::now();
			std::chrono::duration<double> time = end - start;
			std::cout << "Sort worked: " << time.count() << "seconds\n";
			WriteArray(fout, words, size);
			fout << "Sort worked: " << time.count() << "seconds\n";
		}
		std::cout << "do u want to touch boggo?";
		std::cin >> answer;
		if (answer)
		{
			auto start = std::chrono::high_resolution_clock::now();
			BogoSort(words, size, sort);
			auto end = std::chrono::high_resolution_clock::now();
			std::chrono::duration<double> time = end - start;
			std::cout << "Sort worked: " << time.count() << "seconds\n";
			WriteArray(fout, words, size);
			fout << "Sort worked: " << time.count() << "seconds\n";
		}
		break;
	case 5:
		std::cout << " input size: ";
		std::cin >> size;
		InputStudents(peoples, size);
		std::cout << "do u want to touch bubble?";
		std::cin >> answer;
		if (answer)
		{
			auto start = std::chrono::high_resolution_clock::now();
			BubbleSort(peoples, size, sort);
			auto end = std::chrono::high_resolution_clock::now();
			std::chrono::duration<double> time = end - start;
			std::cout << "Sort worked: " << time.count() << "seconds\n";
			WriteStudents(fout, peoples, size);
			fout << "Sort worked: " << time.count() << "seconds\n";
		}
		std::cout << "do u want to touch combi?";
		std::cin >> answer;
		if (answer)
		{
			auto start = std::chrono::high_resolution_clock::now();
			CombSort(peoples, size, sort);
			auto end = std::chrono::high_resolution_clock::now();
			std::chrono::duration<double> time = end - start;
			std::cout << "Sort worked: " << time.count() << "seconds\n";
			WriteStudents(fout, peoples, size);
			fout << "Sort worked: " << time.count() << "seconds\n";
		}
		std::cout << "do u want to touch insertion?";
		std::cin >> answer;
		if (answer)
		{
			auto start = std::chrono::high_resolution_clock::now();
			InsertionSort(peoples, size, sort);
			auto end = std::chrono::high_resolution_clock::now();
			std::chrono::duration<double> time = end - start;
			std::cout << "Sort worked: " << time.count() << "seconds\n";
			WriteStudents(fout, peoples, size);
			fout << "Sort worked: " << time.count() << "seconds\n";
		}
		std::cout << "do u want to touch selection?";
		std::cin >> answer;
		if (answer)
		{
			auto start = std::chrono::high_resolution_clock::now();
			SelectionSort(peoples, size, sort);
			auto end = std::chrono::high_resolution_clock::now();
			std::chrono::duration<double> time = end - start;
			std::cout << "Sort worked: " << time.count() << "seconds\n";
			WriteStudents(fout, peoples, size);
			fout << "Sort worked: " << time.count() << "seconds\n";
		}
		std::cout << "do u want to touch quick?";
		std::cin >> answer;
		if (answer)
		{
			auto start = std::chrono::high_resolution_clock::now();
			QuickSort(peoples, 0, size - 1, sort, size);
			auto end = std::chrono::high_resolution_clock::now();
			std::chrono::duration<double> time = end - start;
			std::cout << "Sort worked: " << time.count() << "seconds\n";
			WriteStudents(fout, peoples, size);
			fout << "Sort worked: " << time.count() << "seconds\n";
		}
		std::cout << "do u want to touch merge?";
		std::cin >> answer;
		if (answer)
		{
			auto start = std::chrono::high_resolution_clock::now();
			MergeSort(peoples, 0, size - 1, sort, size);
			auto end = std::chrono::high_resolution_clock::now();
			std::chrono::duration<double> time = end - start;
			std::cout << "Sort worked: " << time.count() << "seconds\n";
			WriteStudents(fout, peoples, size);
			fout << "Sort worked: " << time.count() << "seconds\n";
		}
		std::cout << "do u want to touch cocktail?";
		std::cin >> answer;
		if (answer)
		{
			auto start = std::chrono::high_resolution_clock::now();
			CocktailSort(peoples, size, sort);
			auto end = std::chrono::high_resolution_clock::now();
			std::chrono::duration<double> time = end - start;
			std::cout << "Sort worked: " << time.count() << "seconds\n";
			WriteStudents(fout, peoples, size);
			fout << "Sort worked: " << time.count() << "seconds\n";
		}
		std::cout << "do u want to touch boggo?";
		std::cin >> answer;
		if (answer)
		{
			auto start = std::chrono::high_resolution_clock::now();
			BogoSort(peoples, size, sort);
			auto end = std::chrono::high_resolution_clock::now();
			std::chrono::duration<double> time = end - start;
			std::cout << "Sort worked: " << time.count() << "seconds\n";
			WriteStudents(fout, peoples, size);
			fout << "Sort worked: " << time.count() << "seconds\n";
			break;
		}
	}
}
void WorkByRandom()
{
	int32_t size{300};
	int32_t* digits = new int[size];
	double* snakes = new double[size];
	char* symbols = new char[size];
	std::string* words = new std::string[size];
	std::string word;
	Student* peoples = new Student[size];
	bool answer{ true };
	std::cout << "what do u want to play with?\n 1) int 2) double 3) char 4) string 5) Students";
	int32_t choose{};
	std::cin >> choose;
	bool sort{};
	std::cout << "Choose type of sort 1) ascending 2) descending\n";
	std::cin >> sort;
	switch (choose)
	{
	case 1:
		std::cout << " input size: ";
		std::cin >> size;
		RandomInt(digits, size);
		std::cout << "do u want to touch bubble?";
		std::cin >> answer;
		if (answer)
		{
			auto start = std::chrono::high_resolution_clock::now();
			BubbleSort(digits, size, sort);
			auto end = std::chrono::high_resolution_clock::now();
			std::chrono::duration<double> time = end - start;
			std::cout << "Sort worked: " << time.count() << "seconds\n";
		}
		std::cout << "do u want to touch combi?";
		std::cin >> answer;
		if (answer)
		{
			auto start = std::chrono::high_resolution_clock::now();
			CombSort(digits, size, sort);
			auto end = std::chrono::high_resolution_clock::now();
			std::chrono::duration<double> time = end - start;
			std::cout << "Sort worked: " << time.count() << "seconds\n";
		}
		std::cout << "do u want to touch insertion?";
		std::cin >> answer;
		if (answer)
		{
			auto start = std::chrono::high_resolution_clock::now();
			InsertionSort(digits, size, sort);
			auto end = std::chrono::high_resolution_clock::now();
			std::chrono::duration<double> time = end - start;
			std::cout << "Sort worked: " << time.count() << "seconds\n";
		}
		std::cout << "do u want to touch selection?";
		std::cin >> answer;
		if (answer)
		{
			auto start = std::chrono::high_resolution_clock::now();
			SelectionSort(digits, size, sort);
			auto end = std::chrono::high_resolution_clock::now();
			std::chrono::duration<double> time = end - start;
			std::cout << "Sort worked: " << time.count() << "seconds\n";
		}
		std::cout << "do u want to touch quick?";
		std::cin >> answer;
		if (answer)
		{
			auto start = std::chrono::high_resolution_clock::now();
			QuickSort(digits, 0, size - 1, sort, size);
			auto end = std::chrono::high_resolution_clock::now();
			std::chrono::duration<double> time = end - start;
			std::cout << "Sort worked: " << time.count() << "seconds\n";
		}
		std::cout << "do u want to touch merge?";
		std::cin >> answer;
		if (answer)
		{
			ShowArray(digits, size);
			auto start = std::chrono::high_resolution_clock::now();
			MergeSort(digits, 0, size - 1, sort, size);
			auto end = std::chrono::high_resolution_clock::now();
			std::chrono::duration<double> time = end - start;
			std::cout << "Sort worked: " << time.count() << "seconds\n";
		}
		std::cout << "do u want to touch cocktail?";
		std::cin >> answer;
		if (answer)
		{
			auto start = std::chrono::high_resolution_clock::now();
			CocktailSort(digits, size, sort);
			auto end = std::chrono::high_resolution_clock::now();
			std::chrono::duration<double> time = end - start;
			std::cout << "Sort worked: " << time.count() << "seconds\n";
		}
		std::cout << "do u want to touch count?";
		std::cin >> answer;
		if (answer)
		{
			auto start = std::chrono::high_resolution_clock::now();
			CountSort(digits, size, sort);
			auto end = std::chrono::high_resolution_clock::now();
			std::chrono::duration<double> time = end - start;
			std::cout << "Sort worked: " << time.count() << "seconds\n";
		}
		std::cout << "do u want to touch boggo?";
		std::cin >> answer;
		if (answer)
		{
			auto start = std::chrono::high_resolution_clock::now();
			BogoSort(digits, size, sort);
			auto end = std::chrono::high_resolution_clock::now();
			std::chrono::duration<double> time = end - start;
			std::cout << "Sort worked: " << time.count() << "seconds\n";
		}
		break;
	
	case 2:
		std::cout << " input size: ";
		std::cin >> size;
		RandomDouble(snakes, size);
		std::cout << "do u want to touch bubble?";
		std::cin >> answer;
		if (answer)
		{
			auto start = std::chrono::high_resolution_clock::now();
			BubbleSort(snakes, size, sort);
			auto end = std::chrono::high_resolution_clock::now();
			std::chrono::duration<double> time = end - start;
			std::cout << "Sort worked: " << time.count() << "seconds\n";
		}
		std::cout << "do u want to touch combi?";
		std::cin >> answer;
		if (answer)
		{
			auto start = std::chrono::high_resolution_clock::now();
			CombSort(snakes, size, sort);
			auto end = std::chrono::high_resolution_clock::now();
			std::chrono::duration<double> time = end - start;
			std::cout << "Sort worked: " << time.count() << "seconds\n";
		}
		std::cout << "do u want to touch insertion?";
		std::cin >> answer;
		if (answer)
		{
			auto start = std::chrono::high_resolution_clock::now();
			InsertionSort(snakes, size, sort);
			auto end = std::chrono::high_resolution_clock::now();
			std::chrono::duration<double> time = end - start;
			std::cout << "Sort worked: " << time.count() << "seconds\n";
		}
		std::cout << "do u want to touch selection?";
		std::cin >> answer;
		if (answer)
		{
			auto start = std::chrono::high_resolution_clock::now();
			SelectionSort(snakes, size, sort);
			auto end = std::chrono::high_resolution_clock::now();
			std::chrono::duration<double> time = end - start;
			std::cout << "Sort worked: " << time.count() << "seconds\n";
		}
		std::cout << "do u want to touch quick?";
		std::cin >> answer;
		if (answer)
		{
			auto start = std::chrono::high_resolution_clock::now();
			QuickSort(snakes, 0, size - 1, sort, size);
			auto end = std::chrono::high_resolution_clock::now();
			std::chrono::duration<double> time = end - start;
			std::cout << "Sort worked: " << time.count() << "seconds\n";
		}
		std::cout << "do u want to touch merge?";
		std::cin >> answer;
		if (answer)
		{
			ShowArray(snakes, size);
			auto start = std::chrono::high_resolution_clock::now();
			MergeSort(snakes, 0, size - 1, sort, size);
			auto end = std::chrono::high_resolution_clock::now();
			std::chrono::duration<double> time = end - start;
			std::cout << "Sort worked: " << time.count() << "seconds\n";
		}
		std::cout << "do u want to touch cocktail?";
		std::cin >> answer;
		if (answer)
		{
			auto start = std::chrono::high_resolution_clock::now();
			CocktailSort(snakes, size, sort);
			auto end = std::chrono::high_resolution_clock::now();
			std::chrono::duration<double> time = end - start;
			std::cout << "Sort worked: " << time.count() << "seconds\n";
		}
		std::cout << "do u want to touch boggo?";
		std::cin >> answer;
		if (answer)
		{
			auto start = std::chrono::high_resolution_clock::now();
			BogoSort(snakes, size, sort);
			auto end = std::chrono::high_resolution_clock::now();
			std::chrono::duration<double> time = end - start;
			std::cout << "Sort worked: " << time.count() << "seconds\n";
		}
		break;
	case 3:
		std::cout << " input size: ";
		std::cin >> size;
		RandomChar(symbols, size);
		std::cout << "do u want to touch bubble?";
		std::cin >> answer;
		if (answer)
		{
			auto start = std::chrono::high_resolution_clock::now();
			BubbleSort(symbols, size, sort);
			auto end = std::chrono::high_resolution_clock::now();
			std::chrono::duration<double> time = end - start;
			std::cout << "Sort worked: " << time.count() << "seconds\n";
		}
		std::cout << "do u want to touch combi?";
		std::cin >> answer;
		if (answer)
		{
			auto start = std::chrono::high_resolution_clock::now();
			CombSort(symbols, size, sort);
			auto end = std::chrono::high_resolution_clock::now();
			std::chrono::duration<double> time = end - start;
			std::cout << "Sort worked: " << time.count() << "seconds\n";
		}
		std::cout << "do u want to touch insertion?";
		std::cin >> answer;
		if (answer)
		{
			auto start = std::chrono::high_resolution_clock::now();
			InsertionSort(symbols, size, sort);
			auto end = std::chrono::high_resolution_clock::now();
			std::chrono::duration<double> time = end - start;
			std::cout << "Sort worked: " << time.count() << "seconds\n";
		}
		std::cout << "do u want to touch selection?";
		std::cin >> answer;
		if (answer)
		{
			auto start = std::chrono::high_resolution_clock::now();
			SelectionSort(symbols, size, sort);
			auto end = std::chrono::high_resolution_clock::now();
			std::chrono::duration<double> time = end - start;
			std::cout << "Sort worked: " << time.count() << "seconds\n";
		}
		std::cout << "do u want to touch quick?";
		std::cin >> answer;
		if (answer)
		{
			auto start = std::chrono::high_resolution_clock::now();
			QuickSort(symbols, 0, size - 1, sort, size);
			auto end = std::chrono::high_resolution_clock::now();
			std::chrono::duration<double> time = end - start;
			std::cout << "Sort worked: " << time.count() << "seconds\n";
		}
		std::cout << "do u want to touch merge?";
		std::cin >> answer;
		if (answer)
		{
			ShowArray(symbols, size);
			auto start = std::chrono::high_resolution_clock::now();
			MergeSort(symbols, 0, size - 1, sort, size);
			auto end = std::chrono::high_resolution_clock::now();
			std::chrono::duration<double> time = end - start;
			std::cout << "Sort worked: " << time.count() << "seconds\n";
		}
		std::cout << "do u want to touch cocktail?";
		std::cin >> answer;
		if (answer)
		{
			auto start = std::chrono::high_resolution_clock::now();
			CocktailSort(symbols, size, sort);
			auto end = std::chrono::high_resolution_clock::now();
			std::chrono::duration<double> time = end - start;
			std::cout << "Sort worked: " << time.count() << "seconds\n";
		}
		std::cout << "do u want to touch count?";
		std::cin >> answer;
		if (answer)
		{
			auto start = std::chrono::high_resolution_clock::now();
			CountSort(symbols, size, sort);
			auto end = std::chrono::high_resolution_clock::now();
			std::chrono::duration<double> time = end - start;
			std::cout << "Sort worked: " << time.count() << "seconds\n";
		}
		std::cout << "do u want to touch boggo?";
		std::cin >> answer;
		if (answer)
		{
			auto start = std::chrono::high_resolution_clock::now();
			BogoSort(symbols, size, sort);
			auto end = std::chrono::high_resolution_clock::now();
			std::chrono::duration<double> time = end - start;
			std::cout << "Sort worked: " << time.count() << "seconds\n";
		}
		break;
	case 4:
		std::cout << " input size: ";
		std::cin >> size;
		for (int32_t i{}; i < size; ++i)
		{
			words[i] = RandomStr();
		}
		std::cout << "do u want to touch bubble?";
		std::cin >> answer;
		if (answer)
		{
			auto start = std::chrono::high_resolution_clock::now();
			BubbleSort(words, size, sort);
			auto end = std::chrono::high_resolution_clock::now();
			std::chrono::duration<double> time = end - start;
			std::cout << "Sort worked: " << time.count() << "seconds\n";
		}
		std::cout << "do u want to touch combi?";
		std::cin >> answer;
		if (answer)
		{
			auto start = std::chrono::high_resolution_clock::now();
			CombSort(words, size, sort);
			auto end = std::chrono::high_resolution_clock::now();
			std::chrono::duration<double> time = end - start;
			std::cout << "Sort worked: " << time.count() << "seconds\n";
		}
		std::cout << "do u want to touch insertion?";
		std::cin >> answer;
		if (answer)
		{
			auto start = std::chrono::high_resolution_clock::now();
			InsertionSort(words, size, sort);
			auto end = std::chrono::high_resolution_clock::now();
			std::chrono::duration<double> time = end - start;
			std::cout << "Sort worked: " << time.count() << "seconds\n";
		}
		std::cout << "do u want to touch selection?";
		std::cin >> answer;
		if (answer)
		{
			auto start = std::chrono::high_resolution_clock::now();
			SelectionSort(words, size, sort);
			auto end = std::chrono::high_resolution_clock::now();
			std::chrono::duration<double> time = end - start;
			std::cout << "Sort worked: " << time.count() << "seconds\n";
		}
		std::cout << "do u want to touch quick?";
		std::cin >> answer;
		if (answer)
		{
			auto start = std::chrono::high_resolution_clock::now();
			QuickSort(words, 0, size - 1, sort, size);
			auto end = std::chrono::high_resolution_clock::now();
			std::chrono::duration<double> time = end - start;
			std::cout << "Sort worked: " << time.count() << "seconds\n";
		}
		std::cout << "do u want to touch merge?";
		std::cin >> answer;
		if (answer)
		{
			ShowArray(words, size);
			auto start = std::chrono::high_resolution_clock::now();
			MergeSort(words, 0, size - 1, sort, size);
			auto end = std::chrono::high_resolution_clock::now();
			std::chrono::duration<double> time = end - start;
			std::cout << "Sort worked: " << time.count() << "seconds\n";
		}
		std::cout << "do u want to touch cocktail?";
		std::cin >> answer;
		if (answer)
		{
			auto start = std::chrono::high_resolution_clock::now();
			CocktailSort(words, size, sort);
			auto end = std::chrono::high_resolution_clock::now();
			std::chrono::duration<double> time = end - start;
			std::cout << "Sort worked: " << time.count() << "seconds\n";
		}
		std::cout << "do u want to touch boggo?";
		std::cin >> answer;
		if (answer)
		{
			auto start = std::chrono::high_resolution_clock::now();
			BogoSort(words, size, sort);
			auto end = std::chrono::high_resolution_clock::now();
			std::chrono::duration<double> time = end - start;
			std::cout << "Sort worked: " << time.count() << "seconds\n";
		}
		break;
	case 5:
		std::cout << " input size: ";
		std::cin >> size;
		RandomStudents(peoples, size);
		std::cout << "do u want to touch bubble?";
		std::cin >> answer;
		if (answer)
		{
			auto start = std::chrono::high_resolution_clock::now();
			BubbleSort(peoples, size, sort);
			auto end = std::chrono::high_resolution_clock::now();
			std::chrono::duration<double> time = end - start;
			std::cout << "Sort worked: " << time.count() << "seconds\n";
		}
		std::cout << "do u want to touch combi?";
		std::cin >> answer;
		if (answer)
		{
			auto start = std::chrono::high_resolution_clock::now();
			CombSort(peoples, size, sort);
			auto end = std::chrono::high_resolution_clock::now();
			std::chrono::duration<double> time = end - start;
			std::cout << "Sort worked: " << time.count() << "seconds\n";
		}
		std::cout << "do u want to touch insertion?";
		std::cin >> answer;
		if (answer)
		{
			auto start = std::chrono::high_resolution_clock::now();
			InsertionSort(peoples, size, sort);
			auto end = std::chrono::high_resolution_clock::now();
			std::chrono::duration<double> time = end - start;
			std::cout << "Sort worked: " << time.count() << "seconds\n";
		}
		std::cout << "do u want to touch selection?";
		std::cin >> answer;
		if (answer)
		{
			auto start = std::chrono::high_resolution_clock::now();
			SelectionSort(peoples, size, sort);
			auto end = std::chrono::high_resolution_clock::now();
			std::chrono::duration<double> time = end - start;
			std::cout << "Sort worked: " << time.count() << "seconds\n";
		}
		std::cout << "do u want to touch quick?";
		std::cin >> answer;
		if (answer)
		{
			auto start = std::chrono::high_resolution_clock::now();
			QuickSort(peoples, 0, size - 1, sort, size);
			auto end = std::chrono::high_resolution_clock::now();
			std::chrono::duration<double> time = end - start;
			std::cout << "Sort worked: " << time.count() << "seconds\n";
		}
		std::cout << "do u want to touch merge?";
		std::cin >> answer;
		if (answer)
		{
			auto start = std::chrono::high_resolution_clock::now();
			MergeSort(peoples, 0, size - 1, sort, size);
			auto end = std::chrono::high_resolution_clock::now();
			std::chrono::duration<double> time = end - start;
			std::cout << "Sort worked: " << time.count() << "seconds\n";
		}
		std::cout << "do u want to touch cocktail?";
		std::cin >> answer;
		if (answer)
		{
			auto start = std::chrono::high_resolution_clock::now();
			CocktailSort(peoples, size, sort);
			auto end = std::chrono::high_resolution_clock::now();
			std::chrono::duration<double> time = end - start;
			std::cout << "Sort worked: " << time.count() << "seconds\n";
		}
		std::cout << "do u want to touch boggo?";
		std::cin >> answer;
		if (answer)
		{
			auto start = std::chrono::high_resolution_clock::now();
			BogoSort(peoples, size, sort);
			auto end = std::chrono::high_resolution_clock::now();
			std::chrono::duration<double> time = end - start;
			std::cout << "Sort worked: " << time.count() << "seconds\n";
			break;
		}
		break;
	default:
		std::cout << "wrong number try again later";
	}
}
void WorkFromFile()
{
	std::ifstream fin("Resources.txt");

	int32_t size{300};

	int32_t* digits = new int[size];
	double* snakes = new double[size];
	char* symbols = new char[size];
	char* copy = new char[size];
	std::string* words = new std::string[size];
	Student* peoples = new Student[size];
	std::string word;

	bool answer{ true };

	std::cout << "what do u put in file?\n 1) int 2) double 3) char 4) string 5) Students";
	int32_t choose{};
	std::cin >> choose;

	bool sort{};
	std::cout << "Choose type of sort 1) ascending 2) descending\n";
	std::cin >> sort;

	switch (choose)
	{
	case 1:
		size = CountNum(fin);
		FillArrayFromFile(fin, digits, size);
		std::cout << "do u want to touch bubble?";
		std::cin >> answer;
		if (answer)
		{
			auto start = std::chrono::high_resolution_clock::now();
			BubbleSort(digits, size, sort);
			auto end = std::chrono::high_resolution_clock::now();
			std::chrono::duration<double> time = end - start;
			std::cout << "Sort worked: " << time.count() << "seconds\n";
		}
		std::cout << "do u want to touch combi?";
		std::cin >> answer;
		if (answer)
		{
			auto start = std::chrono::high_resolution_clock::now();
			CombSort(digits, size, sort);
			auto end = std::chrono::high_resolution_clock::now();
			std::chrono::duration<double> time = end - start;
			std::cout << "Sort worked: " << time.count() << "seconds\n";
		}
		std::cout << "do u want to touch insertion?";
		std::cin >> answer;
		if (answer)
		{
			auto start = std::chrono::high_resolution_clock::now();
			InsertionSort(digits, size, sort);
			auto end = std::chrono::high_resolution_clock::now();
			std::chrono::duration<double> time = end - start;
			std::cout << "Sort worked: " << time.count() << "seconds\n";
		}
		std::cout << "do u want to touch selection?";
		std::cin >> answer;
		if (answer)
		{
			auto start = std::chrono::high_resolution_clock::now();
			SelectionSort(digits, size, sort);
			auto end = std::chrono::high_resolution_clock::now();
			std::chrono::duration<double> time = end - start;
			std::cout << "Sort worked: " << time.count() << "seconds\n";
		}
		std::cout << "do u want to touch quick?";
		std::cin >> answer;
		if (answer)
		{
			auto start = std::chrono::high_resolution_clock::now();
			QuickSort(digits, 0, size - 1, sort, size);
			auto end = std::chrono::high_resolution_clock::now();
			std::chrono::duration<double> time = end - start;
			std::cout << "Sort worked: " << time.count() << "seconds\n";
		}
		std::cout << "do u want to touch merge?";
		std::cin >> answer;
		if (answer)
		{
			auto start = std::chrono::high_resolution_clock::now();
			ShowArray(digits, size);
			MergeSort(digits, 0, size - 1, sort, size);
			auto end = std::chrono::high_resolution_clock::now();
			std::chrono::duration<double> time = end - start;
			std::cout << "Sort worked: " << time.count() << "seconds\n";
		}
		std::cout << "do u want to touch cocktail?";
		std::cin >> answer;
		if (answer)
		{
			auto start = std::chrono::high_resolution_clock::now();
			CocktailSort(digits, size, sort);
			auto end = std::chrono::high_resolution_clock::now();
			std::chrono::duration<double> time = end - start;
			std::cout << "Sort worked: " << time.count() << "seconds\n";
		}
		std::cout << "do u want to touch count?";
		std::cin >> answer;
		if (answer)
		{
			auto start = std::chrono::high_resolution_clock::now();
			CountSort(digits, size, sort);
			auto end = std::chrono::high_resolution_clock::now();
			std::chrono::duration<double> time = end - start;
			std::cout << "Sort worked: " << time.count() << "seconds\n";
		}
		std::cout << "do u want to touch boggo?";
		std::cin >> answer;
		if (answer)
		{
			auto start = std::chrono::high_resolution_clock::now();
			BogoSort(digits, size, sort);
			auto end = std::chrono::high_resolution_clock::now();
			std::chrono::duration<double> time = end - start;
			std::cout << "Sort worked: " << time.count() << "seconds\n";
		}
		break;

	case 2:
		size = CountNum(fin);
		FillArrayFromFile(fin, snakes, size);
		std::cout << "do u want to touch bubble?";
		std::cin >> answer;
		if (answer)
		{
			auto start = std::chrono::high_resolution_clock::now();
			BubbleSort(snakes, size, sort);
			auto end = std::chrono::high_resolution_clock::now();
			std::chrono::duration<double> time = end - start;
			std::cout << "Sort worked: " << time.count() << "seconds\n";
		}
		std::cout << "do u want to touch combi?";
		std::cin >> answer;
		if (answer)
		{
			auto start = std::chrono::high_resolution_clock::now();
			CombSort(snakes, size, sort);
			auto end = std::chrono::high_resolution_clock::now();
			std::chrono::duration<double> time = end - start;
			std::cout << "Sort worked: " << time.count() << "seconds\n";
		}
		std::cout << "do u want to touch insertion?";
		std::cin >> answer;
		if (answer)
		{
			auto start = std::chrono::high_resolution_clock::now();
			InsertionSort(snakes, size, sort);
			auto end = std::chrono::high_resolution_clock::now();
			std::chrono::duration<double> time = end - start;
			std::cout << "Sort worked: " << time.count() << "seconds\n";
		}
		std::cout << "do u want to touch selection?";
		std::cin >> answer;
		if (answer)
		{
			auto start = std::chrono::high_resolution_clock::now();
			SelectionSort(snakes, size, sort);
			auto end = std::chrono::high_resolution_clock::now();
			std::chrono::duration<double> time = end - start;
			std::cout << "Sort worked: " << time.count() << "seconds\n";
		}
		std::cout << "do u want to touch quick?";
		std::cin >> answer;
		if (answer)
		{
			auto start = std::chrono::high_resolution_clock::now();
			QuickSort(snakes, 0, size - 1, sort, size);
			auto end = std::chrono::high_resolution_clock::now();
			std::chrono::duration<double> time = end - start;
			std::cout << "Sort worked: " << time.count() << "seconds\n";
		}
		std::cout << "do u want to touch merge?";
		std::cin >> answer;
		if (answer)
		{
			auto start = std::chrono::high_resolution_clock::now();
			ShowArray(snakes, size);
			MergeSort(snakes, 0, size - 1, sort, size);
			auto end = std::chrono::high_resolution_clock::now();
			std::chrono::duration<double> time = end - start;
			std::cout << "Sort worked: " << time.count() << "seconds\n";
		}
		std::cout << "do u want to touch cocktail?";
		std::cin >> answer;
		if (answer)
		{
			auto start = std::chrono::high_resolution_clock::now();
			CocktailSort(snakes, size, sort);
			auto end = std::chrono::high_resolution_clock::now();
			std::chrono::duration<double> time = end - start;
			std::cout << "Sort worked: " << time.count() << "seconds\n";
		}
		std::cout << "do u want to touch boggo?";
		std::cin >> answer;
		if (answer)
		{
			auto start = std::chrono::high_resolution_clock::now();
			BogoSort(snakes, size, sort);
			auto end = std::chrono::high_resolution_clock::now();
			std::chrono::duration<double> time = end - start;
			std::cout << "Sort worked: " << time.count() << "seconds\n";
		}
		break;
	case 3:
		size = CountSymbol(fin);
		InputSymbols(fin, symbols);
		std::cout << "do u want to touch bubble?";
		std::cin >> answer;
		if (answer)
		{
			auto start = std::chrono::high_resolution_clock::now();
			BubbleSort(symbols, size, sort);
			auto end = std::chrono::high_resolution_clock::now();
			std::chrono::duration<double> time = end - start;
			std::cout << "Sort worked: " << time.count() << "seconds\n";
		}
		std::cout << "do u want to touch combi?";
		std::cin >> answer;
		if (answer)
		{
			auto start = std::chrono::high_resolution_clock::now();
			CombSort(symbols, size, sort);
			auto end = std::chrono::high_resolution_clock::now();
			std::chrono::duration<double> time = end - start;
			std::cout << "Sort worked: " << time.count() << "seconds\n";
		}
		std::cout << "do u want to touch insertion?";
		std::cin >> answer;
		if (answer)
		{
			auto start = std::chrono::high_resolution_clock::now();
			InsertionSort(symbols, size, sort);
			auto end = std::chrono::high_resolution_clock::now();
			std::chrono::duration<double> time = end - start;
			std::cout << "Sort worked: " << time.count() << "seconds\n";
		}
		std::cout << "do u want to touch selection?";
		std::cin >> answer;
		if (answer)
		{
			auto start = std::chrono::high_resolution_clock::now();
			SelectionSort(symbols, size, sort);
			auto end = std::chrono::high_resolution_clock::now();
			std::chrono::duration<double> time = end - start;
			std::cout << "Sort worked: " << time.count() << "seconds\n";
		}
		std::cout << "do u want to touch quick?";
		std::cin >> answer;
		if (answer)
		{
			auto start = std::chrono::high_resolution_clock::now();
			QuickSort(symbols, 0, size - 1, sort, size);
			auto end = std::chrono::high_resolution_clock::now();
			std::chrono::duration<double> time = end - start;
			std::cout << "Sort worked: " << time.count() << "seconds\n";
		}
		std::cout << "do u want to touch merge?";
		std::cin >> answer;
		if (answer)
		{
			auto start = std::chrono::high_resolution_clock::now();
			ShowArray(symbols, size);
			MergeSort(symbols, 0, size - 1, sort, size);
			auto end = std::chrono::high_resolution_clock::now();
			std::chrono::duration<double> time = end - start;
			std::cout << "Sort worked: " << time.count() << "seconds\n";
		}
		std::cout << "do u want to touch cocktail?";
		std::cin >> answer;
		if (answer)
		{
			auto start = std::chrono::high_resolution_clock::now();
			CocktailSort(symbols, size, sort);
			auto end = std::chrono::high_resolution_clock::now();
			std::chrono::duration<double> time = end - start;
			std::cout << "Sort worked: " << time.count() << "seconds\n";
		}
		std::cout << "do u want to touch count?";
		std::cin >> answer;
		if (answer)
		{
			auto start = std::chrono::high_resolution_clock::now();
			CountSort(symbols, size, sort);
			auto end = std::chrono::high_resolution_clock::now();
			std::chrono::duration<double> time = end - start;
			std::cout << "Sort worked: " << time.count() << "seconds\n";
		}
		std::cout << "do u want to touch boggo?";
		std::cin >> answer;
		if (answer)
		{
			auto start = std::chrono::high_resolution_clock::now();
			BogoSort(symbols, size, sort);
			auto end = std::chrono::high_resolution_clock::now();
			std::chrono::duration<double> time = end - start;
			std::cout << "Sort worked: " << time.count() << "seconds\n";
		}
		break;
	case 4:
		size = CountWords(fin);
		InputWords(fin, words);
		std::cout << "do u want to touch bubble?";
		std::cin >> answer;
		if (answer)
		{
			auto start = std::chrono::high_resolution_clock::now();
			BubbleSort(words, size, sort);
			auto end = std::chrono::high_resolution_clock::now();
			std::chrono::duration<double> time = end - start;
			std::cout << "Sort worked: " << time.count() << "seconds\n";
		}
		std::cout << "do u want to touch combi?";
		std::cin >> answer;
		if (answer)
		{
			auto start = std::chrono::high_resolution_clock::now();
			CombSort(words, size, sort);
			auto end = std::chrono::high_resolution_clock::now();
			std::chrono::duration<double> time = end - start;
			std::cout << "Sort worked: " << time.count() << "seconds\n";
		}
		std::cout << "do u want to touch insertion?";
		std::cin >> answer;
		if (answer)
		{
			auto start = std::chrono::high_resolution_clock::now();
			InsertionSort(words, size, sort);
			auto end = std::chrono::high_resolution_clock::now();
			std::chrono::duration<double> time = end - start;
			std::cout << "Sort worked: " << time.count() << "seconds\n";
		}
		std::cout << "do u want to touch selection?";
		std::cin >> answer;
		if (answer)
		{
			auto start = std::chrono::high_resolution_clock::now();
			SelectionSort(words, size, sort);
			auto end = std::chrono::high_resolution_clock::now();
			std::chrono::duration<double> time = end - start;
			std::cout << "Sort worked: " << time.count() << "seconds\n";
		}
		std::cout << "do u want to touch quick?";
		std::cin >> answer;
		if (answer)
		{
			auto start = std::chrono::high_resolution_clock::now();
			QuickSort(words, 0, size - 1, sort, size);
			auto end = std::chrono::high_resolution_clock::now();
			std::chrono::duration<double> time = end - start;
			std::cout << "Sort worked: " << time.count() << "seconds\n";
		}
		std::cout << "do u want to touch merge?";
		std::cin >> answer;
		if (answer)
		{
			auto start = std::chrono::high_resolution_clock::now();
			ShowArray(words, size);
			MergeSort(words, 0, size - 1, sort, size);
			auto end = std::chrono::high_resolution_clock::now();
			std::chrono::duration<double> time = end - start;
			std::cout << "Sort worked: " << time.count() << "seconds\n";
		}
		std::cout << "do u want to touch cocktail?";
		std::cin >> answer;
		if (answer)
		{
			auto start = std::chrono::high_resolution_clock::now();
			CocktailSort(words, size, sort);
			auto end = std::chrono::high_resolution_clock::now();
			std::chrono::duration<double> time = end - start;
			std::cout << "Sort worked: " << time.count() << "seconds\n";
		}
		std::cout << "do u want to touch boggo?";
		std::cin >> answer;
		if (answer)
		{
			auto start = std::chrono::high_resolution_clock::now();
			BogoSort(words, size, sort);
			auto end = std::chrono::high_resolution_clock::now();
			std::chrono::duration<double> time = end - start;
			std::cout << "Sort worked: " << time.count() << "seconds\n";
		}
		break;
	case 5:
		size = CountStudent(fin);
		FillStudent(fin, peoples, size);
		std::cout << "do u want to touch bubble?";
		std::cin >> answer;
		if (answer)
		{
			auto start = std::chrono::high_resolution_clock::now();
			BubbleSort(peoples, size, sort);
			auto end = std::chrono::high_resolution_clock::now();
			std::chrono::duration<double> time = end - start;
			std::cout << "Sort worked: " << time.count() << "seconds\n";
		}
		std::cout << "do u want to touch combi?";
		std::cin >> answer;
		if (answer)
		{
			auto start = std::chrono::high_resolution_clock::now();
			CombSort(peoples, size, sort);
			auto end = std::chrono::high_resolution_clock::now();
			std::chrono::duration<double> time = end - start;
			std::cout << "Sort worked: " << time.count() << "seconds\n";
		}
		std::cout << "do u want to touch insertion?";
		std::cin >> answer;
		if (answer)
		{
			auto start = std::chrono::high_resolution_clock::now();
			InsertionSort(peoples, size, sort);
			auto end = std::chrono::high_resolution_clock::now();
			std::chrono::duration<double> time = end - start;
			std::cout << "Sort worked: " << time.count() << "seconds\n";
		}
		std::cout << "do u want to touch selection?";
		std::cin >> answer;
		if (answer)
		{
			auto start = std::chrono::high_resolution_clock::now();
			SelectionSort(peoples, size, sort);
			auto end = std::chrono::high_resolution_clock::now();
			std::chrono::duration<double> time = end - start;
			std::cout << "Sort worked: " << time.count() << "seconds\n";
		}
		std::cout << "do u want to touch quick?";
		std::cin >> answer;
		if (answer)
		{
			auto start = std::chrono::high_resolution_clock::now();
			QuickSort(peoples, 0, size - 1, sort, size);
			auto end = std::chrono::high_resolution_clock::now();
			std::chrono::duration<double> time = end - start;
			std::cout << "Sort worked: " << time.count() << "seconds\n";
		}
		std::cout << "do u want to touch merge?";
		std::cin >> answer;
		if (answer)
		{
			auto start = std::chrono::high_resolution_clock::now();
			ShowArray(peoples, size);
			MergeSort(peoples, 0, size - 1, sort, size);
			auto end = std::chrono::high_resolution_clock::now();
			std::chrono::duration<double> time = end - start;
			std::cout << "Sort worked: " << time.count() << "seconds\n";
		}
		std::cout << "do u want to touch cocktail?";
		std::cin >> answer;
		if (answer)
		{
			auto start = std::chrono::high_resolution_clock::now();
			CocktailSort(peoples, size, sort);
			auto end = std::chrono::high_resolution_clock::now();
			std::chrono::duration<double> time = end - start;
			std::cout << "Sort worked: " << time.count() << "seconds\n";
		}
		std::cout << "do u want to touch boggo?";
		std::cin >> answer;
		if (answer)
		{
			auto start = std::chrono::high_resolution_clock::now();
			BogoSort(peoples, size, sort);
			auto end = std::chrono::high_resolution_clock::now();
			std::chrono::duration<double> time = end - start;
			std::cout << "Sort worked: " << time.count() << "seconds\n";
		}
		break;
	default:
		std::cout << "wrong number try again later\n";
	}
}
void RandomInt(int32_t* digits, int32_t size) 
{
	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_int_distribution<int> dist(1, 100);
	for (int32_t i{}; i < size; ++i)
	{
		digits[i] = dist(gen);
	}
}
void RandomDouble(double* digits, int32_t size)
{
	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_real_distribution<double> dist(1, 100);
	for (int32_t i{}; i < size; ++i)
	{
		digits[i] = dist(gen);
	}
}
void RandomChar(char* digits, int32_t size)
{
	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_int_distribution<int32_t> dist(1, 255);
	for (int32_t i{}; i < size; ++i)
	{
		digits[i] = static_cast<char>(dist(gen));
	}
	digits[size] = '\0';
}
void CheckOutputFile(std::ofstream& fout)
{

	if (!fout.good())
	{
		throw  std::ios_base::failure("file doesn't exist\n");
	}
	if (!fout)
	{
		throw  std::ios_base::failure("output file error\n");
	}

}
void CheckInputFile(std::ifstream& fin)
{

	if (!fin.good())
	{
		throw std::ios_base::failure("file doesn't exist\n");
	}
	if (!fin)
	{
		throw  std::ios_base::failure("input file error\n");
	}
	if (fin.peek() == EOF)
	{
		throw  std::ios_base::failure("file is empty!\n");
	}
}
int32_t CountNum(std::ifstream& fin)
{
	int32_t counter{};
	double number{};
	while (fin >> number) {
		++counter;
	}
	return counter;
}
int32_t CountStudent(std::ifstream& fin)
{
	int32_t counter{};
	std::string word;
	while (getline(fin, word)) {
		++counter;
	}
	return counter;
}
int32_t CountSymbol(std::ifstream& fin)
{
	int32_t i{};
	char symbol;
	while (fin >> symbol) {
		++i;
	}
	return i;
}
void InputSymbols(std::ifstream& fin, char* symbols)
{
	fin.clear();
	fin.seekg(0);
	int32_t i{};
	char symbol;
	while (fin >> symbol) {
		symbols[i] = symbol;
		++i;
	}
}
int32_t CountWords(std::ifstream& fin)
{
	int32_t i{};
	std::string str;
	while (getline(fin,str,' ')) {
		++i;
	}
	return i;
}
void InputWords(std::ifstream& fin, std::string* symbols)
{
	fin.clear();
	fin.seekg(0);
	int32_t i{};
	std::string str;
	while (getline(fin, str, ' ')) {
		symbols[i] = str;
		++i;
	}
}
std::string RandomStr()
{
	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_int_distribution<int32_t> dist(1, 10);
	int32_t size{ dist(gen) };
	char* word = new char[size];
	strcpy(word, "");
	RandomChar(word, size);
	return word;
}
void RandomStudents(Student* a,  int32_t size) 
{
	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_int_distribution<int32_t> dist(1, 5);
	for (int32_t i{}; i < size; ++i) 
	{
		a[i].surname = RandomStr();
		a[i].course = dist(gen);
		a[i].group = dist(gen);
	}
}
void InputStudents(Student* a, int32_t size) 
{
	for (int32_t i{}; i < size; ++i) 
	{
		std::cout << "input course\n";
		std::cin >> a[i].course;
		std::cout << "input group\n";
		std::cin >> a[i].group;
		std::cout << "input surname\n";
		std::cin >> a[i].surname;
	}
}
void FillStudent(std::ifstream& fin, Student* a, int32_t size)
{
	fin.clear();
	fin.seekg(0, std::ios::beg);
	CheckInputFile(fin);
	std::string word;
	for (int32_t i{}; i < size; ++i)
	{
		getline(fin, a[i].surname,';');
		getline(fin, word, ';');
		a[i].group = stoi(word);
		getline(fin, word);
		a[i].course = stoi(word);
	}
}
void WriteStudents(std::ofstream& fout, Student* array, int32_t size) 
{
	for (int32_t i{}; i < size; ++i)
	{
		fout << std::setprecision(10) << array[i].surname << '\t'<< array[i].group<< array[i].course;
	}
	fout << '\n';
}
bool operator<(const Student& a, const Student& b)
{
	if (a.course == b.course)
	{
		if (a.group == b.group)
		{

			return a.group < b.group;
		}
		else
		{
			return a.surname < b.surname;
		}
		return a.course < b.course;
	}
}
bool operator>(const Student& a, const Student& b)
{
	if (a.course == b.course)
	{
		if (a.group == b.group)
		{

			return a.group > b.group;
		}
		else
		{
			return a.surname > b.surname;
		}
		return a.course > b.course;
	}
}
bool operator==(const Student& a, const Student& b)
{
	return a.course == b.course && a.group == b.group && a.surname == b.surname;
}
bool operator<<(std::ostream& out, const Student& a)
{
	out << a.surname <<';' << a.group << ';' << a.course << '\t';
	return 0;
}