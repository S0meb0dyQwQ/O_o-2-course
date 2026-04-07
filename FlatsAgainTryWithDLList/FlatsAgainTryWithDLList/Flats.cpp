#include "Base.h"
void InputFlat(Flat& house)
{
	std::cout << "input number of rooms:\n";
	std::cin >> house.rooms;
	std::cout << "input number for floor:\n";
	std::cin >> house.floor;
	std::cout << "input area of your house:\n";
	std::cin >> house.area;
	std::cout << "input your address:\n";
	std::cin.ignore();
	getline(std::cin, house.address);
}
void CheckFlatInfo(Flat house)
{
	if (house.rooms <= 0 || house.rooms > 5)
	{
		throw std::invalid_argument("wrong number of rooms");
	}
	if (house.floor <= 0)
	{
		throw std::invalid_argument("wrong number of floor");
	}
	if (house.area <= 0)
	{
		throw std::invalid_argument("too small area");
	}
	if (house.address.empty())
	{
		throw std::invalid_argument("you should enter your address");
	}
}
bool operator > (const Flat& a, const Flat& b)
{
	if (a.rooms == b.rooms)
	{
		if (a.floor == b.floor)
		{
			if (a.area == b.area)
			{
				return a.address > b.address;
			}
			return a.area > b.area;
		}
		return a.floor > b.floor;
	}
	return a.rooms > b.rooms;
}
void Print(Flat a)
{
	std::cout << "amount of rooms: " << a.rooms << '\n';
	std::cout << "number of floor: " << a.floor << '\n';
	std::cout << "area: " << a.area << '\n';
	std::cout << "address: " << a.address << '\n';
}
Flat& Flat:: operator = (const Flat& a)
{
	this->rooms = a.rooms;
	this->floor = a.floor;
	this->area = a.area;
	this->address = a.address;
	return *this;
}
int32_t CountNum(std::ifstream& fin)
{
	fin.clear();
	fin.seekg(0, std::ios::beg);
	std::string tmp;
	int32_t counter{};
	while (getline(fin, tmp))
	{
		++counter;
	}
	return counter;
}
bool Compare(const Flat& a, const Flat& b)
{
	if (a.rooms == b.rooms && a.floor == b.floor && fabs(1 - a.area / b.area) <= 0.1)
	{
		return true;
	}
	return false;
}

List::List()
{
	this->leader = new Item;
	this->leader->next = this->leader;
}
List::~List() 
{
	Item* current;
	Item* next;
	current = this->leader->next;
	while (current != this->leader)
	{
		next = current->next;
		delete current;
		current = next;
	}
	this->leader = nullptr;
}
List::List(const List& other) { Clone(other); }
void List::MakeCatalog(std::ifstream& fin)
{
	int32_t size{ CountNum(fin) };
	fin.clear();
	fin.seekg(0, std::ios::beg);
	Flat house;
	std::string line;
	for (int32_t i{}; i < size; ++i)
	{
		fin >> house.rooms;
		getline(fin, line, ';');
		fin >> house.floor;
		getline(fin, line, ';');
		fin >> house.area;
		getline(fin, line, ';');
		getline(fin, house.address);
		(*this).Insert(house);
	}
}
void List::InputCatalog()
{
	std::cout << "Hello, coworker. Please fill out flat application\n";
	bool choose{ true };
	Flat house;
	while (choose)
	{
		try
		{
			InputFlat(house);
			CheckFlatInfo(house);
			(*this).Insert(house);
		}
		catch (std::invalid_argument& error)
		{
			std::cout << error.what() << " try again, coworker\n";
		}
		std::cout << "do u need to input another flat?\n";
		std::cin >> choose;
	}
	system("cls");
}
void List::Clone(const List& L)
{
	Item* cursor;
	Item* new_item;
	Item* new_list;
	new_list = nullptr;
	cursor = L.leader;
	while (cursor != nullptr)
	{
		new_item = new Item;
		new_item->info = cursor->info;
		new_item->next = nullptr;
		if (new_list == nullptr)
		{
			this->leader = new_item;
		}
		else
		{
			new_list->next = new_item;
		}
		new_list = new_item;
		cursor = cursor->next;
	}
}
void List::Insert(Flat house)
{
	Item* newby = new Item;
	newby->info = house;
	
}
void List::ListPrint()const
{
	Item* cursor = leader;
	size_t i{ 1 };
	if (cursor == nullptr)
	{
		throw std::exception("list is empty, sorry");
	}
	else
	{
		while (cursor != nullptr)
		{
			std::cout << "flat No " << i++ << ": " << '\n';
			Print(cursor->info);
			cursor = cursor->next;
		}
	}
}
void List::FindGoodElement(Flat aplicat)
{
	Item* changer = new Item;
	changer->info = aplicat;
	Item* cursor = leader;
	Item* previous = nullptr;
	Item* ptr;
	while (cursor != nullptr)
	{
		if (Compare(cursor->info, changer->info))
		{
			if (previous == nullptr)
			{
				ptr = leader;
				leader = cursor->next;
				ptr = nullptr;
			}
			else
			{
				previous->next = cursor->next;
				delete cursor;
			}
			break;
		}
		previous = cursor;
		cursor = cursor->next;
	}
	if (cursor == nullptr)
	{
		throw std::invalid_argument("sorry, we cannot find good variant for u");
	}
}