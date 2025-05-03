#pragma once
#include "Person.h"

namespace Constants
{
	constexpr size_t FN_MAX_SIZE = 10;
}

class Student : public Person
{
	Student(const char* name, int age, const char* fn);

	const char* getFn() const;
	void setFn(const char* fn);

private:
	char fn[Constants::FN_MAX_SIZE + 1]{};
};

