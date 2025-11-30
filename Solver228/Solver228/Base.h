#ifndef BASE_H
#define BASE_H
#include <iostream>
#include <cmath>
#include <string>
#include <fstream>
class Equation
{
public:
	virtual void Print(std::ostream& out) = 0;
	virtual void Solve(std::ostream& out) = 0;
	virtual double GetSenior() = 0;
};
void MakeEquationFileInfo(Equation**);
void CheckOutputFile(std::ofstream&);
void FindWhoHaveNoRoots(Equation**);
int FindWithEndlessRoots(Equation**);
void FindSadSmile(Equation**);
int CompareUpSenior(const void* a, const void * b);
int CompareBDown(const void* a, const void* b);
void FindFullSquare(Equation**);
void FindSeniorLessB(Equation**);
void SortArrayBySenior(Equation**);
#endif