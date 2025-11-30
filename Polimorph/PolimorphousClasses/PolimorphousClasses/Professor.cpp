#include "Professor.h"
Professor::Professor() : Person()
{
	department = new char[300];
}
Professor::Professor(char* name, char* a) : Person(name)
{
	department = new char[300];
	strcpy(department, a);
}
Professor::Professor(Professor&& other) : Person(other)
{
	strcpy(department, other.department);
	delete[]other.department;
}
Professor::Professor(const Professor& other) : Person(other)
{
	strcpy(department, other.department);
}
Professor::~Professor()
{
	fullname = nullptr;
	department = nullptr;
}
void Professor::SetDepartment(char* a)
{
	strcpy(department, a);
}
char* Professor::GetDepartment()
{
	return department;
}
void Professor::Print()
{
	std::cout << fullname << '\n' << department << '\n';
}
Professor& Professor:: operator = (const Professor& other)
{
	if (this != &other)
	{
		strcpy(fullname, other.fullname);
		strcpy(department, other.department);
	}
	return *this;
}
void MakeProfessorList(Person** people, int size)
{
	Professor* temp = new Professor[size];
	int counter = 0;
	for (int i{}; i < size; ++i)
	{
		if (Professor* ptr = dynamic_cast<Professor*>(people[i]))
		{
			temp[counter++] = *ptr;
		}
	}
	for (int i = 0; i < counter; ++i)
	{
		temp[i].Print();
	}
}
Professor MakeProfessor()
{
	char* name = new char[300];
	char* dep = new char[300];
	std::cout << "input name\n";
	std::cin.ignore();
	std::cin.getline(name, 300);
	std::cout << "input department\n";
	std::cin.getline(dep, 300);
	return Professor(name, dep);
}