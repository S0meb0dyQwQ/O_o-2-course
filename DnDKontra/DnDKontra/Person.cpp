#include "Person.h"
Person::Person():id(identifier++), race(Race::human)
{
	name = "";
	state = State::normal;
	ability_to_move = 0;
	amount_of_staff = 0;
}
Person::Person(std::string a, State b, Race c, int d, int e): id(identifier++),race(c)
{
	name = a;
	state = b;
	ability_to_move = d;
	amount_of_staff = e;
}
Person::Person(const Person& other): id(identifier++), race(other.race)
{
	name = other.name;
	state = other.state;
	ability_to_move = other.ability_to_move;
	amount_of_staff = other.amount_of_staff;
}
Person::Person(Person&& other) : id(identifier++), race(other.race)
{
	const_cast<Race&>(race) = Race::human;
	name = other.name;
	other.name = "";
	state = other.state;
	other.state = State::normal;
	ability_to_move = other.ability_to_move;
	other.ability_to_move = 0;
	amount_of_staff = other.amount_of_staff;
	other.amount_of_staff = 0;
}
Person& Person:: operator = (const Person& other)
{
	if (this != &other) 
	{
	const_cast<int&>(id) = identifier;
	identifier++;
	const_cast<Race&>(race) = other.race;
	name = other.name;
	state = other.state;
	ability_to_move = other.ability_to_move;
	amount_of_staff = other.amount_of_staff;
	}
	return *this;
}
Person& Person:: operator = (Person&& other)
{
	if (this != &other)
	{
		const_cast<int&>(id) = identifier;
		identifier++;
		const_cast<Race&>(race) = other.race;
		const_cast<Race&>(race) = Race::human;
		name = other.name;
		other.name = "";
		state = other.state;
		other.state = State::normal;
		ability_to_move = other.ability_to_move;
		other.ability_to_move = 0;
		amount_of_staff = other.amount_of_staff;
		other.amount_of_staff = 0;
	}
	return *this;
}
int Person::GetId() 
{
	return id;
}
std::string Person::GetName()
{
	return name;
}
State Person::GetState()
{
	return state;
}
Race Person::GetRace()
{
	return race;
}
int Person::GetMove()
{
	return ability_to_move;
}
int Person::GetStaff()
{
	return amount_of_staff;
}
void Person::SetName(std::string a)
{
	name = a;
}
void Person::SetState(State a)
{
	state = a;
}
void Person::SetMove(int a)
{
	ability_to_move = a;
}
void Person::SetStaff(int a)
{
	amount_of_staff = a;
}
std::ostream& operator << (std::ostream& out, Person a)
{
	
}
bool operator <(Person a, Person b)
{
	return a.name < b.name;
}