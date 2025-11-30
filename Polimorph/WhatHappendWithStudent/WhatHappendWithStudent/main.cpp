#include "Student.h"
#include "FirstSession.h"
#include "SecondSession.h"
#include "Second.cpp"
int main()
{
	int marks1[4] = { 7, 8, 9, 10 };
	int marks2[4] = { 5, 6, 7, 8 };
	int marks3[4] = { 4, 4, 5, 6 };
	int marks4[4] = { 9, 10, 9, 8 };

	int marks5[5] = { 6, 7, 8, 9, 10 };
	int marks6[5] = { 5, 5, 6, 7, 8 };
	int marks7[5] = { 10, 9, 8, 7, 6 };
	int marks8[5] = { 4, 6, 8, 9, 10 };

	Student_second_s a{ "Serega", 2, 1 , marks1 , marks5};
	Student_second_s b{ "Gleb",2,1, marks2,  marks6 };
	Student_second_s c{ "Sanya",2,2, marks3,  marks7 };
	Student_second_s d{ "Jamal",2,3, marks4,  marks8 };

	Student_second_s* array = new Student_second_s[4]{a,b,c,d};
	for (int i{}; i < 4; ++i)
	{
		std::cout << array[i] << array[i].CountAverage()<<'\n';
	}
	std::cout<< CountAverageFirstForGroup(array)<<'\n'<< CountAverageSecondForGroup(array);
	return 0;
}