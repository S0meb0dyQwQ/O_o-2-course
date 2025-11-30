#ifndef SECONDSESSION_H
#define SECONDSESSION_H
#include "FirstSession.h"
class Student_second_s : public Student_first_s
{
private:
	int* second_marks = new int[5];
public:
	Student_second_s() = delete;
	Student_second_s(std::string, int, int, int*, int*);
	Student_second_s(const Student_second_s&);
	~Student_second_s() = default;
	void SetSecondMarks(int, int);
	int GetSecondMarks(int);
	friend std::ostream& operator <<(std::ostream& out, Student_second_s);
	double CountAverage()override;
};
double CountAverageFirstForGroup(Student_second_s*);
double CountAverageSecondForGroup(Student_second_s*);
#endif