#ifndef BASE_H
#define BASE_H
#include <iostream>
#include <string>
#include <fstream>
struct Flat 
{
	size_t rooms{};
	size_t floor{};
	double area{0.0};
	std::string address;
	Flat& operator = (const Flat& a);
};
class List 
{
private:
	struct Item 
	{
		Flat info;
		Item* next;
	};
	Item* leader;
public:
	List();
	~List();
	List(const List&);
	void Erase();
	void Clone(const List& L);
	void Insert(Flat);
	void ListPrint()const;
	void FindGoodElement(Flat);
	void MakeCatalog(std::ifstream& fin);
	void InputCatalog();
};
int32_t CountNum(std::ifstream& fin);
void InputFlat(Flat&);
void CheckFlatInfo(Flat);
void Print(Flat);
bool operator > (const Flat& a, const Flat& b);
bool Compare(const Flat& a, const Flat& b);
#endif