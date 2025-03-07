#include <iostream>
#include <fstream>

int getSizeOfFile(std::ifstream& inFile)
{
	size_t curr = inFile.tellg();
	inFile.seekg(0, std::ios::end);
	size_t size = inFile.tellg();
	
	inFile.seekg(curr);
	return size;
}

int getSizeOfFile(const char* fileName)
{
	if (!fileName)
	{
		return -1;
	}

	std::ifstream inFile(fileName, std::ios::binary | std::ios::in);
	if (!inFile.is_open())
	{
		return -1;
	}

	return getSizeOfFile(inFile);
}

int getArrSize(std::ifstream& inFile)
{
	return getSizeOfFile(inFile) / sizeof(unsigned);
}

int getArrSize(const char* fileName)
{
	if (!fileName)
	{
		return -1;
	}

	std::ifstream inFile(fileName, std::ios::binary | std::ios::in);
	if (!inFile.is_open())
	{
		return -1;
	}

	return getArrSize(inFile);
}

int getKey(std::ifstream& inFile)
{
	uint8_t key = 0;
	inFile.read((char*)&key, sizeof(uint8_t));
	return key;
}

int getKey(const char* fileName)
{
	if (!fileName)
	{
		return -1;
	}

	std::ifstream inFile(fileName, std::ios::binary | std::ios::in);
	if (!inFile.is_open())
	{
		return -1;
	}

	return getKey(inFile);
}

void readNumbers(std::ifstream& inFile, unsigned* arr, int size)
{
	inFile.read((char*)arr, sizeof(unsigned) * size);
}

void readNumbers(const char* fileName, unsigned* arr, int size)
{
	if (!fileName)
	{
		return;
	}

	std::ifstream inFile(fileName);
	if (!inFile.is_open())
	{
		return;
	}

	readNumbers(inFile, arr, size);
}

void addKey(uint8_t key, unsigned* arr, int size)
{
	for (size_t i = 0; i < size; i++)
	{
		arr[i] += key;
	}
}

void printResult(unsigned* arr, int size)
{
	for (size_t i = 0; i < size; i++)
	{
		std::cout << arr[i];

		if (i != size - 1)
		{
			std::cout << ' ';
		}
	}
}

int main()
{
	unsigned nums[4] = { 1, 2, 3, 4 };
	std::ofstream outFile("numbers.bin");
	outFile.write((const char*)nums, sizeof(nums));
	outFile.close();

	uint8_t keyInFile = 5;
	std::ofstream outFileKey("key.bin");
	outFileKey.write((const char*)&keyInFile, sizeof(uint8_t));
	outFileKey.close();

	int size = getArrSize("numbers.bin");
	uint8_t key = getKey("key.bin");
	
	if (size == -1)
	{
		return -1;
	}

	unsigned* arr = new unsigned[size] {};
	readNumbers("numbers.bin", arr, size);
	addKey(key, arr, size);
	printResult(arr, size);

	return 0;
}
