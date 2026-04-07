#ifndef BASE_H
#define BASE_H
#include <string>
#include <cstring>
#include <fstream>
#include <cstdlib>
struct Employee 
{
	std::string surname;
	int32_t children{};
};
int32_t CountNumbers(std::ifstream&, int32_t&);
std::string MakeArray(std::ifstream& fin);
std::string MakeStrNumbers(std::string a, std::string& numb);
void FillArray(std::ifstream& fin, int32_t array[], int32_t& amount);
bool HaveNumbers(std::string numbers);
void MakeCopy(int32_t* array,int32_t* , int32_t amount);
void SortCopy(int32_t*, int32_t amount);
void MakeSurnames(std::ifstream& fin, std::string* allSurnames, int32_t& counter);
bool IsLetter(std::string a);
void HaveWords(std::string*);
template <class T>
void myQuickSort(T* a, int32_t n)
{
	
}
template <class T>
size_t FindTypeOfSort(T* a, int32_t n) 
{
	for (int32_t i{}; i < n; ++i)
	{
		if (a[i] > a[i + 1])
		{
			return 1;
		}
		else if (a[i] < a[i + 1]) 
		{
			return 2;
		}
	}
	return 0;
}

int CompareDown(const void* a, const void* b)
{
	return *((std::string*)b) - *((std::string*)a);
}

int CompareUp(const void* a, const void* b)
{
	return *((T*)a) - *((T*)b);
}
void SortByAlphabet(std::string* allSurnames, int32_t counter);
void MakeEmployeesSurnames(Employee* a, std::string* surnames, int32_t counter);
void MakeEmployeesChildren(Employee* a, int32_t* numbers, int32_t counter, int32_t amount);
void WriteInEmployees(std::ofstream&, Employee*, int32_t);
#endif