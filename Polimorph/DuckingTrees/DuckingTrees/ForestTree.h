#ifndef FORESTTREE_H
#define FORESTTREE_H
#include "Tree.h"
class ForestTree : public Tree
{
private:
	int amount_of_wood;
public:
	ForestTree();
	ForestTree(std::string, int, Type, int);
	ForestTree(const ForestTree&);
	~ForestTree() = default;
	void Print()override;
	void SetWood(int);
	int GetWood();
};
#endif