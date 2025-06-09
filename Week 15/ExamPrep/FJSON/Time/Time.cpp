#include "Time.h"

Time::Time(unsigned hour, unsigned mins) {
	setTime(hour, mins);
}

void Time::setTime(unsigned hour, unsigned mins) {
	if (hour > TimeConstants::MAX_HOURS || mins > TimeConstants::MAX_MINS) {
		this->hour = 0;
		this->mins = 0;
	}

	this->hour = hour;
	this->mins = mins;
}

MyString Time::generateFormat() const {

	MyString res;
	if (hour < 10) {
		res += "0";
		res += std::to_string(hour).c_str();
	}

	else {
		res += std::to_string(hour).c_str();
	}

	res += ":";

	if (mins < 10) {
		res += "0";
		res += std::to_string(mins).c_str();
	}

	else {
		res += std::to_string(mins).c_str();
	}

	return res;
}
