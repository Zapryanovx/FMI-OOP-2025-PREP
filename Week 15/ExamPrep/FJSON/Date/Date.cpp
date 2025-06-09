#include "Date.h"

Date::Date(unsigned day, unsigned month, unsigned year) {
	setDay(day);
	setMonth(month);
	setYear(year);
}

void Date::setYear(unsigned year) {
	this->year = year;
}

void Date::setMonth(unsigned month) {
	if (month >	DateConstants::MAX_MONTHS) {
		std::cout << "invalid month, month was set automatically to 12" << std::endl;
		return;
	}

	this->month = month;
}

void Date::setDay(unsigned day) {
	if (day > DateConstants::MAX_DAYS)
	{
		std::cout << "invalid days, days were set automatically to 31" << std::endl;
	}
	
	this->day = day;
}

MyString Date::generateFormat() const {
	
	MyString res;
	if (day < 10) {
		res += "0";
		res += std::to_string(day).c_str();
	}

	else {
		res += std::to_string(day).c_str();
	}

	res += ".";

	if (month < 10) {
		res += "0";
		res += std::to_string(month).c_str();
	}

	else {
		res += std::to_string(month).c_str();
	}

	res += ".";
	res += std::to_string(year).c_str();
	return res;
}
