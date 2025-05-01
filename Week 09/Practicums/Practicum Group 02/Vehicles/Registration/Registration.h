#pragma once
#include <iostream>
#include <sstream>
#include <stdexcept>
#pragma warning(disable:4996)

namespace Constants
{
	constexpr size_t MAX_SIZE_REGISTRATION = 8;
}

namespace Helpers
{
	static bool isAlpha(char ch)
	{
		return (ch >= 'A' && ch <= 'Z')
			|| (ch >= 'a' && ch <= 'z');
	}

	static bool isDigit(char ch)
	{
		return ch >= '0' && ch <= '9';
	}
}

class Registration
{
public:
	Registration() = delete;
	Registration(const char* number);

	const char* getNumber() const;

private:
	char number[Constants::MAX_SIZE_REGISTRATION + 1]{};

	void setNumber(const char* number);
};

bool operator==(const Registration& lhs, const Registration& rhs);
bool operator!=(const Registration& lhs, const Registration& rhs);

