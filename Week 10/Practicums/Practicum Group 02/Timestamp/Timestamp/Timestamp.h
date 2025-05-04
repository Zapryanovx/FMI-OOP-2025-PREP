#pragma once
#include <iostream>
#include <fstream>

class Timestamp
{
public:
	Timestamp();
	Timestamp(unsigned long long seconds);

	unsigned long long getSeconds() const;
	
	Timestamp& operator+=(unsigned long long seconds);

	friend std::istream& operator>>(std::istream& is, Timestamp& ts);
	friend std::ostream& operator<<(std::ostream& os, const Timestamp& ts);

private:
	unsigned long long seconds;
};

