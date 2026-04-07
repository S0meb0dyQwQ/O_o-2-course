#include "ArendFootballman.h"
ArendFootballman::ArendFootballman(): Footballman()
{
	amount_of_clubs = 0;
}
ArendFootballman::ArendFootballman(char* name, Species spec, int data, int amount): Footballman(name,spec,data)
{
	amount_of_clubs = amount;
}
ArendFootballman::ArendFootballman(ArendFootballman&& other): Footballman(other)
{
	amount_of_clubs = other.amount_of_clubs;
	other.amount_of_clubs = 0;
}
ArendFootballman& ArendFootballman:: operator = (const ArendFootballman& other) 
{
	if (this != &other)
	{
	static_cast<Footballman>(*this) = other;
	amount_of_clubs = other.amount_of_clubs;
	}
	return *this;
}
ArendFootballman& ArendFootballman::operator = (ArendFootballman&& other)
{
	if (this != &other)
	{
		static_cast<Footballman>(*this) = other;
		amount_of_clubs = other.amount_of_clubs;
		other.amount_of_clubs = 0;
	}
	return *this;
}
ArendFootballman::ArendFootballman(const ArendFootballman&other) : Footballman(other)
{
	amount_of_clubs = other.amount_of_clubs;
}
ArendFootballman::~ArendFootballman()
{
	surname = nullptr;
	delete[]surname;
}
std::ostream& operator <<(std::ostream& out, ArendFootballman human)
{
	return out << static_cast<Footballman>(human) << '\n' << "Amount of clubs: " << human.amount_of_clubs;
}
void ArendFootballman::SetAmount(int amount) 
{
	amount_of_clubs = amount;
}
int ArendFootballman::GetAmount()
{
	return amount_of_clubs;
}