#ifndef STUDENT_H
#define STUDENT_H
#include <iostream>
#include <string>
#include <random>
class Student 
{
protected:
	int GenerateId();
	const int id{GenerateId()};
	std::string name;
	int course;
	int group;
	const int card_id{ GenerateId() };
public:
	Student() = delete;
	Student(std::string, int, int);
	Student(const Student&);
	~Student() = default;
	void SetName(std::string);
	void SetCourse(int);
	void SetGroup(int);
	std::string GetName();
	int GetCourse();
	int GetGroup();
	friend std::ostream& operator <<(std::ostream& out, Student);
};
#endif