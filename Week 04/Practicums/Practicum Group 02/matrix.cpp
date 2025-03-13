#include <iostream>
#include <fstream>
#pragma warning(disable:4996)

namespace CONSTANTS
{
	constexpr size_t ROWS_MAX_SIZE = 100;
	constexpr size_t COLS_MAX_SIZE = 100;
	constexpr size_t FILE_MAX_SIZE = 64;
}

class MatrixFile
{
	int matrix[CONSTANTS::ROWS_MAX_SIZE][CONSTANTS::COLS_MAX_SIZE]{};
	size_t n = 0;
	char fileName[CONSTANTS::FILE_MAX_SIZE]{};

	void setMatrix(std::ifstream& inFile)
	{
		inFile.read((char*)&n, sizeof(size_t));
		inFile.read((char*)matrix, sizeof(matrix));
	}

	void setMatrix(const char* fileName)
	{
		if (!fileName)
		{
			return;
		}

		std::ifstream inFile(fileName, std::ios::binary);
		if (!inFile.is_open())
		{
			return;
		}

		setMatrix(inFile);
		inFile.close();
	}

	void printRow(size_t i) const
	{
		for (size_t j = 0; j < n; j++)
		{
			std::cout << matrix[i][j];

			if (j != n - 1)
			{
				std::cout << " ";
			}
		}

		std::cout << std::endl;
	}

	void setFileName(const char* fileName)
	{
		if (!fileName)
		{
			return;
		}

		strcpy(this->fileName, fileName);
	}

	void saveToBinary(std::ofstream& outFile) const
	{
		outFile.write((const char*)&n, sizeof(size_t));
		outFile.write((const char*)matrix, sizeof(matrix));
	}

public:

	MatrixFile(const char* fileName)
	{
		setMatrix(fileName);
		setFileName(fileName);
	}

	void printMatrix() const
	{
		std::cout << "[Rows]: " << n << " [Cols]: " << n << std::endl;
		for (size_t i = 0; i < n; i++)
		{
			printRow(i);
		}
	}

	void transpose()
	{
		for (size_t i = 0; i < n; i++)
		{
			for (size_t j = i + 1; j < n; j++)
			{
				std::swap(matrix[i][j], matrix[j][i]);
			}
		}
	}

	void mulBy(size_t coeff)
	{
		for (size_t i = 0; i < n; i++)
		{
			for (size_t j = 0; j < n; j++)
			{
				matrix[i][j] *= coeff;
			}
		}
	}

	void replaceAt(size_t i, size_t j, int newVal)
	{
		if (i >= n || j >= n)
		{
			return;
		}

		matrix[i][j] = newVal;
	}

	void saveToBinary() const
	{
		std::ofstream outFile(fileName, std::ios::binary);
		if (!outFile.is_open())
		{
			return;
		}

		saveToBinary(outFile);
	}

	~MatrixFile()
	{
		saveToBinary();
	}
};

int main()
{
	size_t rows = 3, cols = 3;
	int matrix[3][3] = {1, 2, 3, 1, 2, 3, 1, 2, 3};
	std::ofstream outFile("matrix.bin", std::ios::binary);
	outFile.write((const char*)&rows, sizeof(size_t));
	outFile.write((const char*)&cols, sizeof(size_t));
	outFile.write((const char*)matrix, sizeof(matrix));
	outFile.close();

	MatrixFile mf("matrix.bin");
	mf.printMatrix();


	return 0;
}