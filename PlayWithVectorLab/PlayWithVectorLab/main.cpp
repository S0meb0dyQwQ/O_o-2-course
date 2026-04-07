#include <iostream>
#include <vector>
#include <cmath>
void InputVector(std::vector<int>& numbers)
{
	int num;
	std::cout << " Введите числа(для завершения введите не числовое значение):" << '\n';
	while (std::cin>> num)
	{
		numbers.push_back(num);
	}
	std::cin.clear();
	std::cin.ignore();
}
void PrintVector(std::vector<int>& numbers)
{
	std::cout << " Вот ваш массив:";
	for (int el : numbers)
	{
		std::cout << el << '\t';
	}
	std::cout << '\n';
}
int CountSum(std::vector<int>& numbers, int a,int b)
{
	int sum{numbers[a]};
	for (int i{ a + 1}; i < b; ++i)
	{
		sum += numbers[i];
	}
	return sum;
}
bool Condition(int el, int num, bool a)
{
	if (a == 0) 
	{
		return el == num;
	}
	else
	{
		return el > num;
	}
}
int CountNumbers(std::vector<int>& numbers, int n, bool a)
{
	int counter{};
	for (int el : numbers)
	{
		if (Condition(el,n,a))
		{
			++counter;
		}
	}
	return counter;
}
void ReplaceZeros(std::vector<int>& numbers, int sum, int size)
{
	bool zero{0};
	int aver{ sum / size };
	for (int i{}; i < size; ++i)
	{
		if (numbers[i] == 0)
		{
			numbers[i] = aver;
			zero = 1;
		}
	}
	if (zero == 0)
	{
		std::cout << "В вашем векторе нет нулей\n";
	}
}
void PlusSumToNumbers(std::vector<int>& numbers, int sum, int size)
{
	for (int i{}; i < size; ++i)
	{
		numbers[i] += sum;
	}
}
bool IsEven(int a)
{
	return (a & 1) == 0;
}
bool Compare(bool sort,int a, int b)
{
	if (sort == 0)
	{
		return a > b;
	}
	else 
	{
		return a < b;
	}
}
int FindExtremum(std::vector<int>& numbers, bool sort)
{
	int extr{ numbers.front() };
	for (int el : numbers)
	{
		if (Compare(sort,el,extr))
		{
			extr = el;
		}
	}
	return extr;
}
void ChangeNumbers(std::vector<int>& numbers, int size)
{
	int max{ FindExtremum(numbers,0) };
	int min{ FindExtremum(numbers,1) };
	int dif{ max - min };
	bool is_even{ 0 };
	for (int i{}; i < size; ++i)
	{
		if (IsEven(abs(numbers[i]))) 
		{
			numbers[i] = dif;
			is_even = 1;
		}
	}
	if (is_even == 0)
	{
		std::cout << "В вашем векторе все элементы нечетные\n";
	}
}
void MakeAbsVector(std::vector<int>& numbers, int size)
{
	for (int i{}; i < size; ++i)
	{
		numbers[i] = abs(numbers[i]);
	}
}
void EraseSameNumbers(std::vector<int>& numbers, int size)
{
	bool erase{ 0 };
	MakeAbsVector(numbers, size);
	for (int i{size - 1}; i > 0; --i) 
	{
		if (CountNumbers(numbers, numbers[i],0) > 1) 
		{
			numbers.erase(numbers.begin() + i);
			erase = 1;
		}
	}
	if (erase == 0)
	{
		std::cout << "В вашем векторе все элементы по модулю различны\n";
	}
}
void CheckInputNum() {
	if (std::cin.fail()) {
		std::cin.clear();
		std::cin.ignore();
		throw std::runtime_error("Введено нечисловое значение\n");
	}
}
void CheckBorders(int a, int b, int size)
{
	CheckInputNum();
	if (a < 0 || b < 0 || a >= size || b >= size)
	{
		throw std::invalid_argument("Плохие граничные точки\n");
	}
	if (a == b)
	{
		std::cout << "В диапазоне только один элемент\n";
	}
	if (b < a)
	{
		std::swap(a, b);
	}
}
int main() 
{
	try {
		setlocale(LC_ALL, "Russian");
		std::vector<int> numbers;
		InputVector(numbers);
		system("cls");
		if (numbers.empty())
		{
			throw std::invalid_argument("Вектор пустой =(\n");
		}
		PrintVector(numbers);

		long long size{ static_cast<int>(numbers.size()) };
		int sum{ CountSum(numbers,0,size) };
		std::cout << "Вот сумма ваших чисел: " << sum << '\n';

		std::cout << "Количество всех чисел: " << size << '\n';

		int num{};
		int counter{};
		try {

			std::cout << "Введите число: " << '\n';
			std::cin >> num;
			CheckInputNum();
			counter = CountNumbers(numbers, num, 0);
			if (counter == 0)
			{
				std::cout << "Чисел равных вашему нет\n";
			}
			else
			{
				std::cout << "Вот сколько чисел похожих на ваше:" << counter << '\n';
			}
		}
		catch (std::runtime_error& e)
		{
			std::cout << e.what();
		}

		try {

			std::cout << "Введите число: " << '\n';
			std::cin >> num;
			CheckInputNum();
			counter = CountNumbers(numbers, num, 1);
			if (counter == 0)
			{
				std::cout << "Чисел больших чем ваше нету\n";
			}
			else
			{
				std::cout << "Вот сколько чисел больших чем ваше:" << counter << '\n';
			}
		}
		catch (std::runtime_error& e)
		{
			std::cout << e.what();
		}

		ReplaceZeros(numbers, sum, size);
		PrintVector(numbers);

		try {
			int a;
			int b;
			std::cout << " Введите границы вектора: " << '\n';
			std::cin >> a >> b;
			CheckBorders(a, b, size);
			sum = CountSum(numbers, a, b);
			std::cout << "Вот сумма чисел в вашем диапазоне: " << sum << '\n';
			std::cout << "Я добавил к элементам эту сумму\n";
			PlusSumToNumbers(numbers, sum, size);
			PrintVector(numbers);
		}
		catch (std::invalid_argument& e)
		{
			std::cout << e.what();
		}
		catch (std::runtime_error& e)
		{
			std::cout << e.what();
		}

		std::cout << "Поработаемка с четными элементами\n";
		ChangeNumbers(numbers, size);
		PrintVector(numbers);

		std::cout << "Поработаемка с одинаковыми по модулю элементами\n";
		EraseSameNumbers(numbers, size);
		PrintVector(numbers);
	}
	catch (std::invalid_argument& e)
	{
		std::cout << e.what();
	}
	return 0;
}