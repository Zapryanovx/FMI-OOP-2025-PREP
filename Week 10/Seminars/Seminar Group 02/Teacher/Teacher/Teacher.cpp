#include "Teacher.h"

static char** copyArrayOfString(const char* const* strings, size_t size)
{
	char** res = new char* [size];
	for (size_t i = 0; i < size; i++)
	{
		res[i] = new char[std::strlen(strings[i]) + 1] {};
		strcpy(res[i], strings[i]);
	}

	return res;
}

static void freeArrayOfString(char** strings, size_t size)
{
	for (size_t i = 0; i < size; i++)
	{
		delete[] strings[i];
	}

	delete[] strings;
}

void Teacher::copyFrom(const Teacher& other)
{
	subjects = copyArrayOfString(other.subjects, other.size);
	size = other.size;
}

void Teacher::moveFrom(Teacher&& other)
{
	subjects = other.subjects;
	other.subjects = nullptr;

	size = other.size;
	other.size = 0;
}

void Teacher::free()
{
	freeArrayOfString(subjects, size);
	size = 0;
}

Teacher::Teacher(const char* name, int age, const char* const* subjects, size_t size) : Person(name, age)
{
	this->subjects = copyArrayOfString(subjects, size);
	this->size = size;
}

Teacher::Teacher(const Teacher& other): Person(other)
{
	copyFrom(other);
}

Teacher& Teacher::operator=(const Teacher& other)
{
	if (this != &other)
	{
		Person::operator=(other);
		free();
		copyFrom(other);
	}

	return *this;
}

Teacher::Teacher(Teacher&& other) noexcept : Person(std::move(other))
{
	moveFrom(std::move(other));
}

Teacher& Teacher::operator=(Teacher&& other) noexcept
{
	if (this != &other)
	{
		Person::operator=(std::move(other));
		free();
		moveFrom(std::move(other));
	}

	return *this;
}

Teacher::~Teacher()
{
	free();
}