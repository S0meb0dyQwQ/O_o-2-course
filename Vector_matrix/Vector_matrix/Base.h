#ifndef BASE_H
#define BASE_H
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <iomanip>
template<typename T>
class Matrix 
{
private:
	size_t rows;
	size_t cols;
	std::vector<std::vector<T>> data;
public:
	Matrix() :rows(1), cols(1) {}
	Matrix(size_t a, size_t b) :rows(a), cols(b)
	{
		data.resize(rows, std::vector<T>(cols, 0));
	}
	Matrix(size_t a, size_t b, T num) :rows(a), cols(b)
	{
		data.resize(rows, std::vector<T>(cols, num));
	}
	Matrix(const std::vector<std::vector<T>>& other) : rows(other.size()), cols(other[0].size())
	{
		for (size_t i{}; i < rows; ++i)
		{
			if (other[i].size() != cols)
			{
				throw std::invalid_argument("hehehe no");
			}
		}
		data = other;
	}
	Matrix(const Matrix& other) :rows(other.rows), cols(other.cols), data(other.data) {}
	Matrix(Matrix&& other) noexcept :rows(other.rows), cols(other.cols), data(std::move(other.data))
	{
		other.rows = 0;
		other.cols = 0;
	}
	~Matrix() = default;

	Matrix& operator = (const Matrix& other)
	{
		if (this != &other)
		{
			rows = other.rows;
			cols = other.cols;
			data = other.data;
		}
		return *this;
	}
	Matrix& operator = (Matrix&& other) noexcept
	{
		if (this != &other)
		{
			rows = other.rows;
			cols = other.cols;
			data = std::move(other.data);
			other.rows = 0;
			other.cols = 0;
		}
		return *this;
	}
	Matrix operator * (const Matrix a)const
	{
		if (cols != a.rows)
		{
			throw std::invalid_argument("bad sizes");
		}
		Matrix res(rows, a.cols);
		for (size_t i{}; i < rows; ++i)
		{
			for (size_t j{}; j < a.cols; ++j)
			{
				for (size_t k{}; k < a.rows; ++k)
				{
					res[i][j] += data[i][k] * a.data[k][j];
				}
			}
		}
		return res;
	}
	Matrix operator * (const T a)const
	{
		Matrix result(*this);
		for (size_t i{}; i < rows; ++i)
		{
			for (size_t j{}; j < cols; ++j)
			{
				result[i][j] = data[i][j] * a;
			}
		}
		return result;
	}
	Matrix operator + (const Matrix a)const
	{
		if (rows != a.rows || cols != a.cols)
		{
			throw std::invalid_argument("hehehe no");
		}
		Matrix result(*this);
		for (size_t i{}; i < rows; ++i)
		{
			for (size_t j{}; j < cols; ++j)
			{
				result.data[i][j] = data[i][j] + a.data[i][j];
			}
		}
		return result;
	}
	Matrix operator - (const Matrix a)const
	{
		return Matrix(*this + (-1) * a);
	}

	Matrix& operator += (const Matrix a)
	{
		return (*this) = (*this) + a;
	}
	Matrix& operator -= (const Matrix a)
	{
		return (*this) += (-1) * a;
	}
	Matrix& operator *= (const Matrix a)
	{
		return (*this) = (*this) * a;
	}
	Matrix& operator *= (T a)
	{
		return (*this) = (*this) * a;
	}
	std::vector<T>& operator[](size_t i)
	{
		return data[i];
	}
	const std::vector<T>& operator[](size_t i)const
	{
		if (i > rows || i < 0)
		{
			throw std::invalid_argument("hehehe no");
		}
		return data[i];
	}
	const T operator()(size_t i, size_t j) const
	{
		if (i > rows - 1 || i < 0 || j > cols - 1 || j < 0)
		{
			throw std::invalid_argument("hehehe no");
		}
		return data[i][j];
	}
	T operator()(size_t i, size_t j)
	{
		return (*this)(i, j);
	}
	inline friend Matrix operator* (T num, const Matrix& a)
	{
		return Matrix(a * num);
	}
	bool operator == (const Matrix& other)const
	{
		/*for (size_t i{}; i < rows; ++i)
		{
		for (size_t j{}; j < cols; ++j)
		{
		if (data[i][j] != other.data[i][j])
		{
		return false;
		}
		}
		}
		return true;*/
		return data == other.data;
	}
	bool operator != (const Matrix& other)const
	{
		/*return !(*this == other);*/
		return data != other.data;
	}
	inline friend std::ostream& operator << (std::ostream& out, const Matrix& a)
	{
		for (std::vector<T> row : a.data)
		{
			for (T elem : row)
			{
				out << std::setw(3)<< elem << " ";
			}
			out << '\n';
		}
		return out;
	}
	inline friend std::istream& operator >> (std::istream& in, Matrix& a)
	{
		for (size_t i{}; i < a.rows; ++i)
		{
			for (size_t j{}; j < a.cols; ++j)
			{
				in >> a.data[i][j];
			}
		}
		return in;
	}

	Matrix Trans()const
	{
		Matrix trans(cols, rows);
		for (size_t i{}; i < cols; ++i)
		{
			for (size_t j{}; j < rows; ++j)
			{
				trans.data[i][j] = data[j][i];
			}
		}
		return trans;
	}
	static Matrix Identity(size_t size)
	{
		Matrix ed(size, size, 0);
		for (size_t i{}; i < size; ++i)
		{
			ed.data[i][i] = 1;
		}
		return ed;
	}

	size_t GetCols()const
	{
		return cols;
	}
	size_t GetRows()const
	{
		return rows;
	}

