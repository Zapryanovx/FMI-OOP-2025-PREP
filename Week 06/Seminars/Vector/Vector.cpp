#include "Vector.h"

void Vector::resize(size_t newCap)
{
	int* temp = new int[newCap];
	for (size_t i = 0; i < size; i++)
	{
		temp[i] = numbers[i];
	}

	delete[] numbers;
	numbers = temp;
	temp = nullptr;
	
	capacity = newCap;
}

void Vector::copyFrom(const Vector& other)
{
	numbers = new int[other.capacity]{};
	size = other.size;
	capacity = other.capacity;
	
	for (size_t i = 0; i < size; i++)
	{
		numbers[i] = other.numbers[i];
	}
}

void Vector::free()
{
	delete[] numbers;
	numbers = nullptr;

	size = 0;
	capacity = 0;
}

void Vector::setNumbers(const int* numbers, size_t size, size_t capacity)
{
	this->numbers = new int[capacity]{};
	this->size = size;

	for (size_t i = 0; i < size; i++)
	{
		this->numbers[i] = numbers[i];
	}
}

void Vector::setCapacity(size_t size)
{
	this->capacity = Helpers::roundToPowerOfTwo(size);
}

Vector::Vector()
{
	size = 0;
	capacity = 8;
	numbers = new int[capacity];
}

Vector::Vector(const int* numbers, size_t size)
{
	setCapacity(size);
	setNumbers(numbers, size, capacity);

}

Vector::Vector(const Vector& other)
{
	copyFrom(other);
}

Vector& Vector::operator=(const Vector& other)
{
	if (this != &other)
	{
		free();
		copyFrom(other);
	}

	return *this;
}

Vector::~Vector()
{
	free();
}

void Vector::push(int n)
{
	if (size == capacity)
	{
		resize(capacity * 2);
	}

	numbers[size++] = n;
}

void Vector::pop()
{
	if (size == 0)
	{
		throw std::logic_error("numbers is empty");
	}

	if (size <= capacity / 4)
	{
		if (capacity / 4 <= Constants::NUMBERS_MIN_CAPACITY)
		{
			resize(Constants::NUMBERS_MIN_CAPACITY);
		}
		
		else
		{
			resize(capacity / 4);
		}
	}

	size--;
}

const int Vector::operator[](size_t i) const
{
	if (i >= size)
	{
		throw std::out_of_range("idx out of range");
	}

	return numbers[i];
}

int& Vector::operator[](size_t i)
{
	if (i >= size)
	{
		throw std::out_of_range("idx out of range");
	}

	return numbers[i];
}

size_t Vector::getSize() const
{
	return size;
}

bool Vector::isEmpty() const
{
	return size == 0;
}

Vector& Vector::operator+=(const Vector& rhs)
{
	if (size != rhs.size)
	{
		throw std::length_error("lengths are not equal");
	}

	for (size_t i = 0; i < size; i++)
	{
		numbers[i] += rhs.numbers[i];
	}

	return *this;
}

Vector& Vector::operator-=(const Vector& rhs)
{
	if (size != rhs.size)
	{
		throw std::length_error("lengths are not equal");
	}

	for (size_t i = 0; i < size; i++)
	{
		numbers[i] -= rhs.numbers[i];
	}

	return *this;
}

Vector& Vector::operator*=(int scalar)
{
	for (size_t i = 0; i < size; i++)
	{
		numbers[i] *= scalar;
	}

	return *this;
}

std::istream& operator>>(std::istream& is, Vector& v)
{
	size_t size;
	is >> size;

	int* temp = new int[size] {};
	for (size_t i = 0; i < size; i++)
	{
		is >> temp[i];
	}

	Vector newVector(temp, size);
	v = newVector;

	delete[] temp;
	return is;
}

std::ostream& operator<<(std::ostream& os, const Vector& v)
{
	os << v.size << " ";

	for (size_t i = 0; i < v.size; i++)
	{
		os << v[i];
		if (i != v.size - 1)
		{
			os << " ";
		}
	}

	return os;
}

Vector operator+(const Vector& lhs, const Vector& rhs)
{
	Vector res(lhs);
	res += rhs;
	return res;
}

Vector operator-(const Vector& lhs, const Vector& rhs)
{
	Vector res(lhs);
	res -= rhs;
	return res;
}

Vector operator*(const Vector& v, int scalar)
{
	Vector res(v);
	res *= scalar;
	return res;
}

Vector operator*(int scalar, const Vector& v)
{
	Vector res(v);
	res *= scalar;
	return res;
}