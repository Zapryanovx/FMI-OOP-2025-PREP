#include "ArithmeticProgression.h"

ArithmeticProgression::ArithmeticProgression(int a1, int d)
{
	this->a1 = a1;
	this->d = d;
}

ArithmeticProgression& ArithmeticProgression::operator+=(const ArithmeticProgression& other)
{
	a1 += other.a1;
	d += other.d;
	return *this;
}

ArithmeticProgression& ArithmeticProgression::operator-=(const ArithmeticProgression& other)
{
	a1 -= other.a1;
	d -= other.d;
	return *this;
}

int ArithmeticProgression::operator[](int n) const
{
	if (n < 1)
	{
		throw std::invalid_argument("invalid n");
	}

	return a1 + (n - 1) * d;
}

ArithmeticProgression& ArithmeticProgression::operator&=(unsigned num)
{
	a1 = (*this)[num];
	return *this;
}

int ArithmeticProgression::operator()(int num) const
{
	return num * (2 * a1 + (num - 1) * d) / 2;
}

ArithmeticProgression& operator+(const ArithmeticProgression& lhs, const ArithmeticProgression& rhs)
{
	ArithmeticProgression res(lhs);
	res += rhs;
	return res;
}

ArithmeticProgression& operator-(const ArithmeticProgression& lhs, const ArithmeticProgression& rhs)
{
	ArithmeticProgression res(lhs);
	res -= rhs;
	return res;
}

ArithmeticProgression& operator&(const ArithmeticProgression& ap, int num)
{
	ArithmeticProgression res(ap);
	res &= num;
	return res;
}

ArithmeticProgression& operator&(unsigned num, const ArithmeticProgression& ap)
{
	ArithmeticProgression res(ap);
	res &= num;
	return res;
}