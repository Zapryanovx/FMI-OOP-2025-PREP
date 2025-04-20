#pragma once
#include <iostream>

class ArithmeticProgression
{
public:
	ArithmeticProgression() = default;
	ArithmeticProgression(int a1, int d);

	ArithmeticProgression& operator+=(const ArithmeticProgression& other);
	ArithmeticProgression& operator-=(const ArithmeticProgression& other);
	ArithmeticProgression& operator&=(unsigned num);

	int operator[](int n) const;
	int operator()(int n) const;

private:
	int a1 = 1;
	int d = 1;
};

ArithmeticProgression& operator+(const ArithmeticProgression& lhs, const ArithmeticProgression& rhs);
ArithmeticProgression& operator-(const ArithmeticProgression& lhs, const ArithmeticProgression& rhs);
ArithmeticProgression& operator&(const ArithmeticProgression& ap, int num);
ArithmeticProgression& operator&(unsigned num, const ArithmeticProgression& ap);
