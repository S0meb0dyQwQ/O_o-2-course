#include "Base.h"
uint64_t gcd(uint64_t a, uint64_t b)
{
	if (b == 0)
	{ return a; }
	return gcd(b, a % b);
}

void Fraction::Simplify() 
{
	uint64_t c{gcd(num,denum)};
	this ->num /= c;
	this ->denum /= c;
}
