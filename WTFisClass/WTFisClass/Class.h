#ifndef CLASS_H
#define CLASS_H

#include <iostream>

class List
{
private:
	struct Listitem
	{
		int info;
		Listitem* next;
	};
	Listitem* first;
public:
	List();
	List(const List&);
	~List();
	const List& operator = (const List&);
	const int Top() const;
	void InsertFirst(const int&);
	void InsertSorted(const int info);
	bool DeleteFirst();
	void ListPrint() const;
	void ForEach(void(int))const;
	void ForEach();
	void Erase();
private:
	void Clone(const List&);
};
void Print(int x);

#endif