#pragma once
#include <iostream>

class ComplexNumber
{
public:
	ComplexNumber(double re, double im = 0);

	double getRe() const;
	double getIm() const;

	ComplexNumber& operator+=(const ComplexNumber& other);
	ComplexNumber& operator-=(const ComplexNumber& other);
	ComplexNumber& operator*=(const ComplexNumber& other);
	ComplexNumber& operator/=(const ComplexNumber& other);

	friend std::istream& operator>>(std::istream& is, ComplexNumber& cn);
	friend std::ostream& operator<<(std::ostream& os, const ComplexNumber& cn);

private:
	double re;
	double im;

	ComplexNumber getConjugate() const;
};

ComplexNumber operator+(const ComplexNumber& lhs, const ComplexNumber& rhs);
ComplexNumber operator-(const ComplexNumber& lhs, const ComplexNumber& rhs);
ComplexNumber operator*(const ComplexNumber& lhs, const ComplexNumber& rhs);
ComplexNumber operator/(const ComplexNumber& lhs, const ComplexNumber& rhs);
bool operator!=(const ComplexNumber& lhs, const ComplexNumber& rhs);
bool operator==(const ComplexNumber& lhs, const ComplexNumber& rhs);
