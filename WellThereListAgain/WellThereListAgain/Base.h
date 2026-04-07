#ifndef BASE_H
#define BASE_H
#include <iostream>
template <class T>
class DLList
{
private:
	struct Node
	{
		T data;
		Node* prev;
		Node* next;
	};
	Node* sntl;
	size_t sz;
public:
	DLList() 
	{
		this->sntl = new Node;
		this->sntl->prev = this->sntl;
		this->sntl->next = this->sntl;
		this->sz = 0;
	}
	~DLList()
	{
		Node* cur = this->sntl->next;
		while (cur != this->sntl) 
		{
			Node* next = cur->next;
			delete cur;
			cur = next;
		}
		this->sntl = nullptr;
		this->sz = 0;
	}
	T& back()
	{
		return this->sntl->prev->data;
	}
	const T& back()const
	{
		return this->sntl->prev->data;
	}
	T& front()
	{
		return this->sntl->next->data;
	}
	const T& front()const
	{
		return this->sntl->next->data;
	}
	T& operator [](size_t pos)
	{
		return this->elem_index(pos)->data;
	}
	const T& operator [](size_t pos)const
	{
		return this->elem_index(pos)->data;
	}
	Node* elem_index(size_t pos)
	{
		Node* elem = this->sntl;
		if (pos <= sz / 2)
		{
			for (size_t i{}; i <= pos; ++i)
			{
				elem = elem->next;
			}
		}
		else
		{
			for (size_t i{sz}; i >= pos; --i)
			{
				elem = elem->prev;
			}
		}
		return elem;
	}
	void insert(size_t pos, T elem)
	{
		Node* item = new Node;
		item->data = elem;
		Node* pos_node = this->elem_index(pos);
		Node* prev_node = pos_node->prev;
		prev_node->next = item;
		pos_node->prev = item;
		item->next = pos_node;
		item->prev = prev_node;;
		++(this->sz);
	}
	void erase(size_t pos)
	{
		Node* erase_node = this->elem_index(pos);
		Node* prev_erase = erase_node->prev;
		Node* next_erase = erase_node->next;
		prev_erase->next = next_erase;
		next_erase->prev = prev_erase;
		delete erase_node;
		--(this->sz);
	}
};
#endif