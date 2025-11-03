#ifndef BASE_H
#define BASE_H

#include <iostream>

class Stack
{
private:
	int32_t top;
	const int32_t size;
	int32_t* arr;

public:
	Stack(const int32_t & = 100);
	~Stack();
	Stack(const Stack&);
	Stack(Stack&&);
	Stack& operator=(const Stack&);
	Stack& operator=(Stack&&);
	void push(int32_t);
	void pop();
	int32_t peek()const;
	bool isEmpty()const;
	bool isFull()const;
};
bool isBracketRight(const std::string& str);
void sortTrain(const std::string& str);
#endif