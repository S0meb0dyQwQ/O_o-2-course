#ifndef MATRIX_H
#define MATRIX_H
#include <iostream>
#include <string>
template<class T>
class Matrix 
{
private:
	T** array;
	int cols;
	int rows;
	void Delete()
	{
		for (int i{}; i < cols; ++i)
		{
			delete[]array[i];
		}
		rows = 0;
		cols = 0;
		delete[]array;
	}
public:
	Matrix() 
	{
		array = new T*;
		cols = 0;
		rows = 0;
	}
	Matrix(int n,int k)
	{
		rows = n;
		cols = k;
		array = new T*[k];
		for (int i{}; i < cols; ++i)
		{
			array[i] = new T[rows];
			for (int k{}; k < rows; ++k)
			{
				array[i][k] = 0;
			}
		}
	}
	~Matrix() 
	{
		this->Delete();
	}
	Matrix(Matrix&& other)
	{
		cols = other.cols;
		rows = other.rows;
		this->Delete();
		array = new T * [cols];
		for (int i{}; i < cols; ++i)
		{
			array[i] = new T[rows];
			for (int k{}; k < rows; ++k)
			{
				array[i][k] = other.array[i][k];
			}
		}
		other.Delete();
	}
	Matrix(const Matrix& other)
	{
		cols = other.cols;
		rows = other.rows;
		this->Delete();
		array = new T * [cols];
		for (int i{}; i < cols; ++i)
		{
			array[i] = new T[rows];
			for (int k{}; k < rows; ++k)
			{
				array[i][k] = other.array[i][k];
			}
		}
	}
	void Print()
	{
		for (int i{}; i < cols; ++i)
		{
			for (int k{}; k < rows; ++k)
			{
				std::cout << array[i][k] << '\t';
			}
			std::cout << '\n';
		}
	}
	Matrix& operator = (const Matrix& other) 
	{
		if (this != &other) 
		{
			cols = other.cols;
			rows = other.rows;
			this->Delete();
			array = new T * [cols];
			for (int i{}; i < cols; ++i)
			{
				array[i] = new T[rows];
				for (int k{}; k < rows; ++k)
				{
					array[i][k] = other.array[i][k];
				}
			}
		}
		return *this;
	}
	Matrix& operator = (Matrix&& other)
	{
		if (this != &other)
		{
			cols = other.cols;
			rows = other.rows;
			this->Delete();
			array = new T * [cols];
			for (int i{}; i < cols; ++i)
			{
				array[i] = new T[rows];
				for (int k{}; k < rows; ++k)
				{
					array[i][k] = other.array[i][k];
				}
			}
			other.Delete();
		}
		return *this;
	}
	//определитель, минор можно, можно обратную,
	Matrix operator +(Matrix other) 
	{
		if (rows != other.rows || cols != other.cols)
		{
			std::cout << "no u can't";
		}
		for (int i{}; i < cols; ++i)
		{
			for (int k{}; k < rows; ++k)
			{
				array[i][k] += other.array[i][k];
			}
		}
		return *this;
	}
	Matrix operator * (T a) 
	{
		for (int i{}; i < cols; ++i)
		{
			for (int k{}; k < rows; ++k)
			{
				array[i][k] *= a;
			}
		}
	}
	Matrix operator * (Matrix other)
	{
		if (cols != other.rows)
		{
			std::cout << "govno";
		}
		Matrix sum(rows,other.cols);
		for (int i{}; i < sum.cols; ++i)
		{
			for (int k{}; k < sum.rows; ++k)
			{
				for (int s{}; s < cols; ++s)
				{
					sum[i][k] += array[i][s] * other.array[s][k];
				}
			}
		}
		return sum;
	}
	Matrix Trans()
	{
		Matrix T(rows, cols);
		for (int i{}; i < sum.cols; ++i)
		{
			for (int k{}; k < sum.rows; ++k)
			{
				T[i][k] = array[k][i];
			}
		}
		return *this = T;
	}
	Matrix operator -(Matrix other)
	{
		other = other * (-1);
		return *this = *this + other;
	}
};
#endif