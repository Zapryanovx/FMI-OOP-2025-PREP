#pragma once
#include "DoubleArray.h"
#include <fstream>

class PrintableDoubleArray: public DoubleArray
{
public:
	PrintableDoubleArray(const double* arr, size_t size);

	friend std::istream& operator>>(std::istream& is, PrintableDoubleArray& pda);
	friend std::ostream& operator<<(std::ostream& os, const PrintableDoubleArray& pda);
};

