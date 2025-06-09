#include "DateTime.h"

DateTime::DateTime(const Date& date, const Time& time) : date(date), time(time) {};

MyString DateTime::generateFormat() const {
	MyString res;
	res += date.generateFormat();
	res += ", ";
	res += time.generateFormat();
	return res;
}