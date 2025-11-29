#include "Base.h"
#include "quadratic.h"
Quadratic::Quadratic(double q, double w, double e)
{
	a = q;
	b = w;
	c = e;
}
Quadratic::Quadratic(const Quadratic& y)
{
	a = y.a;
	b = y.b;
	c = y.c;
}
Quadratic::Quadratic(Quadratic&& y)
{
	a = y.a;
	y.a = 0;
	b = y.b;
	y.b = 0;
	c = y.c;
	y.c = 0;
}
double Quadratic::Disc()
{
	return pow(b, 2) - 4 * a * c;
}
void Quadratic::Print(std::ostream& out)
{
	/*std::string equation;
	if (a != 1)
	{
		equation += std::to_string(a);
	}
	equation += "x^2 ";
	if (b > 0)
	{
		equation += "+ ";
	}
	if (b != 1)
	{
		equation += std::to_string(b);
	}
	equation += "x ";
	if (c > 0)
	{
		equation += "+ ";
	}
	equation += std::to_string(c);
	out << equation << '\n';*/
	//they're both look like trash 
	if (b > 0)
	{
		if (c > 0)
		{
			out << a << "x^2 + " << b << "x + " << c << '\n';
		}
		else if (c < 0)
		{
			out << a << "x^2 + " << b << "x " << c << '\n';
		}
		else
		{
			out << a << "x^2 + " << b << "x" << '\n';
		}
	}
	else if (b < 0)
	{
		if (c > 0)
		{
			out << a << "x^2 " << b << "x + " << c << '\n';
		}
		else if (c < 0)
		{
			out << a << "x^2 " << b << "x " << c << '\n';
		}
		else
		{
			out << a << "x^2 " << b << "x" << '\n';
		}
	}
	else
	{
		if (c > 0)
		{
			out << a << "x^2 + " << c << '\n';
		}
		else if (c < 0)
		{
			out << a << "x^2 " << c << '\n';
		}
		else
		{
			out << a << "x^2\n";
		}
	}
}
void Quadratic::Solve(std::ostream& out)
{
	double disk{ (*this).Disc() };
	if (disk < 0)
	{
		throw std::invalid_argument("no roots\n");
	}
	double res1{};
	double res2{};
	if (disk == 0)
	{
		res1 = -b / (2 * a);
		out << res1 << '\n';
	}
	else
	{
		res1 = (-b + sqrt(disk)) / (2 * a);
		res2 = (-b - sqrt(disk)) / (2 * a);
		out << res1 << ", " << res2 << '\n';
	}
}
double Quadratic::GetSenior()
{
	return a;
}
Quadratic& Quadratic::operator = (const Quadratic& y)
{
	if (this != &y)
	{
		a = y.a;
		b = y.b;
		c = y.c;
	}
	return *this;
}