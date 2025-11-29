#ifndef LINEAR_H
#define LINEAR_H
#include "Base.h"
class Linear : public Equation 
{
private:
	double a;
	double b;
public:
	Linear(double = 1, double = 0);
	~Linear() {};
	Linear(const Linear&);
	Linear(Linear&&);
	Linear& operator = (const Linear&);
	void Print(std::ostream& out)override;
	void Solve(std::ostream& out)override;
	double GetSenior()override;
	double GetBCoef();
};

#endif;