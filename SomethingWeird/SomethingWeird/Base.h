#ifndef BASE_H
#define BASE_H
#include <iostream>
#include <cstdint>
#include <cmath>
#include <string>
class Fraction 
{
private:
	uint64_t num{};
	uint64_t denum{1};
	bool neg{ };
	void  Simplify();
public:
	//?
	uint64_t getDenum() const
	{
		return this->denum;
	}
	uint64_t getNum()
	{
		return this->num;
	}
	bool getNeg()const
	{
		return this -> neg;
	}
	void setDenum(const uint64_t denum)
	{
		if (this->denum == 0)
		{
			throw std::logic_error("no no no i can't divide by zero");
		}
		this->denum = denum;
	}
	void setNum(const uint64_t num)
	{
		this->num = num;
	}
	void setNeg(const uint64_t neg)
	{
		this->neg = neg;
	}

	bool operator >(const Fraction& a)
	{
		return pow(-1, this->neg) * (this->num) * a.denum > pow(-1, this->neg) * a.num * (this->denum);
	}
	bool operator <(const Fraction& a)
	{
		return pow(-1, this->neg) * (this->num) * a.denum < pow(-1, this->neg) * a.num * (this->denum);
	}
	bool operator ==(const Fraction& a)
	{
		return pow(-1,this->neg)*(this->num) * a.denum == pow(-1, a.neg) * a.num * (this->denum);
	}
	Fraction operator + (const Fraction& a)
	{
		if (this->neg + a.neg == 0)
		{
			return Fraction((this->num) * a.denum + a.num * (this->denum), (this->denum) * a.denum, this->neg);
		}
		else if((this->num) * a.denum > a.num * (this->denum))
		{
			return Fraction((this->num) * a.denum - a.num * (this->denum), (this->denum) * a.denum, this->neg);
		}
		else 
		{
			return Fraction((this->denum) * a.num - a.denum * (this->num), (this->denum) * a.denum, a.neg);
		}
	}
	Fraction operator - (const Fraction& a)
	{
		return (*this)+(-a);
	}
	friend Fraction operator - (const Fraction& a) 
	{
		return Fraction(a.num,a.denum,!a.neg);
	}
	Fraction operator *(const Fraction& a)
	{
		
		return Fraction(this->num * a.num, this->denum * a.denum, this->neg != a.neg);
	}
	friend Fraction operator~(const Fraction& a)
	{
		return Fraction(a.denum, a.num, a.neg);
	}
	Fraction operator /(const Fraction& a)
	{
		return (*this)*(~a);
	}
	Fraction operator +(const int64_t& a) 
	{
		return (*this) + Fraction (a, 1, a < 0);
	}
	Fraction operator -(const int64_t& a)
	{
		return-(-(*this) + a);
	}
	Fraction operator *(const int64_t& a) 
	{
		return Fraction(this->num * a, this->denum, this->neg*a);
	}
	Fraction operator /(const int64_t& a)
	{
		return ~(~(*this) * a);
	}
	friend Fraction operator --(Fraction& a)
	{
		return a = a - 1; 
	}
	Fraction operator --(int)
	{
		Fraction temp = *this;
		--(*this);
		return temp;
	}
	friend Fraction& operator ++(Fraction& a) //префикс
	{
		return a = a + 1;
	}
	Fraction operator ++(int)//постфикс
	{
		Fraction temp = *this;
		++(*this);
		return temp;
	}
	Fraction& operator +=(const Fraction& rhs)
	{
		return *this = *this + rhs;
	}
	Fraction& operator =(const Fraction& rhs)
	{
		if (this != &rhs)
		{
			this->num = rhs.num;
			this->denum = rhs.denum;
			this->neg = rhs.neg;
		}
		return *this;
	}
	friend std::ostream& operator <<(std::ostream& out, const Fraction& a)
	{
		if (a.num % a.denum == 0)
		{
			return out << pow(-1, a.neg) << "*" << a.num/a.denum << '\n';
		}
		else if (a.num > a.denum)
		{
			return out << pow(-1, a.neg) << "*" << (a.num - (a.num%a.denum))/a.denum<<'(' << a.num % a.denum << "/" << a.denum << ')' << '\n';
		}
		return out << pow(-1, a.neg) << "*" << a.num << "/" << a.denum << '\n';

	}

	operator std::string() const
	{
		std::string fraction;
		//дела
		return fraction;
	}

	/*operator double()const
	{
		return static_cast<double>(this->num )/ (this->denum) * (this->neg ? -1 : 1);
	}*/

	explicit Fraction(const double d) 
	{
		this->num = (int)(d * 100);
		this->denum = 100;
	}

	Fraction()
	{
		std::cout << "input num\n";
		std::cin >> this->num;
		std::cout << "input denum\n";
		std::cin >> this->denum;
		std::cout << "input neg\n";
		std::cin >> this->neg;
		if (denum == 0)
		{
			throw std::logic_error("no no no i can't divide by zero\n");
		}
		std::cout << (*this) << "=";
		Simplify();
		std::cout << (*this);
	}
	Fraction(int num, int denum, bool neg) 
	{
		if (denum == 0)
		{
			throw std::logic_error("no no no i can't divide by zero\n");
		}
		this->num = num;
		this->denum = denum;
		this->neg = neg;
		std::cout << num << "/" <<denum<<"=";
		Simplify();
		std::cout << (*this);
	}

};
uint64_t gcd(uint64_t, uint64_t);
#endif