#pragma once
#include "Book.h"

class Bookstore
{
public:
	Bookstore();
	Bookstore(const char* name);
	Bookstore(const Bookstore& other);
	Bookstore& operator=(const Bookstore& other);
	~Bookstore();

	double calcTotalPrice() const;

	Bookstore& operator+=(const Book& book);
	Bookstore& operator-=(unsigned id);

	void saveToBinary(std::ofstream& ofs);
	void readFromBinary(std::ifstream& ifs);

	void print() const;

private:
	char* name;
	Book* books;
	size_t size;
	size_t capacity;

	void setName(const char* name);
	void initBooks();

	void copyFrom(const Bookstore& other);
	void free();
	void resize(size_t newCap);
};

bool operator<(const Bookstore& lhs, const Bookstore& rhs);