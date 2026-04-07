#include "Base.h"
#include <iostream>
int32_t CountNumbers(std::ifstream& fin, int32_t& a)
{
	int32_t number{};
	while (fin >> number) 
	{
		++a;
	}
	return a;
}
std::string MakeArray(std::ifstream& fin) 
{
	std::string delims;
    std::string word;
    std::string numbers;
	getline(fin, delims);
	std::string line;
    while (getline(fin, line))
    {
        size_t begin{};
        size_t end{};
        begin = line.find_first_not_of(delims);
        while (begin != std::string::npos)
        {
            end = line.find_first_of(delims, begin);
            if (end == std::string::npos)
            {
                end = line.length();
            }
            word = line.substr(begin, end - begin);
            numbers = MakeStrNumbers(word, numbers);
            begin = line.find_first_not_of(delims, end);
        }
    }
    return numbers;
}
void FillArray(std::ifstream& fin, int32_t array[], int32_t& amount)
{
    std::string numbers;
    numbers = MakeArray(fin);
    if (!HaveNumbers(numbers)) 
    {
        throw std::logic_error("there is no numbers");
    }
        size_t begin{};
        size_t end{};
        begin = numbers.find_first_not_of(" ");
        while (begin != std::string::npos)
        {
            end = numbers.find_first_of(" ", begin);
            if (end == std::string::npos)
            {
                end = numbers.length();
            }
            array[amount++] = stoi(numbers.substr(begin, end - begin));
            begin = numbers.find_first_not_of(" ", end);
        }
}
bool HaveNumbers(std::string numbers)
{
    size_t n{ numbers.length() };
    const char* str{ numbers.c_str() };
    for (size_t i{}; i < n; ++i)
    {
        if (!isspace(str[i]))
        {
            return true;
        }
    }
    return false;
}
std::string MakeStrNumbers(std::string a, std::string& numb) 
{
   size_t n{ a.length() };
   const char* str{ a.c_str() };
    for (size_t i{}; i < n; ++i) 
    {
        if (isdigit(a[i]))
        {
            numb.push_back(a[i]);
        }
    }
    numb += " ";
    return numb;
}
void MakeCopy(int32_t* array, int32_t* copy, int32_t amount)
{
    for (int32_t i{}; i < amount; ++i) 
    {
        copy[i] = array[i];
    }
}
void SortCopy(int32_t* copy, int32_t amount)
{
    bool no_swap{ true };
    for (int32_t i{}; i < amount ; ++i)
    {
        for (int32_t j{}; j < amount - 1 - i; ++j)
        {
            if (copy[j] % 2 == 1 && copy[j + 1] % 2 == 0) 
            {
                std::swap(copy[j], copy[j + 1]);
                no_swap = false;
            }
        }
        if (no_swap)
        {
            break;
        }
        no_swap = true;
    }
}
void MakeSurnames(std::ifstream& fin, std::string* allSurnames, int32_t& counter)
{
    std::string delims;
    getline(fin, delims);
    std::string str;
    std::string word;
    while (getline(fin, str))
    {
        size_t begin{};
        size_t end{};
        begin = str.find_first_not_of(delims);
        while (begin != std::string::npos)
        {
            end = str.find_first_of(delims, begin);
            if (end == std::string::npos)
            {
                end = str.length();
            }
            word = str.substr(begin, end - begin);
            if (IsLetter(word)) 
            {
                allSurnames[counter++] = word;
            }
            begin = str.find_first_not_of(delims, end);
        }
    }
}
bool IsLetter(std::string a) 
{
    size_t n{ a.length() };
    const char* str{ a.c_str() };
    for (size_t i{}; i < n; ++i)
    {
        if (!isalpha(str[i]))
        {
            return false;
        }
    }
    return true;
}
void HaveWords(std::string* allSurnames)
{
    if (allSurnames[0] == "")
    {
        throw std::logic_error(" input some words pls next time");
    }
}
void SortByAlphabet(std::string* allSurnames, int32_t counter) 
{
    for (int32_t i{}; i < counter; ++i)
    {
        for (int32_t j{}; j < counter - 1 - i; ++j)
        {
            if (allSurnames[j] > allSurnames[j + 1]) 
            {
                std::swap(allSurnames[j], allSurnames[j + 1]);
            }
        }
    }
    for (int32_t i{}; i < counter; ++i)
    {
        std::cout << allSurnames[i] << " ";
    }
}
void MakeEmployeesSurnames(Employee* a,std::string* surnames, int32_t counter)
{
    for (int32_t i{}; i < counter; ++i)
    {
        a[i].surname = surnames[i];
    }
}
void MakeEmployeesChildren(Employee* a, int32_t* numbers, int32_t counter, int32_t amount)
{
    int32_t number{1};
    int32_t j{};
    for (int32_t i{}; i < amount; ++i)
    {
        if(numbers[i] < 10 && numbers[i] > 0)
        {
            a[j].children = numbers[i];
            ++j;
        }
    }
    for (j; j < counter; ++j)
    {
        std::cin >> number;
        if (number >= 10 || number <= 0) 
        {
            std::cout << "govno number. 0 < number < 10\n";
            --j;
        }
    }
}
void WriteInEmployees(std::ofstream& fout, Employee* a, int32_t counter) 
{
    for (int32_t i{}; i < counter; ++i)
    {
        fout << a[i].surname << "; " << a[i].children << '\n';
    }
}