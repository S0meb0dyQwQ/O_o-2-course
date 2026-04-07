#ifndef BASE_H
#define BASE_H
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include <random>
#include "Sorts.h"
struct Student 
{
	int32_t course{};
	int32_t group{};
	std::string surname;
};
bool operator<(const Student& a, const Student& b);
bool operator>(const Student& a, const Student& b);
bool operator==(const Student& a, const Student& b);
bool operator<<(std::ostream& out, const Student& a);
template<typename T>
void InputArray(T* a, int32_t size)
{
	std::cout << "...and input elements of array\n";
	for (int32_t i{}; i < size; ++i)
	{
		std::cin >> a[i];
	}
}
template<typename T>
void FillArrayFromFile(std::ifstream& fin, T* numbers, int32_t size) {
	fin.clear();
	fin.seekg(0);
	for (int32_t i{}; i < size; ++i) {
		fin >> numbers[i];
	}
}
void WorkFromConsole();
void WorkByRandom();
void WorkFromFile();
void RandomInt(int32_t*, int32_t);
void RandomDouble(double*, int32_t);
void RandomChar(char*, int32_t);
void CheckOutputFile(std::ofstream& fout);
void CheckInputFile(std::ifstream& fin);
int32_t CountNum(std::ifstream& fin);
int32_t CountSymbol(std::ifstream& fin);
void InputSymbols(std::ifstream& fin, char* symbols);
int32_t CountWords(std::ifstream& fin);
void InputWords(std::ifstream& fin, std::string* symbols);
void InputStudents(Student*, int32_t);
void WriteStudents(std::ofstream& fout, Student*, int32_t);
std::string RandomStr();
void RandomStudents(Student*, int32_t );
int32_t CountStudent(std::ifstream& fin);
void FillStudent(std::ifstream& fin, Student* a, int32_t size);
#endif