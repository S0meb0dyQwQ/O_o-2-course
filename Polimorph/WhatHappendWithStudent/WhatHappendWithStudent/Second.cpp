#include "SecondSession.h"
Student_second_s::Student_second_s(std::string name, int a, int b, int* c, int* array):Student_first_s(name,a,b,c)
{
	for (int i{}; i < 5; ++i)
	{
		second_marks[i] = array[i];
	}
}
Student_second_s::Student_second_s(const Student_second_s&other): Student_first_s(other)
{
	for (int i{}; i < 5; ++i)
	{
		second_marks[i] = other.second_marks[i];
	}
}
void Student_second_s::SetSecondMarks(int grade, int i)
{
	second_marks[i] = grade;
}
int Student_second_s::GetSecondMarks(int i)
{
	return second_marks[i];
}
std::ostream& operator <<(std::ostream& out, Student_second_s people)
{
	out << static_cast<Student_first_s>(people);
	for (int i{}; i < 5; ++i)
	{
		out << people.second_marks[i] << '\t';
	}
	return out << '\n';
}
double Student_second_s::CountAverage()
{
	double  average_f{(static_cast<Student_first_s>(*this)).CountAverage()};
	double average_s{0.0};
	for (int i{}; i < 5; ++i) 
	{
		average_s += second_marks[i];
	}
	average_s /= 5;
	return (average_f + average_s) / 2;
}
double CountAverageFirstForGroup(Student_second_s* ias)
{
	double average{ 0.0 };
	for (int i{}; i < 4; ++i)
	{
		average += (static_cast<Student_first_s>(ias[i])).CountAverage();
	}
	return average / 4;
}
double CountAverageSecondForGroup(Student_second_s* ias)
{
	double average{ 0.0 };
	for (int i{}; i < 4; ++i)
	{
		average += ias[i].CountAverage();
	}
	return average / 4;
}