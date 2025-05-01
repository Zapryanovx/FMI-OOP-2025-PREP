#include "Registration.h"

Registration::Registration(const char* number)
{
	setNumber(number);
}

const char* Registration::getNumber() const
{
	return number;
}

void Registration::setNumber(const char* number)
{
	if (!number || (std::strlen(number) != Constants::MAX_SIZE_REGISTRATION && std::strlen(number) != Constants::MAX_SIZE_REGISTRATION -1))
	{
		throw std::invalid_argument("invalid number");
	}

	bool type = std::strlen(number) == Constants::MAX_SIZE_REGISTRATION ? true : false;
	if (type)
	{
		for (size_t i = 0; i < std::strlen(number); i++)
		{
			if (i == 0 || i == 1 || i == std::strlen(number) - 1 || i == std::strlen(number) - 2)
			{
				if (!Helpers::isAlpha(number[i]))
				{
					throw std::invalid_argument("invalid number");
				}
			}

			else if (!Helpers::isDigit(number[i]))
			{
				throw std::invalid_argument("invalid number");
			}
		}
	}

	else
	{
		for (size_t i = 0; i < std::strlen(number); i++)
		{
			if (i == 0 || i == std::strlen(number) - 1 || i == std::strlen(number) - 2)
			{
				if (!Helpers::isAlpha(number[i]))
				{
					throw std::invalid_argument("invalid number");
				}
			}

			else if (!Helpers::isDigit(number[i]))
			{
				throw std::invalid_argument("invalid number");
			}
		}
	}

	strcpy(this->number, number);
}


bool operator==(const Registration& lhs, const Registration& rhs)
{
	return !std::strcmp(lhs.getNumber(), rhs.getNumber());
}

bool operator!=(const Registration& lhs, const Registration& rhs)
{
	return !(lhs == rhs);
}

