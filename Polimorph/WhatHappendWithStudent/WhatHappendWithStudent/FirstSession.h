#ifndef FIRSTSESSION_H
#define FIRSTSESSION_H
#include "Student.h"
class Student_first_s: public Student
{
protected:
	int* first_marks = new int[4];;
public:
	Student_first_s() = delete;
	Student_first_s(std::string, int, int, int*);
	Student_first_s(const Student_first_s&);
	~Student_first_s() = default;
	void SetFirstMark(int,int);
	int GetFirstMark(int);
	friend std::ostream& operator <<(std::ostream& out, Student_first_s);
	virtual double CountAverage();
};
#endif