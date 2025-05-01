#include "B.h"

void B::free()
{
	for (size_t i = 0; i < size; i++)
	{
		delete data[i];
	}

	delete[] data;
	data = nullptr;

	capacity = size = 0;
}

void B::copyFrom(const B& other)
{
	data = new A * [other.capacity] {nullptr};
	for (size_t i = 0; i < other.size; i++)
	{
		data[i] = new A(*other.data[i]);
	}

	capacity = other.capacity;
	size = other.size;
}

void B::moveFrom(B&& other)
{
	data = other.data;
	other.data = nullptr;

	size = other.size;
	capacity = other.capacity;

	other.capacity = other.size = 0;
}

void B::resize(size_t newCap)
{
	A** newData = new A * [newCap] {nullptr};
	for (size_t i = 0; i < size; i++)
	{
		newData[i] = data[i];
	}

	delete[] data;
	data = newData;
	newData = nullptr;

	capacity = newCap;
}

B::B()
{
	capacity = 8;
	size = 0;

	data = new A * [capacity] {nullptr};
}

B::B(const B& other)
{
	copyFrom(other);
}

B& B::operator=(const B& other)
{
	if (this != &other)
	{
		free();
		copyFrom(other);
	}

	return *this;
}

B::~B()
{
	free();
}

B::B(B&& other) noexcept
{
	moveFrom(std::move(other));
}

B& B::operator=(B&& other) noexcept
{
	if (this != &other)
	{
		free();
		moveFrom(std::move(other));
	}

	return *this;
}

void B::add(const A& obj)
{
	if (size == capacity)
	{
		resize(capacity * 2);
	}

	data[size++] = new A(obj);
}