#include "MulString.h"


MulString::MulString(const MyString& str) : str(str) {};
MulString::MulString(const char* data) : str(data) {};

MulString& MulString::operator*=(int k)
{
	MyString cpy = str;
	for (int i = 1; i < k; i++) 
	{
		str += cpy;
	}

	return *this;
}

unsigned MulString::calcWeight() const
{
	unsigned res = 0;
	for (size_t i = 0; i < str.getSize(); i++)
	{
		res += str[i];
	}

	return res;
}

MulString& MulString::operator%=(const MulString& other)
{
	bool histogram[256]{};

	for (size_t i = 0; i < str.getSize(); i++)
	{
		unsigned code = str[i];
		histogram[code] = true;
	}

	for (size_t i = 0; i < other.str.getSize(); i++)
	{
		unsigned code = other.str[i];
		if (!histogram[code])
		{
			str += other.str[i];
		}
	}

	return *this;
}

MulString operator*(const MulString& mulstr, int k)
{
	MulString res(mulstr);
	res *= k;
	return res;
}

MulString operator*(int k, const MulString& mulstr)
{
	MulString res(mulstr);
	res *= k;
	return res;
}

std::ostream& operator<<(std::ostream& os, const MulString& mulstr)
{
	os << mulstr.str.c_str() << std::endl;;
	return os;
}

MulString operator%(const MulString& lhs, const MulString& rhs)
{
	MulString res(lhs);
	res %= rhs;
	return res;
}

bool operator!=(const MulString& lhs, const MulString& rhs)
{
	return lhs.calcWeight() != rhs.calcWeight();
}