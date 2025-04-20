#pragma once
#include <iostream>

typedef int(*pred)(int);

class SpecialCustomFunction
{
public:

	SpecialCustomFunction() = default;
	SpecialCustomFunction(pred func, const int* specials, size_t size);
	SpecialCustomFunction(const SpecialCustomFunction& other);
	SpecialCustomFunction& operator=(const SpecialCustomFunction& other);
	~SpecialCustomFunction();

	int operator()(int val) const;

	SpecialCustomFunction& operator++();
	SpecialCustomFunction operator++(int dummy);

	SpecialCustomFunction& operator--();
	SpecialCustomFunction operator--(int dummy);

	friend SpecialCustomFunction operator!(const SpecialCustomFunction& scf);

private:
	pred func = nullptr;
	int* specials = nullptr;
	size_t size = 0;
	
	void copyFrom(const SpecialCustomFunction& other);
	void free();

	void setFunc(pred func);
	void setSpecials(const int* specials, size_t size);
};

