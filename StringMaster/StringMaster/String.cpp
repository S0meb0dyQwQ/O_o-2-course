#include "Base.h"
String::String() 
{
	this->length = 300;
	this->string = new char[length];
	std::cout << "input words\n";
	std::cin.getline(string, 300);
	this->length = strlen(string);
	/*strcpy(this->string, "");
	this->length = 1;*/
}
String::String(char* str, size_t n)
{
	this->length = n;
	this->string = new char[n + 1] {'\0'};
	strcpy(this->string, str);
}
String::String(const String& rhs)
{
	this->length = rhs.length;
	this->string = new char[length];
	strcpy(this->string, rhs.string);
}
String::String(String&& rhs)
{
	this->length = rhs.length;
	rhs.length = 0;
	string = rhs.string;
	rhs.string = nullptr;
}
String::~String()
{
	delete[]this->string;
	string = nullptr;
}
String String:: operator + (const String& rhs)const
{
	return String(strcat(this->string, rhs.string), this->length + rhs.length + 1);
}
bool String::operator==(const String& rhs) const
{
	return std::strcmp(this->string, rhs.string) == 0;
}


bool String::operator<(const String& rhs) const
{
	return std::strcmp(this->string, rhs.string) < 0;
}
String& String:: operator = (const String& other)
{
	if (this != &other)
	{
	length = other.length;
	string = nullptr;
	string = new char[length + 1];
	strcpy(string, other.string);
	}
	return *this;
}
String& String:: operator = (String&& other) 
{
	length = other.length;
	delete[]string;
	string = other.string;
	other.string = nullptr;
	other.length = 0;
	return *this;
}
bool String::operator>(const String& rhs) const
{
	return rhs.string>this->string;
}

bool String::operator!=(const String& rhs) const
{
	return !(this->string == rhs.string);
}
char& String:: operator[](size_t index)const
{
	if (index > length || index < 0)
	{
		throw std::out_of_range("can't find this symbol");
	}
	return this->string[index];
}
bool String::empty() const
{
	return this->length == 0;
}
void String::clear()
{
	delete[]this->string;
	this->string = new char[1] {'\0'};
	length = 0;
}

size_t String::size()const
{
	return this->length;
}
size_t String::find(const String& rhs)const 
{
	if (strstr(this->string, rhs.string) == nullptr) 
	{
		return -1;
	}
	return this->length - strlen(strstr(this->string, rhs.string));
}
size_t String:: find_first_of(const String& rhs)const 
{
	if (strpbrk(this->string, rhs.string) == nullptr)
	{
		return -1;
	}
	return this->length - strlen(strpbrk(this->string, rhs.string));
}
size_t String:: find_last_of(const String& rhs)const
{
	for (size_t i{}; i < rhs.length; ++i)
	{
		if (strrchr(string, rhs.string[i]))
		{
			return this->length - strlen(strrchr(string, rhs.string[i]));
		}
	}
	return -1;
}
String String:: substr(size_t pos, size_t count)const
{
	if (pos >= length || pos < 0) 
	{
		throw std::out_of_range("position is too big");
	}
	if (length - pos < count)
	{
		count = length - pos;
	}
	char* copy = new char[count + 1] {'\0'};
	strncpy(copy, (this->string) + pos, count);
	String result(copy, count + 1);
	delete[]copy;
	return result;
}
void String::reverse()
{
	size_t len{ length / 2 };
	for (size_t i{}; i < len; ++i)
	{
		std::swap(string[i], string[length - i - 1]);
	}
}

int String::compare(const String& rhs) const
{
	return std::strcmp(string, rhs.string);
}

void String::insert(size_t pos, const String& rhs)
{
	if (pos > length)
	{
		throw std::out_of_range("insert position out of range\n");
	}
	char* result = new char[length + rhs.length + 1];
	std::strncpy(result, string, pos);
	std::strcpy(result + pos, rhs.string);
	std::strcpy(result + pos + rhs.length, string + pos);
	this->string = nullptr;
	this->string = result;
	length += rhs.length;
}

void String::replace(size_t pos, size_t count, const String& rhs)
{
	if (pos >= length)
	{
		throw std::out_of_range("position is too big");
	}
	if (length - pos < count)
	{
		count = length - pos;
	}
	char* bufer = new char[length - pos + 1];
	strncpy(bufer, string, pos);
	strcpy(bufer + pos, rhs.string);
	strcat(bufer, string + pos + count);
	this->string = nullptr;
	this->string = bufer;
	length -= count - rhs.length;
}
String& String:: erase(size_t pos)
{
	if (pos >= length)
	{
		throw std::out_of_range("position is too big");
	}
	(*this)[pos] = '\0';
	this->length = pos;
	return *this;
}
void String:: push_back(char ch)
{
	String copy(this->string,length + 1);
	copy.string[length] = ch;
	*this = copy;
}
void String::pop_back()
{
	(*this)[--length] = '\0';
}
void String:: resize(size_t n, char ch)
{
	this->length = n + 1;
	if (n >= length) 
	{
		(*this).append(n - length, ch);
	}
	else 
	{
		(*this).erase(n);
	}
}
String& String:: append(size_t n, char ch) 
{
	for (size_t i{}; i < n; ++i)
	{
		(*this).push_back(ch);
	}
	return *this;
}
String& String:: append(const String& rhs)
{
	return (*this) = (*this) + rhs;
}
char* String::c_str()
{
	return this->string;
}
bool String::isNumber() const
{
	for (size_t i{}; i < length; ++i)
	{
		if (!isdigit(string[i]) && string[i] != '.')
		{
			return false;
		}
	}
	return true;
}
int String::stoi() 
{
	return this->stod();
}
double String::stod()
{
	if (!isNumber())
	{
		throw std::invalid_argument("this is not a number");
	}
	return atof(string);
}
std::istream& getline(std::istream& cin, String& a)
{
	return cin.getline(a.string, 300);
}
size_t String::count(char ch) const
{
	size_t counter{};
	for (size_t i{}; i < length; ++i)
	{
		if (string[i] == ch)
		{
			++counter;
		}
	}
	return counter;
}