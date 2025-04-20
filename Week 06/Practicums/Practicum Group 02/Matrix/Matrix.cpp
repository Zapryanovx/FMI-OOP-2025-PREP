#include "Matrix.h"


void Matrix::copyFrom(const Matrix& other)
{
	rows = other.rows;
	cols = other.cols;

	matrix = new int* [rows] {};
	for (size_t i = 0; i < rows; i++)
	{
		matrix[i] = new int[cols] {};
	}

	for (size_t i = 0; i < rows; i++)
	{
		for (size_t j = 0; j < cols; j++)
		{
			matrix[i][j] = other.matrix[i][j];
		}
	}
}

void Matrix::free()
{
	for (size_t i = 0; i < rows; i++)
	{
		delete[] matrix[i];
	}

	delete[] matrix;
	matrix = nullptr;
	rows = cols = 0;
}

Matrix::Matrix()
{
	rows = cols = 2;
	
	matrix = new int* [rows] {};
	for (size_t i = 0; i < rows; i++)
	{
		matrix[i] = new int[cols] {};
	}
}

Matrix::Matrix(size_t rows, size_t cols)
{
	this->rows = rows;
	this->cols = cols;
	
	matrix = new int* [rows] {};
	for (size_t i = 0; i < rows; i++)
	{
		matrix[i] = new int[cols] {};
	}
}

Matrix::Matrix(const Matrix& other)
{
	copyFrom(other);
}

Matrix Matrix::operator=(const Matrix& other)
{
	if (this != &other)
	{
		free();
		copyFrom(other);
	}

	return *this;
}

Matrix::~Matrix()
{
	free();
}


Matrix& Matrix::operator+=(const Matrix& other)
{
	if (rows != other.rows || cols != other.cols)
	{
		throw std::invalid_argument("err");
	}

	for (size_t i = 0; i < rows; i++)
	{
		for (size_t j = 0; j < cols; j++)
		{
			matrix[i][j] += other.matrix[i][j];
		}
	}

	return *this;
}

Matrix& Matrix::operator-=(const Matrix& other)
{
	if (rows != other.rows || cols != other.cols)
	{
		throw std::invalid_argument("err");
	}

	for (size_t i = 0; i < rows; i++)
	{
		for (size_t j = 0; j < cols; j++)
		{
			matrix[i][j] -= other.matrix[i][j];
		}
	}

	return *this;
}

Matrix& Matrix::operator*=(const Matrix& other)
{
	if (cols != other.rows)
	{
		throw std::invalid_argument("err");
	}

	Matrix newMatrix(rows, other.cols);
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			for (int k = 0; k < other.cols; k++)
			{
				newMatrix.matrix[i][j] += matrix[i][k] * other.matrix[k][j];
			}
		}
	}

	*this = newMatrix;
	return *this;
}

Matrix& Matrix::operator*=(int scalar)
{
	for (size_t i = 0; i < rows; i++)
	{
		for (size_t j = 0; j < cols; j++)
		{
			matrix[i][j] *= scalar;
		}
	}

	return *this;
}

size_t Matrix::getRows() const
{
	return rows;
}

size_t Matrix::getCols() const
{
	return cols;
}

Matrix::operator bool() const
{
	for (size_t i = 0; i < rows; i++)
	{
		for (size_t j = 0; j < cols; j++)
		{
			if (matrix[i][j] != 0)
			{
				return false;
			}
		}
	}
}

int*& Matrix::operator[](size_t idx)
{
	if (idx >= rows)
	{
		throw std::invalid_argument("err");
	}

	return matrix[idx];
}

const int* Matrix::operator[](size_t idx) const
{
	if (idx >= rows)
	{
		throw std::invalid_argument("err");
	}

	return matrix[idx];
}

void Matrix::print() const
{

	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			std::cout << matrix[i][j] << " ";
		}

		std::cout << std::endl;
	}

	std::cout << std::endl;
}

Matrix operator+(const Matrix& lhs, const Matrix& rhs)
{
	Matrix res(lhs);
	res += rhs;
	return res;
}

Matrix operator-(const Matrix& lhs, const Matrix& rhs)
{
	Matrix res(lhs);
	res -= rhs;
	return res;
}

Matrix operator*(const Matrix& lhs, const Matrix& rhs)
{
	Matrix res(lhs);
	res *= rhs;
	return res;
}

Matrix operator*(const Matrix& lhs, int scalar)
{
	Matrix res(lhs);
	res *= scalar;
	return res;
}

Matrix operator*(int scalar, const Matrix& lhs)
{
	Matrix res(lhs);
	res *= scalar;
	return res;
}

bool operator==(const Matrix& lhs, const Matrix& rhs)
{
	if (lhs.getRows() != rhs.getRows() || lhs.getCols() != rhs.getCols())
	{
		throw std::invalid_argument("err");
	}

	size_t rows = lhs.getRows();
	size_t cols = lhs.getCols();
	for (size_t i = 0; i < rows; i++)
	{
		const int* rowLhs = lhs[i];
		const int* rowRhs = rhs[i];

		for (size_t j = 0; j < cols; j++)
		{
			if (rowLhs[i] != rowRhs[i])
			{
				return false;
			}
		}
	}

	return true;
}

bool operator!=(const Matrix& lhs, const Matrix& rhs)
{
	return !(lhs == rhs);
}