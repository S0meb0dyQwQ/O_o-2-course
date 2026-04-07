#include "Base.h"
int main()
{
	std::ifstream fin("Source.txt");
	std::vector <Word> words;
	try 
	{
		CheckFile(fin);
		std::string dividers;
		std::cout << "input dividers:\n";
		getline(std::cin, dividers);
		std::string line;
		size_t begin;
		size_t end;
		while (getline(fin, line)) 
		{
			begin = line.find_first_not_of(dividers);
			while (begin != std::string::npos)
			{
				end = line.find_first_of(dividers, begin);
				if (end == std::string::npos)
				{
					end = line.length();
				}
				std::string thing;
				thing = line.substr(begin, end - begin);
				bool here{ 0 };
				for (Word a: words)
				{
					if ( a.text == thing) 
					{
						++a.amount;
						here = 1;
						break;
					}
				}
				if(here == 0)
				{
					words.push_back(Word(thing));
				}
				begin = line.find_first_not_of(dividers, end);
			}
		}
		for (Word a : words)
		{
			std::cout << a.text << "(" << a.amount << ")" << " ";
		}

	}
	catch (std::exception& e)
	{
		std::cout << e.what();
	}
	return 0;
}