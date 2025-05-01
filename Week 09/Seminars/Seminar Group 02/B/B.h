#pragma once
#include <iostream>

struct A
{
	int x;
	int y;
};

class B
{
	B();
	B(const B& other);
	B& operator=(const B& other);
	~B();

	B(B&& other) noexcept;
	B& operator=(B&& other) noexcept;

	void add(const A& obj);

private:
	A** data;
	size_t size;
	size_t capacity;

	void free();
	void copyFrom(const B& other);
	void moveFrom(B&& other);
	void resize(size_t newCap);
};

