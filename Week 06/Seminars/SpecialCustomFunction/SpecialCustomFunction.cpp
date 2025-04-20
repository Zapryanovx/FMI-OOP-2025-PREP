#include "SpecialCustomFunction.h"


void SpecialCustomFunction::copyFrom(const SpecialCustomFunction& other)
{
	func = other.func;
	size = other.size;

	specials = new int[size] {};
	for (size_t i = 0; i < size; i++)
	{
		specials[i] = other.specials[i];
	}
}

void SpecialCustomFunction::free()
{
	delete[] specials;
	specials = nullptr;

	size = 0;
	
	func = nullptr;
}

void SpecialCustomFunction::setFunc(pred func)
{
	this->func = func;
}

void SpecialCustomFunction::setSpecials(const int* specials, size_t size)
{
	if (!specials || size == 0 || this->specials == specials)
	{
		return;
	}

	this->size = size;
	this->specials = new int[size] {};
	for (size_t i = 0; i < size; i++)
	{
		this->specials[i] = specials[i];
	}
}

SpecialCustomFunction::SpecialCustomFunction(pred func, const int* specials, size_t size)
{
	setFunc(func);
	setSpecials(specials, size);
}

SpecialCustomFunction::SpecialCustomFunction(const SpecialCustomFunction& other)
{
	copyFrom(other);
}

SpecialCustomFunction& SpecialCustomFunction::operator=(const SpecialCustomFunction& other)
{
	if (this != &other)
	{
		free();
		copyFrom(other);
	}

	return *this;
}

SpecialCustomFunction::~SpecialCustomFunction()
{
	free();
}

int SpecialCustomFunction::operator()(int val) const
{
	for (size_t i = 0; i < size; i++)
	{
		if (specials[i] == val)
		{
			return val * val;
		}
	}

	return func(val);
}

SpecialCustomFunction& SpecialCustomFunction::operator++()
{
	for (size_t i = 0; i < size; i++)
	{
		specials[i]++;
	}

	return *this;
}

SpecialCustomFunction SpecialCustomFunction::operator++(int dummy)
{
	SpecialCustomFunction cpy(*this);
	for (size_t i = 0; i < size; i++)
	{
		specials[i]++;
	}

	return cpy;
}

SpecialCustomFunction& SpecialCustomFunction::operator--()
{
	for (size_t i = 0; i < size; i++)
	{
		specials[i]--;
	}

	return *this;
}

SpecialCustomFunction SpecialCustomFunction::operator--(int dummy)
{
	SpecialCustomFunction cpy(*this);
	for (size_t i = 0; i < size; i++)
	{
		specials[i]--;
	}

	return cpy;
}

SpecialCustomFunction operator!(const SpecialCustomFunction& scf)
{
	SpecialCustomFunction res(scf);
	for (size_t i = 0; i < res.size; i++)
	{
		res.specials[i] = -res.specials[i];
	}

	return res;
}