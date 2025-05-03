#include "Student.h"

Student::Student(const char* name, int age, const char* fn): Person(name, age)
{
	setFn(fn);
}

const char* Student::getFn() const
{
	return fn;
}

void Student::setFn(const char* fn)
{
	if (!fn || this->fn == fn || std::strlen(fn) >= Constants::FN_MAX_SIZE)
	{
		throw std::invalid_argument("invalid fn");
	}

	std::strcpy(this->fn, fn);
}