#include "Base.h"
#include "Linear.h"
Linear::Linear(double k, double c)
{
	a = k;
	b = c;
}
Linear::Linear(const Linear& y)
{
	a = y.a;
	b = y.b;
}
Linear::Linear(Linear&& y)
{
	a = y.a;
	y.a = 0;
	b = y.b;
	y.b = 0;
}
Linear& Linear:: operator = (const Linear& y)
{
	if (this != &y)
	{
		a = y.a;
		b = y.b;
	}
	return *this;
}
void Linear::Print(std::ostream& out)
{
	/*std::string equation;
	if (a != 1)
	{
		equation += std::to_string(a);
	}
	equation += "x ";
	if (b != 0)
	{
		if (b > 0)
		{
			equation += "+ ";
		}
		equation += std::to_string(b);
	}
	out << equation << '\n';*/
	if (b > 0)
	{
		out << a << "x + " << b << '\n';
	}
	else if (b < 0)
	{
		out << a << "x " << b << '\n';
	}
	else
	{
		out << a << "x\n";
	}
}
void Linear::Solve(std::ostream& out)
{
	double result{ 0.0 };
	result = -b / a;
	if (a == 0 && b != 0)
	{
		throw std::invalid_argument("no roots\n");
	}
	if (a == 0 && b == 0)
	{
		throw std::invalid_argument("endless amount of roots\n");
	}
	out << result << '\n';
}
double Linear::GetSenior()
{
	return a;
}
double Linear::GetBCoef()
{
	return b;
}