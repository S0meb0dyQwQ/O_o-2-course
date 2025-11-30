#include "ForestTree.h"
ForestTree::ForestTree(): Tree()
{
	amount_of_wood = 0;
}
ForestTree::ForestTree(std::string a, int b, Type c, int d): Tree(a,b,c)
{
	amount_of_wood = d;
}
ForestTree::ForestTree(const ForestTree& other): Tree(other)
{
	amount_of_wood = other.amount_of_wood;
}
void ForestTree::Print() 
{
	(static_cast<Tree>(*this)).Print();
	std::cout << amount_of_wood << '\n';
}
void ForestTree:: SetWood(int c) 
{
	amount_of_wood = c;
}
int ForestTree:: GetWood()
{
	return amount_of_wood;
}