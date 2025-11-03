#ifndef BASE_H
#define BASE_H
#include <iostream>
template <class TInfo>
class TDeque 
{
private:
	struct Item 
	{
		TInfo info; 
		Item* next; 
		Item* prev; 
	};
	
	Item* front;
	Item* back;
	int size;
	void Erase() 
	{
		Item* cursor = this->front;
		Item* next;
		while (cursor != nullptr)
		{
			next = cursor->next;
			cursor = nullptr;
			cursor = next;
		}
		size = 0;
	}
	void Clone(const TDeque& other) 
	{
		Item* cursor = other.front;
		Item* new_item;
		Item* new_list = nullptr;
		while (cursor != nullptr)
		{
			new_item = new Item;
			new_item->next = nullptr;
			new_item->info = cursor->info;
			if (new_list == nullptr)
			{
				new_item->prev = nullptr;
				this->front = new_item;
			}
			else
			{
				new_list->next = new_item;
				new_item->prev = new_list;
			}
			new_list = new_item;
			cursor = cursor->next;
		}
		this->back = new_list;
		new_list->next = nullptr;
		size = other.size;
	}
	void DeleteItem(Item* elem) 
	{
		Item* next = elem->next;
		Item* prev = elem->prev;
		next->prev = prev;
		prev->next = next;
		elem = nullptr;
		--size;
	}
	void* PtrByIndex(unsigned i)const
	{
		Item* cursor;
		if (i < size / 2)
		{
			cursor = front;
			for (unsigned k{1}; k < i; ++k)
			{
				cursor = cursor->next;
			}
		}
		else 
		{
			cursor = back;
			for (unsigned k{i + 1}; k < size; ++k)
			{
				cursor = cursor->prev;
			}
		}
		return (void*)cursor;
	}
public:
	TDeque()
	{
		front = nullptr;
		back = nullptr;
		size = 0;
	}
	TDeque(const TDeque& other) 
	{
		this->Clone(other);
	}
	~TDeque()
	{
		this->Erase();
	}
	void InsFront(TInfo data)
	{
		Item* new_item = new Item;
		new_item->info = data;
		if (front == nullptr)
		{
			front = new_item;
			back = new_item;
			front->next = back;
			back->prev = front;
			front->prev = nullptr;
			back->next = nullptr;
		}
		else
		{
			Item* cursor = front;
			new_item->next = front;
			front->prev = new_item;
			front = new_item;
		}
		++size;
	}
	void InsBack(TInfo data)
	{
		Item* new_item = new Item;
		new_item->info = data;
		if (back == nullptr) 
		{
			front = new_item;
			back = new_item;
			front->next = back;
			back->prev = front;
			front->prev = nullptr;
			back->next = nullptr;
		}
		else
		{
			Item* cursor = back;
			new_item->prev = back;
			back->next = new_item;
			back = new_item;
			back->next = nullptr;
		}
		++size;
	}
	bool DelFront()
	{
		if (front == nullptr)
		{
			return false;
		}
		Item* elem = front->next;
		elem->prev = nullptr;
		front = elem;
		size--;
		return true;
	}
	bool DelRear()
	{
		if (back == nullptr)
		{
			return false;
		}
		Item* elem = back->prev;
		elem->next = nullptr;
		back = elem;
		size--;
		return true;
	}
	const TDeque& operator = (const TDeque& other)
	{
		return this->Clone(other);
	}
	const TInfo& GetByIndex(unsigned i)const 
	{
		Item* cursor((Item*)this->PtrByIndex(i));
		return cursor->info;
	}
	void SetByIndex(TInfo data, unsigned i) 
	{
		Item* cursor((Item*)this->PtrByIndex(i));
		cursor->info = data;
	}
	void Browse(void Print(TInfo&)) 
	{
		Item* cursor = front;
		size_t i{ 1 };
		if (cursor == nullptr)
		{
			throw std::exception("list is empty, sorry");
		}
		else
		{
			while (cursor != nullptr)
			{

				Print(cursor->info);
				cursor = cursor->next;
			}
		}
	}
	void Browse(void Print(TInfo)) const 
	{
		Item* cursor = front;
		size_t i{ 1 };
		if (cursor == nullptr)
		{
			throw std::exception("list is empty, sorry");
		}
		else
		{
			while (cursor != nullptr)
			{
				
				Print(cursor->info);
				cursor = cursor->next;
			}
		}
	}
	void Print(TInfo a)const 
	{
		std::cout << a;
	}
	void Print(TInfo& a)
	{
		a = a + 27;
		std::cout << a;
	}

	void PrintDeque()const
	{
		Item* cursor = front;
		size_t i{ 1 };
		if (cursor == nullptr)
		{
			throw std::exception("list is empty, sorry");
		}
		else
		{
			while (cursor != nullptr)
			{
				
				std::cout << cursor->info;
				cursor = cursor->next;
			}
		}
	}
};

#endif