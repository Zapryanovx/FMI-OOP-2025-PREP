#pragma once
#include "StudentDB.h"

typedef bool(*filtercrit)(const Student& st);

class FilteredStudentDB: public StudentDB
{
public:
	FilteredStudentDB();

	void filter(filtercrit filter);
	void limit(unsigned n);
};

