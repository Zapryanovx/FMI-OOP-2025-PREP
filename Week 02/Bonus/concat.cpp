#include <iostream>
#include <fstream>

namespace CONSTANTS
{
	constexpr int BUFFER_SIZE = 1024;
}

void copyFile(std::ifstream& inFile, std::ofstream& outFile)
{
	char buff[CONSTANTS::BUFFER_SIZE]{};

	bool firstLine = true;
	while (!inFile.eof())
	{
		inFile.getline(buff, CONSTANTS::BUFFER_SIZE);
		outFile << buff;

		firstLine ? outFile << ' ' : outFile << std::endl;
		firstLine = false;
	}
}

void copyFile(const char* from, const char* to)
{
	if (!from || !to)
	{
		return;
	}

	std::ifstream inFile(from);
	std::ofstream outFile(to);

	if (!inFile.is_open() || !outFile.is_open())
	{
		return;
	}

	copyFile(inFile, outFile);
	inFile.close();
	outFile.close();
}

void concatInto(std::ifstream& inFile1, std::ifstream& inFile2, std::ofstream& outFile)
{
	copyFile(inFile1, outFile);
	copyFile(inFile2, outFile);
}

void concatInto(const char* from1, const char* from2, const char* to)
{
	if (!from1 || !from2 || !to)
	{
		return;
	}

	std::ifstream inFile1(from1);
	std::ifstream inFile2(from2);	
	std::ofstream outFile(to);

	if (!inFile1.is_open() || !inFile2.is_open() || !outFile.is_open())
	{
		return;
	}

	concatInto(inFile1, inFile2, outFile);
	
	inFile1.close();
	inFile2.close();
	outFile.close();
}

void replaceSpaces(std::fstream& repl)
{
	while (true)
	{
		char curr = repl.get();

		if (curr == ' ')
		{
			repl.seekp(-1, std::ios::cur);
			repl.put(',');
			repl.flush();
		}

		if (repl.eof())
		{
			break;
		}
	}
}

void replaceSpaces(const char* fileName)
{
	if (!fileName)
	{
		return;
	}

	std::fstream repl(fileName);
	if (!repl.is_open())
	{
		return;
	}

	replaceSpaces(repl);
	repl.close();
}

int main()
{
	std::ofstream f1("1.txt");
	f1 << "abc d";
	f1.close();

	std::ofstream f2("2.txt");
	f2 << "efg";
	f2.close();

	concatInto("1.txt", "2.txt", "3.txt");

	replaceSpaces("3.txt");

	return 0;
}