#pragma once
#include <iostream>

class Container
{
public:
	virtual bool member(double x) const = 0;
	virtual double& operator[](size_t i) = 0;
	virtual const double& operator[](size_t i) const = 0;
	virtual int count() const = 0;
	virtual void write() const = 0;
	virtual ~Container() = default;
};

