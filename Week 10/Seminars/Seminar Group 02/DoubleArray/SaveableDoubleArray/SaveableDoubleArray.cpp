#include "SaveableDoubleArray.h"

SaveableDoubleArray::SaveableDoubleArray(double* arr, size_t size) : DoubleArray(arr, size) {}

void SaveableDoubleArray::writeToBinary(const char* fileName)
{
	if (!fileName)
	{
		throw std::invalid_argument("invalid file name");
	}

	std::ofstream ofs(fileName, std::ios::binary);
	if (!ofs.is_open())
	{
		throw std::exception("cannot be opened");
	}

	writeToBinary(ofs);
	ofs.close();
}

void SaveableDoubleArray::readFromBinary(const char* fileName)
{
	if (!fileName)
	{
		throw std::invalid_argument("invalid file name");
	}

	std::ifstream ifs(fileName, std::ios::binary);
	if (!ifs.is_open())
	{
		throw std::exception("cannot be opened");
	}

	readFromBinary(ifs);
	ifs.close();
}

void SaveableDoubleArray::writeToBinary(std::ofstream& ofs)
{
	size_t len = getSize();
	const double* data = getArr();
	
	ofs.write((const char*)&len, sizeof(size_t));
	ofs.write((const char*)data, len * sizeof(double));
}

void SaveableDoubleArray::readFromBinary(std::ifstream& ifs)
{
	size_t len;
	ifs.read((char*)&len, sizeof(size_t));

	double* data = new double[len];
	ifs.read((char*)data, len * sizeof(double));

	SaveableDoubleArray res(data, len);
	*this = res;

}

