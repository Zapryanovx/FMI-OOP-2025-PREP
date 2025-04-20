#include "ComplexNumber.h"

ComplexNumber::ComplexNumber(double re, double im): re(re), im(im) {}

double ComplexNumber::getRe() const
{
	return re;
}

double ComplexNumber::getIm() const
{
	return im;
}

ComplexNumber& ComplexNumber::operator+=(const ComplexNumber& other)
{
	re += other.re;
	im += other.im;
	return *this;
}

ComplexNumber& ComplexNumber::operator-=(const ComplexNumber& other)
{
	re -= other.re;
	im -= other.im;
	return *this;
}

ComplexNumber& ComplexNumber::operator*=(const ComplexNumber& other)
{
	re = re * other.re - im * other.im;
	im = im * other.re + re * other.im;
	return *this;
}

ComplexNumber ComplexNumber::getConjugate() const
{
	return ComplexNumber(re, -im);
}


ComplexNumber& ComplexNumber::operator/=(const ComplexNumber& other)
{
	ComplexNumber Conjugated = other.getConjugate();
	ComplexNumber numerator = *this * Conjugated;
	ComplexNumber denominator = other * Conjugated;

	if (denominator.re == 0)
	{
		throw std::runtime_error("Division by zero in complex /= operation.");
	}

	re = numerator.re / denominator.re;
	im = numerator.im / denominator.re;
	return *this;
}

ComplexNumber operator+(const ComplexNumber& lhs, const ComplexNumber& rhs)
{
	ComplexNumber res(lhs);
	res += rhs;
	return res;
}

ComplexNumber operator-(const ComplexNumber& lhs, const ComplexNumber& rhs)
{
	ComplexNumber res(lhs);
	res -= rhs;
	return res;
}

ComplexNumber operator*(const ComplexNumber& lhs, const ComplexNumber& rhs)
{
	ComplexNumber res(lhs);
	res *= rhs;
	return res;
}

ComplexNumber operator/(const ComplexNumber& lhs, const ComplexNumber& rhs)
{
	ComplexNumber res(lhs);
	res /= rhs;
	return res;
}

bool operator==(const ComplexNumber& lhs, const ComplexNumber& rhs)
{
	return lhs.getRe() == rhs.getRe() && lhs.getIm() == rhs.getIm();
}

bool operator!=(const ComplexNumber& lhs, const ComplexNumber& rhs)
{
	return !(lhs == rhs);
}

std::istream& operator>>(std::istream& is, ComplexNumber& cn)
{
	is >> cn.re;
	is.ignore();
	is >> cn.im;
	return is;
}

std::ostream& operator<<(std::ostream& os, const ComplexNumber& cn)
{
	os << cn.re << '+' << cn.im << "i" << std::endl;
	return os;
}