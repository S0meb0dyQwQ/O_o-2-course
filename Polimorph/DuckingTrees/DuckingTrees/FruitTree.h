#ifndef FRUITTREE_H
#define FRUITTREE_H
#include "Tree.h"
class FruitTree :public Tree 
{
private:
	int mass_of_crop;
	int average_keeping;
public:
	FruitTree();
	FruitTree(std::string, int, Type,int,int);
	FruitTree(const FruitTree&);
	~FruitTree() = default;
	void Print()override;
	int GetCrop();
	int GetAvKep();
	void SetCrop(int);
	void SetAvKep( int);
};
#endif