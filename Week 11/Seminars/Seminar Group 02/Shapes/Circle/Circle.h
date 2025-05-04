#pragma once
#include "Shape.h"

namespace Constants
{
	constexpr double PI = 3.1415;
}

class Circle: public Shape
{
public:
	Circle(int x, int y, double radius);
	
	double getArea() const override;
	double getPer() const override;
	bool isPointIn(int x, int y) const override;

private:
	double radius;
};

