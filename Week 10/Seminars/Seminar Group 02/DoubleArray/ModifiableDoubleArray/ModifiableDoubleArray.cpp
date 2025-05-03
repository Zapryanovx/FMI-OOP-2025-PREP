#include "ModifiableDoubleArray.h"

ModifiableDoubleArray::ModifiableDoubleArray(const double* arr, size_t size) : DoubleArray(arr, size) 
{
	capacity = Helpers::roundToPowerOfTwo(size);
}

void ModifiableDoubleArray::push_back(double n)
{
	if (getSize() == capacity)
	{
		resize(capacity * 2);
	}

	size_t len = getSize() + 1;
	double* newArr = new double[len] {};

	for (size_t i = 0; i < getSize(); i++)
	{
		newArr[i] = getArr()[i];
	}
	newArr[len - 1] = n;

	ModifiableDoubleArray res(newArr, len);
	res.capacity = capacity;
	*this = res;
}

void ModifiableDoubleArray::pop_back()
{
	size_t len = getSize() - 1;
	double* newArr = new double[len] {};

	for (size_t i = 0; i < len; i++)
	{
		newArr[i] = getArr()[i];
	}

	ModifiableDoubleArray res(newArr, len);
	res.capacity = capacity;
	*this = res;
}

double ModifiableDoubleArray::last() const
{
	return getArr()[getSize() - 1];
}

void ModifiableDoubleArray::resize(size_t newCap)
{
	double* newArr = new double[newCap] {};

	for (size_t i = 0; i < getSize(); i++)
	{
		newArr[i] = getArr()[i];
	}

	ModifiableDoubleArray res(newArr, getSize());
	res.capacity = capacity;
	*this = res;
}