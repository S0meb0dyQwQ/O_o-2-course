#include "Class.h"

List::List()
{
	first = NULL;
}

void List::InsertFirst(const int& ainfo)
{
	Listitem* P = new Listitem;
	P->info = ainfo;
	P->next = first;
	first = P;
}

bool List::DeleteFirst()
{
	if (first == NULL)
	{
		return false;
	}
	Listitem* P = first;
	first = first->next;
	delete P;
	return true;
}

const int List::Top() const
{
	if (first == NULL)
	{
		throw "list is empty";
	}
	int x = first->info;
	return x;
}

void List::Clone(const List& L)
{
	Listitem* p, * q, * r;
	r = NULL;
	p = L.first;
	while (p != NULL)
	{
		q = new Listitem;
		q->info = p->info;
		q->next = NULL;
		if (r == NULL)
		{
			first = q;
		}
		else
		{
			r->next = q;
		}
		r = q;
		p = p->next;
	}
}

void List::Erase()
{
	Listitem* p;
	Listitem* q;
	p = first;
	while (p != NULL)
	{
		q = p->next;
		delete p;
		p = q;
	}
	first = NULL;
}

List::List(const List& L)
{
	Clone(L);
}

const List& List::operator = (const List& L)
{
	if (&L == this)
	{
		return *this;
	}
	Erase();
	Clone(L);
	return *this;
}
void List:: ForEach()
{
	Listitem* p = first;
	if (p != NULL)
	{
		while (p != NULL)
		{
			std::cin >> p->info ;
			p = p->next;
		}
	}
}

List::~List()
{
	Erase();
}

void List::ListPrint()const// -_- яно не работает а это даже не я писал
{
	Listitem* p = first;
	if (p == NULL)
	{
		std::cout << "list is empty" << '\n';
	}
	if (p != NULL)
	{
		std::cout << "contents of the list" << '\n';
		while (p != NULL)
		{
			Print(p->info);
		}
		p = p->next;
	}
}

void Print(int x)
{
	std::cout << x << '\n';
}

void List:: InsertSorted(const int info)
{
	Listitem* ptr = first;
	Listitem* elem = ptr;
	elem->info = info;
	while (ptr->next != NULL) 
	{
		//ptr = ptr->next;   
		//if (elem->info < ptr->next->info) 
		//{
		//	elem->next = ptr->next;
		//	ptr->next = elem;
		//	break;
		//}
	}
}

void List::ForEach(void Fun(int))const
{
	Listitem* p = first;
	if (p == NULL)
	{
		std::cout << "list is empty" << '\n';
	}
	if (p != NULL)
	{
		std::cout << "contents of the list" << '\n';
		while (p != NULL)
		{
			Fun(p->info);//????????????????
			p = p->next;
		}
	}
}