#include <iostream>
#include <fstream>

int getFileSize(std::ifstream& fileIn, char ch)
{
	int res = 0;

	while (!fileIn.eof())
	{
		char curr = fileIn.get();
		if (curr == ch)
		{
			res += 1;
		}

	}

	fileIn.clear();
	fileIn.seekg(0, std::ios::beg);
	return res + 1;
}

int* readFrom(std::ifstream& ifs, size_t& size)
{
	size = getFileSize(ifs, ' ');
	int* arr = new int[size];
	
	size_t at = 0;
	while (!ifs.eof())
	{
		ifs >> arr[at++];
	}

	ifs.close();
	return arr;
}

void mergeFile(std::ifstream& ifs1, std::ifstream& ifs2, std::ofstream& ofsTo)
{

	size_t size1 = 0, size2 = 0, at1 = 0, at2 = 0;
	int* arr1 = readFrom(ifs1, size1);
	int* arr2 = readFrom(ifs2, size2);

	while (at1 < size1 && at2 < size2)
	{
		if (arr1[at1] <= arr2[at2])
		{
			ofsTo << arr1[at1] << " ";
			at1++;
		}

		else
		{
			ofsTo << arr2[at2] << " ";
			at2++;
		}
	}

	while (at1 < size1)
	{
		ofsTo << arr1[at1++] << " ";
	}

	while (at2 < size2)
	{
		ofsTo << arr2[at2++] << " ";
	}

	delete[] arr1;
	delete[] arr2;
}

void mergeFile(const char* f1, const char* f2, const char* to)
{
	if (!f1 || !f2 || !to)
	{
		return;
	}

	std::ifstream ifs1(f1);
	std::ifstream ifs2(f2);
	std::ofstream ofsTo(to);

	if (!ifs1.is_open() || !ifs2.is_open() || !ofsTo.is_open())
	{
		return;
	}

	mergeFile(ifs1, ifs2, ofsTo);

	ifs1.close();
	ifs2.close();
	ofsTo.close();
}

void printFile(std::ifstream& fileIn)
{
	while (!fileIn.eof())
	{
		char curr = fileIn.get();
		std::cout << curr;
	}

	fileIn.seekg(0, std::ios::beg);
}

int main()
{

	std::ofstream f1("f1.txt");
	f1 << 1 << " " << 3 << " " << 5;
	f1.close();

	std::ofstream f2("f2.txt");
	f2 << 2 << " " << 4 << " " << 6;
	f2.close();

	mergeFile("f1.txt", "f2.txt", "to.txt");

	std::ifstream fileIn("to.txt");
	printFile(fileIn);

	return 0;
}
