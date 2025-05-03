#pragma once
#include "Person.h"

class Teacher: public Person
{
public:

	Teacher(const char* name, int age, const char* const* subjects, size_t size);

	Teacher(const Teacher& other);
	Teacher& operator=(const Teacher& other);

	Teacher(Teacher&& other) noexcept;
	Teacher& operator=(Teacher&& other) noexcept;

	~Teacher();

private:
	char** subjects;
	size_t size;

	void copyFrom(const Teacher& other);
	void moveFrom(Teacher&& other);
	void free();
};

