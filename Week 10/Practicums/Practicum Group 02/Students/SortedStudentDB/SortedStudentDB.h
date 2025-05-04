#pragma once
#include "StudentDB.h"

typedef bool(*compare)(const Student& lhs, const Student& rhs);

class SortedStudentDB: public StudentDB
{
public:
	SortedStudentDB();

	void sortBy(compare cmp);
};

