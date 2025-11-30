#ifndef TREE_H
#define TREE_H
#include <iostream>
#include <string>
enum class Type{ deciduous, coniferous };
class Tree
{
protected:
	std::string name;
	int age{};
	Type type;
public:
	Tree();
	Tree(std::string, int, Type);
	Tree(const Tree&);
	~Tree() = default;
	virtual void Print();
	Type GetType();
	std::string GetName();
	int GetAge();
	void SetType(Type);
	void SetName(std::string);
	void SetAge(int);
};
#endif