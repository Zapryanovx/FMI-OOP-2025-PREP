#include "DoubleArray.h"

void DoubleArray::setArr(const double* arr, size_t size)
{
	if (!arr)
	{
		throw std::invalid_argument("invalid arr");
	}

	this->arr = new double[size];
	this->size = size;

	for (size_t i = 0; i < size; i++)
	{
		this->arr[i] = arr[i];
	}
}

void DoubleArray::copyFrom(const DoubleArray& other)
{
	arr = new double[other.size] {};
	size = other.size;

	for (size_t i = 0; i < size; i++)
	{
		arr[i] = other.arr[i];
	}
}

void DoubleArray::moveFrom(DoubleArray&& other)
{
	arr = other.arr;
	other.arr = nullptr;

	size = other.size;
	other.size = 0;
}

void DoubleArray::free()
{
	delete[] arr;
	arr = nullptr;

	size = 0;
}

DoubleArray::DoubleArray(const double* arr, size_t size)
{
	setArr(arr, size);
}

DoubleArray::DoubleArray(const DoubleArray& other)
{
	copyFrom(other);
}

DoubleArray& DoubleArray::operator=(const DoubleArray& other)
{
	if (this != &other)
	{
		free();
		copyFrom(other);
	}

	return *this;
}

DoubleArray::DoubleArray(DoubleArray&& other) noexcept
{
	moveFrom(std::move(other));
}

DoubleArray& DoubleArray::operator=(DoubleArray&& other) noexcept
{
	if (this != &other)
	{
		free();
		moveFrom(std::move(other));
	}

	return *this;
}

DoubleArray::~DoubleArray()
{
	free();
}

const double* DoubleArray::getArr() const
{
	return arr;
}

size_t DoubleArray::getSize() const
{
	return size;
}

bool DoubleArray::isEmpty() const
{
	return size == 0;
}

const double DoubleArray::operator[](size_t index) const
{
	if (index >= size)
	{
		throw std::out_of_range("invalid index");
	}

	return arr[index];
}

double& DoubleArray::operator[](size_t index)
{
	if (index >= size)
	{
		throw std::out_of_range("invalid index");
	}

	return arr[index];
}

bool operator==(const DoubleArray& lhs, const DoubleArray& rhs)
{
	if (lhs.getSize() != rhs.getSize())
	{
		return false;
	}

	for (size_t i = 0; i < lhs.getSize(); i++)
	{
		if (lhs[i] != rhs[i])
		{
			return false;
		}
	}
}

bool operator!=(const DoubleArray& lhs, const DoubleArray& rhs)
{
	return !(lhs == rhs);
}