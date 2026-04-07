#ifndef ARENDFOOTBALLMAN_H
#define ARENDFOOTBALLMAN_H
#include "Footballman.h"
class ArendFootballman :public Footballman
{
private:
	int amount_of_clubs;
public:
	ArendFootballman();
	ArendFootballman(char*, Species, int, int);
	explicit ArendFootballman(ArendFootballman&&);
	explicit ArendFootballman(const ArendFootballman&);
	~ArendFootballman();
	ArendFootballman& operator = (const ArendFootballman&);
	ArendFootballman& operator = (ArendFootballman&&);
	friend std::ostream& operator <<(std::ostream&, ArendFootballman);
	void SetAmount(int);
	int GetAmount();
};
#endif