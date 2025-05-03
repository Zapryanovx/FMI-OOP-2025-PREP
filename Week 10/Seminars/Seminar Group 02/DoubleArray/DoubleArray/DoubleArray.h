#pragma once
#include <iostream>

class DoubleArray
{
public:
	DoubleArray(const double* arr, size_t size);
	
	DoubleArray(const DoubleArray& other);
	DoubleArray& operator=(const DoubleArray& other);
	
	DoubleArray(DoubleArray&& other) noexcept;
	DoubleArray& operator=(DoubleArray&& other) noexcept;

	~DoubleArray();

	const double operator[](size_t index) const;
	double& operator[](size_t index);
	
	const double* getArr() const;
	size_t getSize() const;
	bool isEmpty() const;

private:
	double* arr;
	size_t size;

	void setArr(const double* arr, size_t size);

	void copyFrom(const DoubleArray& other);
	void moveFrom(DoubleArray&& other);
	void free();

};

bool operator==(const DoubleArray& lhs, const DoubleArray& rhs);
bool operator!=(const DoubleArray& lhs, const DoubleArray& rhs);

