#ifndef QUADRATIC_H
#define QUADRATIC_H
#include "Base.h"
class Quadratic :public Equation
{
private:
	double a;
	double b;
	double c;
public:
	Quadratic(double = 1, double = 0, double = 0);
	~Quadratic() {};
	Quadratic(const Quadratic&);
	Quadratic(Quadratic&&);
	Quadratic& operator = (const Quadratic&);
	void Print(std::ostream& out)override;
	void Solve(std::ostream& out)override;
	double GetSenior()override;
	double Disc();
};
#endif