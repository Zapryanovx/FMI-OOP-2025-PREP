#pragma once
#include <iostream>
#include "MyString.h"

class Student
{
public:
	Student();
	Student(const MyString& name, unsigned fn, unsigned course);

	const MyString& getName() const;
	unsigned getFn() const;
	unsigned getCourse() const;

	void print() const;

private:
	MyString name;
	unsigned fn;
	unsigned course;
};

