#pragma once
#include "DoubleArray.h"

namespace Helpers
{
	static size_t roundToPowerOfTwo(size_t x)
	{
		x--;                           
		x |= x >> 1;
		x |= x >> 2;
		x |= x >> 4;
		x |= x >> 8;
		x |= x >> 16;
		x |= x >> 32;
		x++;

		return x;
	}
}

class ModifiableDoubleArray: public DoubleArray
{
public:
	ModifiableDoubleArray(const double* arr, size_t size);

	void push_back(double n);
	void pop_back();
	double last() const;

private:
	size_t capacity;

	void resize(size_t newCap);
};

