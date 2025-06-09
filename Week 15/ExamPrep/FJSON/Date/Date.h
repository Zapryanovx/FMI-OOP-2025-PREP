#pragma once
#include "MyString.h"
#include <string>  

namespace DateConstants {
	constexpr size_t MAX_DAYS = 31;
	constexpr size_t MAX_MONTHS = 12;
}

class Date
{
public:
	Date(unsigned day, unsigned month, unsigned year);

	MyString generateFormat() const;

private:
	unsigned day;
	unsigned month;
	unsigned year;

	void setYear(unsigned year);
	void setMonth(unsigned month);
	void setDay(unsigned day);

};

