#include "FruitTree.h"
FruitTree::FruitTree(): Tree()
{
	mass_of_crop = 0;
	average_keeping = 0;
}
FruitTree::FruitTree(std::string a, int b, Type c, int d, int e): Tree(a,b,c)
{
	mass_of_crop = d;
	average_keeping = e;
}
FruitTree::FruitTree(const FruitTree& other): Tree(other)
{
	mass_of_crop = other.mass_of_crop;
	average_keeping = other.average_keeping;
}
void FruitTree::Print()
{
	(static_cast<Tree>(*this)).Print();
	std::cout << mass_of_crop << '\n' << average_keeping << '\n';
}
int FruitTree::GetCrop()
{
	return mass_of_crop;
}
int FruitTree::GetAvKep()
{
	return average_keeping;
}
void FruitTree::SetCrop(int c)
{
	mass_of_crop = c;
}
void FruitTree::SetAvKep( int c)
{
	average_keeping = c;
}