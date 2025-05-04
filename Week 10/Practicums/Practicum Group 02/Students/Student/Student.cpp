#include "Student.h"

Student::Student() : Student(MyString("default"), 123, 1) {}

Student::Student(const MyString& name, unsigned fn, unsigned course): name(name), fn(fn), course(course){}

const MyString& Student::getName() const
{
	return name;
}

unsigned Student::getFn() const
{
	return fn;
}

unsigned Student::getCourse() const
{
	return course;
}

void Student::print() const
{
	std::cout << name.c_str() << " " << fn << " " << course << std::endl;
}
