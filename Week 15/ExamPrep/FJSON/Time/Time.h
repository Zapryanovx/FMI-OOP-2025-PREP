#pragma once
#include "MyString.h"
#include <string>  

namespace TimeConstants {
	constexpr size_t MAX_HOURS = 23;
	constexpr size_t MAX_MINS = 59;
}

class Time
{
public:
	Time(unsigned hour, unsigned mins);

	MyString generateFormat() const;

private:
	unsigned hour;
	unsigned mins;

	void setTime(unsigned hour, unsigned mins);
	

};

