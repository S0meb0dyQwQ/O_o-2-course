#include "FirstSession.h"
Student_first_s::Student_first_s(std::string name, int a, int b, int* array): Student(name, a, b)
{
	for (int i{}; i < 4; ++i)
	{
		first_marks[i] = array[i];
	}
}
Student_first_s::Student_first_s(const Student_first_s& other): Student(other)
{
	for (int i{}; i < 4; ++i)
	{
		first_marks[i] = other.first_marks[i];
	}
}
void Student_first_s::SetFirstMark(int grade, int i)
{
	first_marks[i] = grade;
}
int Student_first_s::GetFirstMark(int i)
{
	return first_marks[i];
}
std::ostream& operator <<(std::ostream& out, Student_first_s people)
{
	out << static_cast<Student>(people);
	for (int i{}; i < 4; ++i)
	{
		out << people.first_marks[i] << '\t';
	}
	return out << '\n';
}
double Student_first_s::CountAverage()
{
	double average = 0.0;
	for (int i{}; i < 4; ++i) 
	{
		average +=first_marks[i];
	}
	return average / 4;
}