	T det_gauss() const {
		if (rows != cols)
			throw std::invalid_argument("Matrix must be square for determinant");

		Matrix temp = *this;
		T det = 1.0;
		int swaps = 0;

		for (int i = 0; i < rows; ++i) {
			if (temp[i][i] == 0) {
				int pivot = -1;
				for (int j = i + 1; j < rows; ++j) {
					if (temp[j][i] != 0) {
						pivot = j;
						break;
					}
				}
				if (pivot == -1) {
					return 0.0;
				}
				std::swap(temp[i], temp[pivot]);
				swaps++;
			}

			for (int j = i + 1; j < rows; ++j) {
				T factor = temp[j][i] / temp[i][i];
				if (factor == 0) continue;

				for (int k = i; k < cols; ++k) {
					temp[j][k] -= factor * temp[i][k];
				}
			}
		}

		for (int i = 0; i < rows; ++i) {
			det *= temp[i][i];
		}
		return (swaps % 2 == 0) ? det : -det;
	}
	Matrix minor(int row, int col) const {
		Matrix result(rows - 1, cols - 1);

		int r = 0;
		for (int i = 0; i < rows; ++i) {
			if (i != row) {
				int c = 0;
				for (int j = 0; j < cols; ++j) {
					if (j != col) {
						result[r][c] = data[i][j];
						++c;
					}
				}
				++r;
			}
		}
		return result;
	}
	Matrix adjugate() const {
		if (rows != cols)
			throw std::invalid_argument("Matrix must be square for adjugate");

		Matrix result(rows, cols);
		for (int i = 0; i < rows; ++i) {
			for (int j = 0; j < cols; ++j) {
				Matrix m = minor(j, i);
				T sign = ((i + j) % 2 == 0) ? 1.0 : -1.0;
				result[i][j] = sign * m.det_gauss();
			}
		}
		return result;
	}
};
template<>
class Matrix<std::string>
{
private:
	size_t rows;
	size_t cols;
	std::vector<std::vector<std::string>> data;
public:
	Matrix() :rows(1), cols(1) {}
	Matrix(size_t a, size_t b) :rows(a), cols(b)
	{
		data.resize(rows, std::vector<std::string>(cols, "0"));
	}
	Matrix(size_t a, size_t b, std::string num) :rows(a), cols(b)
	{
		data.resize(rows, std::vector<std::string>(cols, num));
	}
	Matrix(const std::vector<std::vector<std::string>>& other) : rows(other.size()), cols(other[0].size())
	{
		for (size_t i{}; i < rows; ++i)
		{
			if (other[i].size() != cols)
			{
				throw std::invalid_argument("hehehe no");
			}
		}
		data = other;
	}
	Matrix(const Matrix& other) :rows(other.rows), cols(other.cols), data(other.data) {}
	Matrix(Matrix&& other) noexcept :rows(other.rows), cols(other.cols), data(std::move(other.data))
	{
		other.rows = 0;
		other.cols = 0;
	}
	~Matrix() = default;

	Matrix& operator = (const Matrix& other)
	{
		if (this != &other)
		{
			rows = other.rows;
			cols = other.cols;
			data = other.data;
		}
		return *this;
	}
	Matrix& operator = (Matrix&& other) noexcept
	{
		if (this != &other)
		{
			rows = other.rows;
			cols = other.cols;
			data = std::move(other.data);
			other.rows = 0;
			other.cols = 0;
		}
		return *this;
	}
	Matrix operator + (const Matrix a)const
	{
		if (rows != a.rows || cols != a.cols)
		{
			throw std::invalid_argument("hehehe no");
		}
		Matrix result(*this);
		for (size_t i{}; i < rows; ++i)
		{
			for (size_t j{}; j < cols; ++j)
			{
				result.data[i][j] = data[i][j] + a.data[i][j];
			}
		}
		return result;
	}

	Matrix& operator += (const Matrix a)
	{
		return (*this) = (*this) + a;
	}
	std::vector<std::string>& operator[](size_t i)
	{
		return data[i];
	}
	const std::vector<std::string>& operator[](size_t i)const
	{
		if (i > rows || i < 0)
		{
			throw std::invalid_argument("hehehe no");
		}
		return data[i];
	}
	const std::string operator()(size_t i, size_t j) const
	{
		if (i > rows - 1 || i < 0 || j > cols - 1 || j < 0)
		{
			throw std::invalid_argument("hehehe no");
		}
		return data[i][j];
	}
	std::string operator()(size_t i, size_t j)
	{
		return (*this)(i, j);
	}
	bool operator == (const Matrix& other)const
	{
		return data == other.data;
	}
	bool operator != (const Matrix& other)const
	{
		return data != other.data;
	}
	inline friend std::ostream& operator << (std::ostream& out, const Matrix& a)
	{
		for (std::vector<std::string> row : a.data)
		{
			for (std::string elem : row)
			{
				out << std::setw(3) << elem << " ";
			}
			out << '\n';
		}
		return out;
	}
	inline friend std::istream& operator >> (std::istream& in, Matrix& a)
	{
		for (size_t i{}; i < a.rows; ++i)
		{
			for (size_t j{}; j < a.cols; ++j)
			{
				std::getline(in, a.data[i][j]);
			}
		}
		return in;
	}

	Matrix Trans()const
	{
		Matrix trans(cols, rows);
		for (size_t i{}; i < cols; ++i)
		{
			for (size_t j{}; j < rows; ++j)
			{
				trans.data[i][j] = data[j][i];
			}
		}
		return trans;
	}
	static Matrix Identity(size_t size)
	{
		Matrix ed(size, size, "0");
		for (size_t i{}; i < size; ++i)
		{
			ed.data[i][i] = "1";
		}
		return ed;
	}

	size_t GetCols()const
	{
		return cols;
	}
	size_t GetRows()const
	{
		return rows;
	}
};
#endif