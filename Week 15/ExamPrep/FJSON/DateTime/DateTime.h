#pragma once
#include "Date.h"
#include "Time.h"
class DateTime
{
public:
	DateTime(const Date& date, const Time& time);

	MyString generateFormat() const;

private:
	Date date;
	Time time;

};

