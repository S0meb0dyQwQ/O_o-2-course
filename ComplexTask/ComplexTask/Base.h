#ifndef BASE_H
#define BASE_H
#include <iostream>
#include <cmath>
class Complex
{
private:
	double im{ 0.0 };
	double re{ 0.0 };
public:
	Complex operator + (const Complex& a);
	Complex operator - (const Complex& a);
	Complex operator * (const Complex& a);
	Complex operator / (const Complex& a);
	friend Complex operator - (const Complex& a);
	bool operator ==(const Complex& a);
	bool operator != (const Complex& a);
	Complex operator +=(const Complex& a);
	friend Complex operator +=(Complex& a, double b);
	Complex operator -=(const Complex& a);
	friend Complex operator -=(Complex& a, double b);
	Complex operator *=(const Complex& a);
	friend Complex operator *=(Complex& a, double b);
	Complex operator /=(const Complex& a);
	friend Complex operator /=(Complex& a, double b);
	friend Complex& operator ++(Complex& a);
	Complex operator ++(int);
	friend Complex& operator --(Complex& a);
	Complex operator --(int);
	Complex opposite()const;
	friend Complex operator /(const Complex& a, double b);
	double module()const;
	Complex reverse()const;
	double argument()const;
	Complex sqrtcomplex()const;
	friend std::ostream& operator <<(std::ostream& out, const Complex& a);
	Complex();
	Complex(double a, double b);
	Complex(const Complex& c);
	~Complex();
};
#endif
