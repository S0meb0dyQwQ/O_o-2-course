#ifndef FOOTBALLMAN_H
#define FOOTBALLMAN_H
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
static int identificator = 0;
enum class Species{vratar,defender,semidefender,atacker};
class Footballman 
{
protected:
	int id;
	char* surname;
	const Species spec;
	int data_of_end;
public:
	Footballman();
	Footballman(char*, Species, int);
	Footballman(const Footballman&);
	Footballman(Footballman&&);
	~Footballman();
	int GetId();
	char* GetName();
	Species GetSpeciality();
	int GetData();
	void setName(char*);
	void SetData(int);
	Footballman& operator = (const Footballman&);
	Footballman& operator = (Footballman&&);
	friend bool operator == (Footballman, Footballman);
	friend std::ostream& operator << (std::ostream&, Footballman);
};
void CountSpecies(Footballman**);
#endif