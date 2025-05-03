#include "PrintableDoubleArray.h"

PrintableDoubleArray::PrintableDoubleArray(const double* arr, size_t size): DoubleArray(arr, size) {}

std::istream& operator>>(std::istream& is, PrintableDoubleArray& pda)
{
	size_t len = 0;
	is >> len;

	double* data = new double[len] {};
	for (size_t i = 0; i < len; i++)
	{
		is >> data[i];
	}

	PrintableDoubleArray res(data, len);
	pda = res;

	delete[] data;
	return is;
}

std::ostream& operator<<(std::ostream& os, const PrintableDoubleArray& pda)
{
	os << pda.getSize() << " ";
	for (size_t i = 0; i < pda.getSize(); i++)
	{
		os << pda[i];

		if (i != pda.getSize() - 1)
		{
			os << " ";
		}
	}

	return os;
}