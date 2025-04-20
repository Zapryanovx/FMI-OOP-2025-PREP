#pragma once
#include <iostream>
#include <stdexcept> 

namespace Helpers
{
	static size_t roundToPowerOfTwo(size_t n)
	{
		n--;
		n |= n >> 1;
		n |= n >> 2;
		n |= n >> 4;
		n |= n >> 8;
		n |= n >> 16;
		n++;

		return n;
	}
}

namespace Constants
{
	constexpr size_t NUMBERS_MIN_CAPACITY = 8;
}

class Vector
{	

public:
	Vector();
	Vector(const int* numbers, size_t size);
	Vector(const Vector& other);
	Vector& operator=(const Vector& other);
	~Vector();

	void push(int n);
	void pop();

	const int operator[](size_t i) const;
	int& operator[](size_t i);
	
	size_t getSize() const;
	bool isEmpty() const;

	Vector& operator+=(const Vector& rhs);
	Vector& operator-=(const Vector& rhs);
	Vector& operator*=(int scalar);

	friend std::istream& operator>>(std::istream& is, Vector& v);
	friend std::ostream& operator<<(std::ostream& os, const Vector& v);

private:
	int* numbers;
	size_t size;
	size_t capacity;

	void setNumbers(const int* numbers, size_t size, size_t capacity);
	void setCapacity(size_t size);

	void resize(size_t newCap);
	void copyFrom(const Vector& other);
	void free();
};

Vector operator+(const Vector& lhs, const Vector& rhs);
Vector operator-(const Vector& lhs, const Vector& rhs);
Vector operator*(const Vector& v, int scalar);
Vector operator*(int scalar, const Vector& v);


