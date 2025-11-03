#include "Base.h"

Stack::Stack(const int32_t& size) : size(size), top(0)
{
	if (size < 1)
	{
		throw std::invalid_argument("bad size\n");
	}
	arr = new int32_t[size];
}
Stack::~Stack()
{
	if (arr != NULL)
	{
		delete[] arr;
		arr = NULL;
	}
}
Stack::Stack(const Stack& other) : size(other.size), top(other.top)
{
	arr = new int32_t[size];
	for (int32_t i{}; i < top; ++i)
	{
		arr[i] = other.arr[i];
	}
}
Stack::Stack(Stack&& other) : size(other.size), top(other.top)
{
	const_cast<int&>(other.size) = 0;
	other.top = 0;
	arr = other.arr;
	other.arr = NULL;
	
}
void Stack::push(int32_t num)
{
	if (isFull())
	{
		throw std::out_of_range("stack is full\n");
	}
	arr[top++] = num;
}
void Stack::pop()
{
	if (isEmpty())
	{
		throw std::range_error("stack is empty\n");
	}
	--top;
}
int32_t Stack::peek()const
{
	if (isEmpty())
	{
		throw std::range_error("stack is empty\n");
	}
	return arr[top - 1];
}
bool Stack::isEmpty()const
{
	return top == 0;
}
bool Stack::isFull()const
{
	return top == size;
}
Stack& Stack:: operator=(const Stack& other) 
{
	const_cast<int&>(size) = other.size;
	top = other.top;
	arr = new int32_t[size];
	for (int32_t i{}; i < top; ++i)
	{
		arr[i] = other.arr[i];
	}
	return *this;
}
Stack& Stack:: operator=(Stack&& other)
{
	const_cast<int&>(size) = other.size;
	const_cast<int&>(other.size) = 0;
	top = other.top;
	other.top = 0;
	arr = other.arr;
	other.arr = NULL;
	return *this;
}


bool isBracketRight(const std::string& str)
{
	Stack stack(str.size());

	for (char ch : str) {
		switch (ch) {
		case '(':
		case '[':
		case '{':
			stack.push(ch);
			break;

		case ')':
			if (stack.isEmpty() || stack.peek() != '(') { return false; }
			else { stack.pop(); }
			break;

		case ']':
			if (stack.isEmpty() || stack.peek() != '[') { return false; }
			else { stack.pop(); }
			break;

		case '}':
			if (stack.isEmpty() || stack.peek() != '{') { return false; }
			else { stack.pop(); }
			break;

		default:
			break;
		}
	}

	return stack.isEmpty();
}

void sortTrain(const std::string& str)
{
	Stack bufer;
	std::string line;
	for (char ch : str)
	{
		switch (ch)
		{
		case 'b':
			if(line.empty() || line.back() == 'w')
			{
				line += ch;
				if (!bufer.isEmpty() && line.back() == 'b' && bufer.peek() == 'w')
				{
					bufer.pop();
					line +='w';
				}
			}
			else if (line.back() == 'b')
			{
				bufer.push(ch);
			}
			break;
		case'w':
			if (line.empty() || line.back() == 'b')
			{
				line += ch;
				if (!bufer.isEmpty() && line.back() == 'w' && bufer.peek() == 'b')
				{
					bufer.pop();
					line += 'b';
				}
			}
			else if (line.back() == 'w')
			{
				bufer.push(ch);
			}
			break;
		default:
			break;
		}
	}
	std::cout << line;
}