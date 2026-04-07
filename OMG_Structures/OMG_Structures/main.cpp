#include <iostream>
#include <string>
int main() 
{
	double n{0.0};
	std::cin >> n;
	std::string number{std::to_string(n)};
	size_t begin{ number.find_first_of('.') + 1};
	size_t end{};
	size_t counter{};
	while (begin != std::string::npos)
	{
		end = number.find_first_of('0', begin);
		if (end == std::string::npos)
		{
			end = number.length();
		}
		counter += end - begin;
		begin = number.find_first_not_of('0', end);
	}
	std::cout << counter;
	return 0;
}