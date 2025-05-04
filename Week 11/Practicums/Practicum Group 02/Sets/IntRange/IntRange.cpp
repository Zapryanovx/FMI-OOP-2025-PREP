#include "IntRange.h"

IntRange::IntRange(int start, int end)
{
	if (start > end)
	{
		throw std::invalid_argument("start > end");
	}

	this->start = start;
	this->end = end;
}

bool IntRange::member(int x) const
{
	return x >= start && x <= end;
}

int IntRange::get(int i) const
{
	if (i < 1)
	{
		throw std::invalid_argument("invalid index of arg");
	}

	if (start + i - 1 > end)
	{
		throw std::out_of_range("ith el is > than end");
	}

	return start + i - 1;
}

bool IntRange::isSubsetOf(const IntSet* s) const
{
	for (size_t i = start; i <= end; i++)
	{
		if (!s->member(i))
		{
			return false;
		}
	}
	
	return true;
}

bool IntRange::intersects(const IntSet* s) const
{
	for (size_t i = start; i <= end; i++)
	{
		if (s->member(i))
		{
			return true;
		}
	}

	return false;
}

void IntRange::print() const
{
	std::cout << "<<<<< Int Range >>>>>" << std::endl;
	for (size_t i = start; i <= end; i++)
	{
		std::cout << i;

		if (i != end)
		{
			std::cout << " ";
		}
	}

	std::cout << std::endl;
}