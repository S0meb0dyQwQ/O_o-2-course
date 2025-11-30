#ifndef CONTAINER_H
#define CONTAINER_H
#include "Tree.h"
#include "FruitTree.h"
#include "ForestTree.h"
#include <cstdlib>
#include <fstream>

class Container
{
private:
	Tree** trees;
	int size;
	int capacity;
	void Resize(int);
public:
	Container(int = 0);
	Container(const Container&);
	~Container();
	void Push_back(Tree*);
	void Pop_back();
	Tree at(int) const;
	void Print() const;
	int CountDeciduous();
	int CountConiferous();
	int CountForest();
	int CountFruit();
	void PrintSorted();
	int GetSize();
	int GetCapacity();
};
int CompareTrees(const void*, const void*);
void CheckInputFile(std::ifstream&);
int CountSize(std::ifstream&);
void MakeArrayFromFile(std::ifstream&, Container&);
#endif