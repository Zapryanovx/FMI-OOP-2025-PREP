#pragma once
#include "Computer.h"
#pragma warning(disable:4996)

class ComputerStore
{
public:
	ComputerStore(const char* name);
	ComputerStore(const ComputerStore& other);
	ComputerStore& operator=(const ComputerStore& other);
	~ComputerStore();

	void add(const Computer& computer);
	void buy(const char* brand, double cash);

	void printAvailable() const;
	void printAll() const;

private:
	char* name;
	Computer* computers;
	size_t size;
	size_t capacity;

	void setName(const char* name);

	int getIndexOf(const Computer& computer);

	void copyFrom(const ComputerStore& other);
	void free();
	void resize(size_t newCap);
};

