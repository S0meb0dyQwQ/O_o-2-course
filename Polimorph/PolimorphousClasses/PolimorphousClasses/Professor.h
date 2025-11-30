#ifndef PROFESSOR_H
#define POFESSOR_H
#include "Person.h"
class Professor : public Person
{
private:
	char* department;
public:
	Professor();
	Professor(char*, char*);
	Professor(Professor&&);
	Professor(const Professor&);
	~Professor();
	void SetDepartment(char*);
	char* GetDepartment();
	void Print();
	Professor& operator = (const Professor&);
};
void MakeProfessorList(Person**, int);
Professor MakeProfessor();
#endif