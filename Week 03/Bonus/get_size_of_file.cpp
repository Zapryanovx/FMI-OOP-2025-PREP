#include <iostream>
#include <fstream>

size_t getSizeOfFile(std::ifstream& inFile)
{
	size_t curr = inFile.tellg();
	inFile.seekg(0, std::ios::end);
	size_t size = inFile.tellg();

	inFile.seekg(curr);
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
	outFile << "123456789";
	outFile.close();

	std::cout << getSizeOfFile("size.txt");


	return 0;
}