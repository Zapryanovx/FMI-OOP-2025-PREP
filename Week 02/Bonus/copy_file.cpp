#include <iostream>
#include <fstream>

void copyFile(std::ifstream& fileIn, std::ofstream& fileOut)
{
	while (!fileIn.eof())
	{
		char curr = fileIn.get();
		fileOut << curr;
	}

	fileIn.close();
	fileOut.close();
}

void copyFile(const char* from, const char* to)
{
	if (!from || !to)
	{
		return;
	}

	std::ifstream fileIn(from);
	std::ofstream fileOut(to);

	if (!fileIn.is_open() || !fileOut.is_open())
	{
		return;
	}

	copyFile(fileIn, fileOut);
}

void printFile(std::ifstream& fileIn)
{
	while (!fileIn.eof())
	{
		char curr = fileIn.get();
		std::cout << curr;
	}
}

int main()
{
	std::ofstream fileOut("from.txt");
	fileOut << "abc";
	fileOut.close();

	copyFile("from.txt", "to.txt");

	std::ifstream fileIn("to.txt");
	printFile(fileIn);

	return 0;
}
