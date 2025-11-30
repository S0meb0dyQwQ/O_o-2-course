#include "Student.h"

Student::Student() : Person(), course(1), group(1) {}
Student::Student(char* name, int a, int b) : Person(name), course(a), group(b)
{
	if (course <= 0 || group <= 0)
	{
		throw std::invalid_argument("no course/group can't be zero or less");
	}
}
Student::Student(Student&& other) : Person(other), course(other.course), group(other.group)
{
	other.course = 0;
	other.group = 0;
}
Student::Student(const Student& other) : Person(other), course(other.course), group(other.group) {}
Student::~Student()
{
	fullname = nullptr;
}
void Student::SetCourse(int a)
{
	course = a;
}
int Student::GetCourse()
{
	return course;
}
void Student::SetGroup(int a)
{
	group = a;
}
int Student::GetGroup()
{
	return group;
}
void Student::Print()
{
	std::cout << fullname << '\n' << course << '\n' << group << '\n';
}
Student& Student:: operator = (const Student& other)
{
	if (this != &other)
	{
		strcpy(fullname, other.fullname);
		group = other.group;
		course = other.course;
	}
	return *this;
}
Student MakeStudent()
{
	char* name = new char[300];
	int c;
	int g;
	std::cout << "input name\n";
	std::cin.ignore();
	std::cin.getline(name, 300);
	std::cout << "input course\n";
	std::cin >> c;
	std::cout << "input group\n";
	std::cin >> g;
	return Student(name, c, g);
}
void MakeStudentList(Person** people, int size)
{
	Student* temp = new Student[size];
	int counter = 0;
	for (int i{}; i < size; ++i)
	{
		if (Student* ptr = dynamic_cast<Student*>(people[i]))
		{
			temp[counter++] = *ptr;
		}
	}
	for (int i = 0; i < counter; ++i)
	{
		temp[i].Print();
	}
}