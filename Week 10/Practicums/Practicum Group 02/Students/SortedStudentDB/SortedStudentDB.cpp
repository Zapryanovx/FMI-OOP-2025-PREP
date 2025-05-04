#include "SortedStudentDB.h"

SortedStudentDB::SortedStudentDB() : StudentDB() {}

void SortedStudentDB::sortBy(compare cmp)
{
	for (size_t i = 0; i < getSize() - 1; i++)
	{
		size_t minIdx = i;
		for (size_t j = i + 1; j < getSize(); j++)
		{
			if (cmp(*getStudents()[j], *getStudents()[minIdx]))
			{
				minIdx = j;
			}
		}

		if (minIdx != i)
		{
			swapStudents(i, minIdx);
		}
	}
}
