#include "Matrix.h"

int main()
{
	Matrix m1(3, 3);
	Matrix m2(3, 3);

	for (size_t i = 0; i < 3; i++)
	{
		int* temp = m1[1];
		for (size_t j = 0; j < 3; j++)
		{
			temp[j] = 1;
		}
	}

	for (size_t i = 0; i < 3; i++)
	{
		int* temp = m2[1];
		for (size_t j = 0; j < 3; j++)
		{
			temp[j] = 2;
		}
	}

	Matrix mul = m1 * m2;
	mul.print();

	Matrix m1Copy(m1);
	m1Copy.print();

	std::cout << (m1Copy == m1) << std::endl << std::endl;

	m1Copy += m1;
	m1Copy.print();

	if (!m1Copy)
	{
		std::cout << "not zero";
	}

	return 0;

}