#pragma once
#include <iostream>

class Stack
{
public:
	Stack();
	Stack(const Stack& other);
	Stack& operator=(const Stack& other);
	~Stack();

	void push(int a);
	void pop();
	int peek() const;

private:

	int* stack = nullptr;
	size_t size = 0;
	size_t capacity = 0;

	void copyFrom(const Stack& other);
	void free();
	void resize();
};

