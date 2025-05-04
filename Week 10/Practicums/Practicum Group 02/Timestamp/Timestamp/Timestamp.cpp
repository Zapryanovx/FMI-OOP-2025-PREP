#include "Timestamp.h"

Timestamp::Timestamp() : Timestamp(0) {}
Timestamp::Timestamp(unsigned long long seconds) : seconds(seconds) {}

unsigned long long Timestamp::getSeconds() const
{
	return seconds;
}


Timestamp& Timestamp::operator+=(unsigned long long seconds)
{
	this->seconds += seconds;
	return *this;
}

std::istream& operator>>(std::istream& is, Timestamp& ts)
{
	is >> ts.seconds;
	return is;
}

std::ostream& operator<<(std::ostream& os, const Timestamp& ts)
{
	return os << ts.seconds;
}