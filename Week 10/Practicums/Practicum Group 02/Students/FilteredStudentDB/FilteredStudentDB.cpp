#include "FilteredStudentDB.h"

FilteredStudentDB::FilteredStudentDB(): StudentDB() {}

void FilteredStudentDB::filter(filtercrit filter)
{
	for (size_t i = 0; i < getSize(); i++)
	{
		if (!filter(*getStudents()[i]))
		{
			remove(getStudents()[i]->getFn());
		}
	}
}

void FilteredStudentDB::limit(unsigned n)
{
	if (n > getSize())
	{
		return; //save all
	}

	size_t removeCount = getSize() - n;
	size_t last = getSize() - 1;
	while (removeCount--)
	{
		remove(getStudents()[last--]->getFn());
	}
}