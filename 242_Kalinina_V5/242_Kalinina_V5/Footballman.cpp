#include "Footballman.h"
Footballman::Footballman(): id(++identificator),spec(Species::vratar)
{
	surname = new char[300];
	data_of_end = 2025;
}
Footballman::Footballman(char* name, Species special, int data): id(++identificator), spec(special)
{
	surname = new char[strlen(name) + 1];
	strcpy(surname, name);
	data_of_end = data;
}
Footballman::Footballman(const Footballman& other):id(++identificator), spec(other.spec)
{
	surname = new char[strlen(other.surname) + 1];
	strcpy(surname, other.surname);
	data_of_end = other.data_of_end;
}
Footballman::Footballman(Footballman&& other) :id(++identificator), spec(other.spec)
{
	surname = new char[strlen(other.surname) + 1];
	strcpy(surname, other.surname);
	delete[]other.surname;
	data_of_end = other.data_of_end;
	other.data_of_end = 0;
}
Footballman::~Footballman()
{
	surname = nullptr;
	delete[]surname;
}
int Footballman::GetId()
{
	return id;
}
char* Footballman::GetName()
{
	return surname;
}
Species Footballman::GetSpeciality()
{
	return spec;
}
int Footballman::GetData()
{
	return data_of_end;
}
void Footballman::setName(char* other)
{
	delete[]surname;
	surname = new char[strlen(other)];
	strcpy(surname, other);
}
void Footballman::SetData(int data)
{
	data_of_end = data;
}
Footballman& Footballman:: operator = (const Footballman& other)
{
	if (this != &other)
	{
	const_cast<Species&>(spec) = other.spec;
	strcpy(surname, other.surname);
	data_of_end = other.data_of_end;
	}
	return *this;
}
Footballman& Footballman:: operator = (Footballman&& other)
{
	if (this != &other)
	{
		const_cast<Species&>(spec) = other.spec;
		strcpy(surname, other.surname);
		data_of_end = other.data_of_end;
		delete[]other.surname;
		other.data_of_end = 0;
	}
	return *this;
}
bool operator == (Footballman first, Footballman second)
{
	return first.spec == second.spec;
}
std::ostream& operator << (std::ostream& out, Footballman human)
{
	out << "Id: " << human.id << '\n' << "Surname: " << human.surname << '\n'<<"Speciality: ";
	switch (human.spec) 
	{
	case Species::vratar:
		out << "vratar\n";
		break;
	case Species::defender:
		out << "defender\n";
		break;
	case Species::semidefender:
		out << "semidefender\n";
		break;
	case Species::atacker:
		out << "atacker\n";
		break;
	}
	out << "Data of the end: " << human.data_of_end;
	return out;
}
void CountSpecies(Footballman** array)
{
	int counter_at{};
	int counter_def{};
	int counter_semdef{};
	int counter_vr{};
	for (int i{}; i < 4; ++i)
	{
		switch (array[i]->GetSpeciality()) 
		{
		case Species::vratar:
			++counter_vr;
			break;
		case Species::defender:
			++counter_def;
			break;
		case Species::semidefender:
			++counter_semdef;
			break;
		case Species::atacker:
			++counter_at;
			break;
		}
	}
	std::cout << "atacker " << counter_at << "defender " << counter_def << "semidefender " << counter_semdef << "atacker " << counter_at;
}