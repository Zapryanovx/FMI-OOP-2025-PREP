#include "PrintableDoubleArray.h"
#include "SaveableDoubleArray.h"
#include "ModifiableDoubleArray.h"

int main()
{

	double arr[5] = { 1 ,2 ,3 ,4 ,5 };
	PrintableDoubleArray pd1(arr, 5);
	std::cout << pd1 << std::endl;

	SaveableDoubleArray sda(arr, 5);
	sda.writeToBinary("text.bin");

	SaveableDoubleArray sda2(arr, 5);
	sda2.readFromBinary("text.bin");
	for (size_t i = 0; i < 5; i++)
	{
		std::cout << sda2[i] << " ";
	}
	std::cout << std::endl;

	ModifiableDoubleArray mda(arr, 5);
	std::cout << mda.last() << " ";
	mda.push_back(3);
	mda.push_back(4);
	mda.pop_back();
	std::cout << mda.last();
		
	return 0;

}
