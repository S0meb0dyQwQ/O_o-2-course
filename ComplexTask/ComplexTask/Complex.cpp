#include "Base.h"
Complex Complex:: operator = (const Complex& a)
{
	if (this != &a)
	{
		this->im = a.im;
		this->re = a.re;
	}
	return *this;
}
Complex Complex:: operator = (Complex&& a) 
{
	this->im = a.im;
	this->re = a.re;
	a.im = 0;
	a.re = 0;
	return *this;
}
Complex Complex:: operator + (const Complex& a)
{
	return Complex(this->re + a.re, this->im + a.im);
}
bool Complex:: operator ==(const Complex& a) 
{
	return this->re == a.re && this->im == a.im;
}
bool Complex:: operator != (const Complex& a)
{
	return !(*this == a);
}
Complex Complex:: operator +=(const Complex& a)
{
	return *this = *this + a;
}
Complex operator +=(Complex& a, double b)
{
	return a += Complex(b, 0);
}
Complex Complex:: operator -=(const Complex& a)
{
	return *this += -a;
}
Complex operator -=(Complex& a, double b)
{
	return a += -b;
}
Complex Complex:: operator *=(const Complex& a)
{
	return *this = *this * a;
}
Complex operator *=(Complex& a, double b)
{
	return a *= Complex(b, 0);
}
Complex Complex:: operator /=(const Complex& a)
{
	return *this *= a.reverse();
}
Complex operator /=(Complex& a, double b)
{
	return a *= (1/b);
}
Complex& operator ++(Complex& a)
{
	a += 1.0;
	return a;
}
Complex Complex:: operator ++(int)
{
	Complex temp = *this;
	++(*this);
	return temp;
}
Complex& operator --(Complex& a)
{
	a -= 1.0;
	return a;
}
Complex Complex:: operator --(int)
{
	Complex temp = *this;
	--(*this);
	return temp;
}
Complex Complex:: operator - (const Complex& a)
{
	return (*this) + (-a);
}
Complex Complex:: operator * (const Complex& a)
{
	return Complex((this->re * a.re) - (this->im * a.im), (this->im * a.re) + (this->re * a.im));
}
Complex Complex:: opposite()const
{
	return Complex(this->re, -this->im);
}
Complex operator /(const Complex& a, double b)
{
	if (b == 0) 
	{
		throw std::invalid_argument("division by zero");
	}
	return Complex(a.re / b, a.im / b);
}
Complex operator - (const Complex& a)
{
	return Complex(-a.re, -a.im);
}
Complex Complex:: operator /(const Complex& a)
{
	return (*this) * a.reverse();
}
double Complex:: module()const
{
	return sqrt(pow(this->re, 2) + pow(this->im, 2));
}
Complex Complex:: reverse()const
{
	if ((*this).module() == 0) 
	{
		throw std::invalid_argument("division by zero");
	}
	return (*this).opposite() / (*this).module();
}
double Complex:: argument()const
{
	if ((*this).module() == 0)
	{
		throw std::invalid_argument("division by zero");
	}
	return sin(this->im / (*this).module());
}
Complex Complex:: sqrtcomplex()const
{
	return Complex(sqrt(this->re + (*this).module()), sqrt(-this->re + (*this).module()));
}
std::ostream& operator <<(std::ostream& out, const Complex& a)
{
	if (a.im > 0)
		return out << a.re << '+' << a.im << 'i';
	else if (a.im < 0)
		return out << a.re << a.im << 'i';
	else
		return out << a.re;
}
std::istream& operator >>(std::istream& in, Complex& a)
{
	return in >> a.re >> a.im;
}
Complex:: Complex()
{
	this->re = 0.0;
	this->im = 0.0;
}
Complex:: Complex(Complex&& other) 
{
	this->re = other.re;
	this->im = other.im;
	other.im = 0;
	other.re = 0;
}
Complex::Complex(double a, double b)
{
	this->re = a;
	this->im = b;
}
Complex::Complex(const Complex& c)
{
	this->re = c.re;
	this->im = c.im;
}
Complex::~Complex() {}