#pragma once
#include <iostream>
#include <stdexcept>

class Matrix
{
public:
	Matrix();
	Matrix(size_t rows, size_t cols);
	Matrix(const Matrix& other);
	Matrix operator=(const Matrix& other);
	~Matrix();

	Matrix& operator+=(const Matrix& other);
	Matrix& operator-=(const Matrix& other);
	Matrix& operator*=(const Matrix& other);
	Matrix& operator*=(int scalar);

	size_t getRows() const;
	size_t getCols() const;

	operator bool() const;

	int*& operator[](size_t idx);
	const int* operator[](size_t idx) const;

	void print() const;

private:
	int** matrix;
	size_t rows;
	size_t cols;

	void copyFrom(const Matrix& other);
	void free();
};


Matrix operator+(const Matrix& lhs, const Matrix& rhs);
Matrix operator-(const Matrix& lhs, const Matrix& rhs);
Matrix operator*(const Matrix& lhs, const Matrix& rhs);
Matrix operator*(const Matrix& lhs, int scalar);
Matrix operator*(int scalar, const Matrix& lhs);
bool operator==(const Matrix& lhs, const Matrix& rhs);
bool operator!=(const Matrix& lhs, const Matrix& rhs);