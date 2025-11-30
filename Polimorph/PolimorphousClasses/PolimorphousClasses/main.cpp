#include"Student.h"
#include "Person.h"
#include "Professor.h"
int main()
{
	int size;
	std::cout << "how many people do u have?";
	std::cin >> size;
	char choice;
	int i = 0;
	Student student;
	Professor teacher;
	Person** people = new Person*[size];
	while (i < size) {

		std::cout << "who do u want to input? (s/p)\n";
		std::cin >> choice;
		switch (choice)
		{
		case 's':
			people[i] = new Student(MakeStudent());
			break;
		case 'p':
			people[i] = new Professor(MakeProfessor());
			break;
		default:
			std::cout << "wrong choice. try s or p\n";
			break;
		}
		++i;
	}
	std::cout << "here are students\n";
	MakeStudentList(people,size);
	std::cout << "here are professors\n";
	MakeProfessorList(people, size);
	return 0;
}