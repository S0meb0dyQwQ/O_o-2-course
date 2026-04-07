#ifndef PERSON_H
#define PERSON_H
#include <iostream>
#include <string>
enum class State{normal,paralyzed,dead};
enum class Race{human,gnome,elf};
int identifier{};
class Person 
{
protected:
	const int id;
	std::string name;
	State state;
	const Race race;
	int ability_to_move;
	int amount_of_staff;
public:
	Person();
	Person(std::string, State, Race, int, int);
	Person(const Person&);
	Person(Person&&);
	~Person() = default;
	Person& operator = (const Person&);
	Person& operator = (Person&&);
	int GetId();
	std::string GetName();
	State GetState();
	Race GetRace();
	int GetMove();
	int GetStaff();
	void SetName(std::string);
	void SetState(State);
	void SetMove(int);
	void SetStaff(int);
	friend std::ostream& operator << (std::ostream&, Person);
	friend bool operator <(Person , Person);
};
#endif