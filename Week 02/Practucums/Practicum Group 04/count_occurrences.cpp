#include <iostream>
#include <fstream>

size_t countOccurences(char ch, std::ifstream& inFile)
{
	size_t count = 0;
	while (true)
	{
		char curr = inFile.get();
		if (!inFile.eof())
		{
			break;
		}

		if (curr == ch)
		{
			count++;
		}
	}

	inFile.seekg(0, std::ios::beg);
	return count;
}

size_t countOccurences(char ch, const char* fileName)
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

	size_t count = countOccurences(ch, inFile);
	inFile.close();

	return count;
}

int main() {

	std::ofstream outFile("text.txt");
	outFile << "fkaskxekxa" << std::endl << "daseqwa";
	outFile.close();

	char lookFor = 'a';
	const char* fileName = "text.txt";

	std::cout << countOccurences(lookFor, fileName);

	return 0;
}
