#include "Person.h"
Person::Person()
{
	fullname = new char[300];
}
Person::Person(char* name)
{
	fullname = new char[300];
	strcpy(fullname, name);
}
Person::Person(Person&& other)
{
	strcpy(fullname, other.fullname);
	/*strcpy(other.fullname, "");*/
	delete[]other.fullname;
}
Person::Person(const Person& other)
{
	strcpy(fullname, other.fullname);
}
Person::~Person()
{
	fullname = nullptr;
}
void Person::SetName(char* name)
{
	strcpy(fullname, name);
}
char* Person::GetName() 
{
	return fullname;
}
void Person:: Print() 
{
	std::cout << fullname << '\n';
}
Person& Person:: operator = (const Person& other)
{
	if (this != &other)
	{
		strcpy(fullname, other.fullname);
	}
	return *this;
}