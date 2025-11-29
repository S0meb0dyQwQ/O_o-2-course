#include "Base.h"
#include "Linear.h"
#include "quadratic.h"
int CompareUpSenior(const void* a, const void* b)
{
	return (*(Equation*)a).GetSenior() > (*(Equation*)b).GetSenior();
}
int CompareBDown(const void* a, const void* b)
{
	return (*(Linear*)a).GetBCoef() > (*(Linear*)b).GetBCoef();
}
void MakeEquationFileInfo(Equation** array)
{
	std::ofstream fout("Equations.txt");
	for (int i{}; i < 5; ++i)
	{
		array[i]->Print(fout);
		try
		{
			array[i]->Solve(fout);
		}
		catch (std::invalid_argument& e)
		{
			fout << e.what();
		}
	}
}
void FindWhoHaveNoRoots(Equation** array) 
{
	for (int i{}; i < 5; ++i)
	{
		if (Quadratic* ptr = dynamic_cast<Quadratic*>(array[i]))
		{
			if (ptr->Disc() < 0)
			{
				ptr->Print(std::cout);
			}
		}
		if (Linear* l = dynamic_cast<Linear*>(array[i]))
		{
			if (l->GetSenior() == 0 && l->GetBCoef() != 0) 
			{
				l->Print(std::cout);
			}
		}
	}
}
int FindWithEndlessRoots(Equation** array) 
{
	int counter = 0;
	for (int i{}; i < 5; ++i)
	{
		if (Linear* ptr = dynamic_cast<Linear*>(array[i]))
		{
			if (ptr->GetSenior() == 0 && ptr->GetBCoef() == 0)
			{
				ptr->Print(std::cout);
				++counter;
			}
		}
	}
	return counter;
}
void FindSadSmile(Equation** array)
{
	for (int i{}; i < 5; ++i)
	{
		if (Quadratic* ptr = dynamic_cast<Quadratic*>(array[i]))
		{
			if (ptr->GetSenior() < 0) 
			{
				ptr->Print(std::cout);
			}
		}
	}
}
void FindFullSquare(Equation** array)
{
	Quadratic* temp = new Quadratic[5];
	int size = 0;
	for (int i{}; i < 5; ++i)
	{
		if (Quadratic* ptr = dynamic_cast<Quadratic*>(array[i]))
		{
			if (ptr->Disc() == 0)
			{
				temp[size++] = *ptr;
			}
		}
	}
	qsort(temp, size, sizeof(Quadratic), CompareUpSenior);
	for (int i{}; i < size; ++i)
	{
		temp[i].Print(std::cout);
	}
	delete[]temp;
}
void FindSeniorLessB(Equation** array)
{
	Linear* temp = new Linear[5];
	int size = 0;
	for (int i{}; i < 5; ++i)
	{
		if (Linear* ptr = dynamic_cast<Linear*>(array[i]))
		{
			if (ptr->GetBCoef() > ptr->GetSenior()) 
			{
				temp[size++] = *ptr;
			}
		}
	}
	qsort(temp, size, sizeof(Linear), CompareBDown);
	for (int i{}; i < size; ++i)
	{
		temp[i].Print(std::cout);
	}
	delete[]temp;
}
void SortArrayBySenior(Equation** array)
{
	Quadratic* ar_q = new Quadratic[5];
	int size_q = 0;
	Linear* ar_l = new Linear[5];
	int size_l = 0;
	for (int i{}; i < 5; ++i)
	{
		if (Linear* ptr_l = dynamic_cast<Linear*>(array[i]))
		{
			ar_l[size_l++] = *ptr_l;
		}
		if (Quadratic* ptr_q = dynamic_cast<Quadratic*>(array[i]))
		{
			ar_q[size_q++] = *ptr_q;
		}
	}
	qsort(ar_q, size_q, sizeof(Quadratic), CompareUpSenior);
	qsort(ar_l, size_l, sizeof(Linear), CompareUpSenior);
	int i = 0;
	int j = 0;
	int k = 0;
	Equation** result = new Equation*[5];
	while (i < size_l && j <size_q) {
		if (ar_l[i].GetSenior() < ar_q[j].GetSenior()) 
		{
			result[k++] = &ar_l[i++];
		}
		else {
			result[k++] = &ar_q[j++];
		}
	}

	while (i < size_l) {
		result[k++] = &ar_l[i++];
	}
	while (j <size_q) {
		result[k++] = &ar_q[j++];
	}
	for (int i{}; i < 5; ++i)
	{
		result[i]->Print(std::cout);
	}
	delete[]ar_q;
	delete[]ar_l;
	delete[]result;
}