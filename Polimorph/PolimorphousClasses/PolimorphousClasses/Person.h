#ifndef PERSON_H
#define PERSON_H
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
class Person 
{
protected:
	char* fullname;
public:
	Person();
	Person(char*);
	Person(Person&&);
	Person(const Person&);
	virtual~Person();
	void SetName(char*);
	char* GetName();
	void Print();
	Person& operator = (const Person&);
};
#endif