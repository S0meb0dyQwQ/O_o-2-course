#include <iostream>
#include <vector>
#include <string>
#include <fstream>
void CheckFile(std::ifstream& fin)
{
	if (!fin)
	{
		throw std::ios_base::failure("not exist");
	}
	if (fin.peek() == EOF)
	{
		throw std::ios_base::failure("is empty");
	}
}
void FulfillVector(std::ifstream& fin, std::vector<std::string>& text)
{
	std::string line;
	while (getline(fin,line,';'))
	{
		text.push_back(line);
	}
}
void PrintVector(std::vector<std::string>& text) 
{
	for (std::string line : text)
	{
		std::cout << line << '\t';
	}
	std::cout << '\n';
}
bool Compare(std::string& a, std::string& b, bool sort)
{
	if (sort == 0)
	{
		return a < b;
	}
	else 
	{
		return a > b;
	}
}
void SortVector(std::vector<std::string>& text,bool sort) 
{
	size_t size{ text.size() };
	for (size_t i{}; i < size - 1; ++i)
	{
		size_t extr_id = i;
		for (size_t j = i + 1; j < size; ++j)
		{
			if (Compare(text[j],text[extr_id],sort))
			{
				extr_id = j;
			}
		}

		if (extr_id != i)
		{
			std::swap(text[i], text[extr_id]);
		}
	}
}
void CheckForLetter(char a) 
{
	if (!isalpha(a))
	{
		throw std::invalid_argument("Это не буква\n");
	}
}
void PrintWords(std::vector<std::string>& text, char a)
{
	bool here{};
	for (std::string line : text)
	{
		if (line[0] == a)
		{
			std::cout << line << '\t';
			here = 1;
		}
	}
	if (here == 0) 
	{
		std::cout << "Таких слов нет";
	}
	std::cout << '\n';
}
void EraseWords(std::vector<std::string>& text, char a) 
{
	bool here{};
	size_t size{ text.size() };
	for (size_t i{}; i < size; ++i)
	{
		if (text[i][0] == a)
		{
			text.erase(text.begin() + i);
			--i;
			--size;
			here = 1;
		}
	}
	if (here == 0)
	{
		std::cout << "Таких слов нет\n";
	}
}
int main()
{
	try {
	setlocale(LC_ALL, "Russian");
	std::vector<std::string> text;
	std::ifstream fin("Library.txt");
	CheckFile(fin);

	FulfillVector(fin, text);

	bool sort{};
	std::cout << "Какой вектор вы предпочитаете ^(0) или v(1)\n";
	std::cin >> sort;
	std::cout << "Вот отсортированный текст\n";
	SortVector(text,sort);
	PrintVector(text);

	char symbol;
	try 
	{
		std::cout << "Слова начинающиеся с заданной буквы\n";
		std::cin >> symbol;
		CheckForLetter(symbol);
		PrintWords(text, symbol);
	}
	catch (std::invalid_argument& e)
	{
		std::cout << e.what();
	}

	try 
	{
		std::cout << "Текст без слов на заданную букву\n";
		std::cin >> symbol;
		CheckForLetter(symbol);
		EraseWords(text, symbol);
		PrintVector(text);
	}
	catch (std::invalid_argument& e)
	{
		std::cout << e.what();
	}
	}
	catch (std::ios_base::failure& e)
	{
		std::cout << e.what();
	}
	return 0;
}