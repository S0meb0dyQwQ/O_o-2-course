#ifndef BASE_H
#define BASE_H
#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <exception>
struct Word
{
	std::string text;
	size_t amount;
	Word(std::string a) : text(a), amount(1) {}
};
void CheckFile(std::ifstream&);
#endif