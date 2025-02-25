#include <iostream>
#include <fstream>

void replace(std::fstream& fs, char target, char replaceWith)
{
	while (true)
	{
		char curr = fs.get();

		if (curr == target)
		{
			fs.seekg(-1, std::ios::cur);
			fs.put(replaceWith);
			fs.flush();
		}

		if (fs.eof())
		{
			break;	
		}
	}
}

void replace(const char* fileName, char target, char replaceWith)
{
	if (!fileName)
	{
		return;
	}

	std::fstream fs(fileName);
	if (!fs.is_open())
	{
		return;
	}

	replace(fs, target, replaceWith);
	fs.close();
}

int main()
{
	std::ofstream outFile("replace.txt");
	outFile << "aaaaaa3131bbbaaa";
	outFile.close();

	char target = 'a';
	char replaceWith = 'b';

	replace("replace.txt", target, replaceWith);
	

	return 0;
}