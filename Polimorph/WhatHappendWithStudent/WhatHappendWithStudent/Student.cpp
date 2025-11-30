#include "Student.h"
int Student::GenerateId()
{
	srand(time(0));
	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_int_distribution<int>dist(0, 1000000);
	return dist(gen);
}
Student::Student(std::string c, int a, int b)
{
	name = c;
	course = a;
	group = b;
}
Student::Student(const Student& other):id(other.id), card_id(other.card_id)
{
	name = other.name;
	course = other.course;
	group = other.group;
}
void Student::SetName(std::string line)
{
	name = line;
}
void Student::SetCourse(int c)
{
	course = c;
}
void Student::SetGroup(int g)
{
	group = g;
}
std::string Student::GetName()
{
	return name;
}
int Student::GetCourse()
{
	return course;
}
int Student::GetGroup() 
{
	return group;
}
std::ostream& operator <<(std::ostream& out, Student people)
{
	return out << people.id << '\n' << people.name << '\n' << people.course << '\n' << people.group << '\n' << people.card_id << '\n';
}