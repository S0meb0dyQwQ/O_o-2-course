#include "Footballman.h"
#include "ArendFootballman.h"
//Kalinina
int main() 
{
	Footballman a;
	char* surname = new char[10];
	std::cin.getline(surname, 10);
	Footballman b{ surname, Species::vratar, 2029 };
	std::cin.getline(surname, 10);
	ArendFootballman c{ surname, Species::atacker, 2029, 3 };
	std::cin.getline(surname, 10);
	ArendFootballman d{ surname, Species::atacker, 2028, 1 };
	if (c == d) 
	{
		std::cout << "they all are atacker\n";
	}
	else 
	{
		std::cout << "not an atacker\n";
	}
	std::cout << b;
	Footballman** array = new Footballman * [4];
	array[0] = new Footballman(a);
	array[1] = new Footballman{ surname, Species::vratar, 2030};
	array[2] = &c;
	array[3] = new ArendFootballman;
	CountSpecies(array);
	return 0;
}