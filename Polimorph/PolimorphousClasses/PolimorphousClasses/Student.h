#ifndef STUDENT_H
#define STUDENT_H
#include "Person.h"
class Student : public Person
{
private:
	int course;
	int group;
public:
	Student();
	Student(char*, int, int);
	Student(Student&&);
	Student(const Student&);
	~Student();
	void SetCourse(int);
	int GetCourse();
	void SetGroup(int);
	int GetGroup();
	void Print();
	Student& operator = (const Student&);
};
Student MakeStudent();
void MakeStudentList(Person**, int);
#endif