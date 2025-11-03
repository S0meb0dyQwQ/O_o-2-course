#ifndef BASE_H
#define BASE_H
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
class String
{
private:
	size_t length;
	char* string;
public:
	String operator + (const String&)const;
	bool operator==(const String& other) const;
	String& operator = (const String& other);
	String& operator = (String&& other);
	bool operator>(const String& other) const;
	bool operator<(const String& other) const;
	bool operator!=(const String& other) const;
	char& operator[](size_t pos)const;
	friend std::ostream& operator << (std::ostream& cout, const String& a) 
	{
		cout << a.string;
		return cout;
	}
	size_t size()const;
	bool empty() const;
	void clear();
	void pop_back();
	void resize(size_t n, char ch);
	void push_back(char ch);
	String& append(size_t n, char ch);
	String& append(const String&);
	size_t find(const String&)const;
	size_t find_first_of(const String&)const;
	size_t find_last_of(const String&)const;
	String substr(size_t, size_t)const;
	void reverse();
	String& erase(size_t pos);
	int compare(const String& other) const;
	void insert(size_t pos, const String& str);
	void replace(size_t pos,size_t count,const String& tmp);
	char* c_str();
	int stoi();
	double stod();
	friend std::istream& getline(std::istream&, String&);
	bool isNumber()const;
	size_t count(char ch) const;
	String(String&&);
	String();
	String(char*, size_t);
	String(const String&);
	~String();
};
#endif