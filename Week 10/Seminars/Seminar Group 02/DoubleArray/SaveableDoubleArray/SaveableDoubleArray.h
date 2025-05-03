#pragma once
#include "DoubleArray.h"
#include <fstream>

class SaveableDoubleArray: public DoubleArray
{
public:
	SaveableDoubleArray(double* arr, size_t size);

	void writeToBinary(const char* fileName);
	void readFromBinary(const char* fileName);

private:
	
	void writeToBinary(std::ofstream& ofs);
	void readFromBinary(std::ifstream& ifs);
};

