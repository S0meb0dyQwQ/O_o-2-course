#include "Base.h"
void CheckFile(std::ifstream& fin)
{
	if (!fin)
	{
		throw std::exception("not exist");
	}
	if (fin.peek() == EOF)
	{
		throw std::exception("is empty");
	}
}