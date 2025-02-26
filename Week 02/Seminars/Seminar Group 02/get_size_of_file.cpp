#include <iostream>
#include <fstream>

size_t getSizeOfFile(std::ifstream& inFile)
{
	size_t currPos = inFile.tellg();
	inFile.seekg(0, std::ios::end);
	size_t size = inFile.tellg();

	inFile.seekg(currPos);
	return size;
}

size_t getSizeOfFile(const char* fileName)
{
	if (!fileName)
	{
		return 0;
	}

	std::ifstream inFile(fileName);
	if (!inFile.is_open())
	{
		return 0;
	}

	return getSizeOfFile(inFile);
}

int main()
{
	std::ofstream outFile("size.txt");
	outFile << "abcd";
	outFile.close();

	std::cout << getSizeOfFile("size.txt");

	return 0;
}