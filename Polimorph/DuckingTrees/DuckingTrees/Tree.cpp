#include "Tree.h"
Tree::Tree()
{
	name = "";
	age = 0;
	type = Type::coniferous;
}
Tree::Tree(std::string a, int b, Type c)
{
	if (b < 0)
	{
		throw std::invalid_argument("age can't be less then 0");
	}
	name = a;
	age = b;
	type = c;
}
Tree::Tree(const Tree& other) 
{
	name = other.name;
	age = other.age;
	type = other.type;
}
void Tree::Print()
{
	if (type == Type::coniferous)
	{
		std::cout << name << '\n' << age << '\n'<<"coniferous\n";
	}
	else 
	{
		std::cout << name << '\n' << age << '\n' << "deciduous\n";
	}
}
Type Tree:: GetType()
{
	return type;
}
std::string Tree::GetName() 
{
	return name;
}
int Tree::GetAge()
{
	return age;
}
void Tree:: SetType(Type c)
{
	type = c;
}
void Tree:: SetName(std::string c)
{
	name = c;
}
void Tree:: SetAge(int c)
{
	age = c;
}