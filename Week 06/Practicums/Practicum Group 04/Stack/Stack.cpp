#include "Stack.h"

void Stack::copyFrom(const Stack& other)
{
	stack = new int[other.size] {};
	size = other.size;
	capacity = other.capacity;
	
	for (size_t i = 0; i < size; i++)
	{
		stack[i] = other.stack[i];
	}
}

void Stack::free()
{
	delete[] stack;
	stack = nullptr;

	size = capacity = 0;
}

void Stack::resize()
{
	int* temp = new int[capacity *= 2] {};
	for (size_t i = 0; i < size; i++)
	{
		temp[i] = stack[i];
	}

	delete[] stack;
	stack = temp;
	temp = nullptr;
}

Stack::Stack()
{
	capacity = 8;
	size = 0;
	stack = new int[capacity] {};
}

Stack::Stack(const Stack& other)
{
	copyFrom(other);
}

Stack& Stack::operator=(const Stack& other)
{
	if (this != &other)
	{
		free();
		copyFrom(other);
	}

	return *this;
}

Stack::~Stack()
{
	free();
}

void Stack::push(int a)
{
	if (size == capacity)
	{
		resize();
	}

	stack[size++] = a;
}

void Stack::pop()
{
	size--;
}

int Stack::peek() const
{
	return stack[size - 1];
}