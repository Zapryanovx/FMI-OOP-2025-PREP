#pragma once
#include "MyString.h"

class MulString
{
public:
	MulString(const MyString& str);
	MulString(const char* data);

	MulString& operator*=(int k);
	MulString& operator%=(const MulString& other);

	unsigned calcWeight() const;

	friend std::ostream& operator<<(std::ostream& os, const MulString& mulstr);

private:
	MyString str;
};

MulString operator*(const MulString& mulstr, int k);
MulString operator*(int k, const MulString& mulstr);
MulString operator%(const MulString& lhs, const MulString& rhs);
bool operator!=(const MulString& lhs, const MulString& rhs);
