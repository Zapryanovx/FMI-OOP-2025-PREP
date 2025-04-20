#include "Bookstore.h"

void Bookstore::setName(const char* name)
{
	if (!name)
	{
		return;
	}

	this->name = new char[std::strlen(name) + 1] {};
	strcpy(this->name, name);
}

void Bookstore::initBooks()
{
	size = 0;
	capacity = 8;
	books = new Book[capacity]{};
}

void Bookstore::copyFrom(const Bookstore& other)
{
	name = new char[std::strlen(other.name) + 1] {};
	strcpy(name, other.name);

	books = new Book[other.capacity]{};
	size = other.size;
	capacity = other.capacity;

	for (size_t i = 0; i < size; i++)
	{
		books[i] = other.books[i];
	}
}

void Bookstore::free()
{
	delete[] name;
	name = nullptr;

	delete[] books;
	books = nullptr;

	capacity = size = 0;
}

void Bookstore::resize(size_t newCap)
{
	Book* newBooks = new Book[newCap]{};
	for (size_t i = 0; i < size; i++)
	{
		newBooks[i] = books[i];
	}

	delete[] books;
	books = newBooks;
	newBooks = nullptr;

	capacity = newCap;
}

Bookstore::Bookstore() : Bookstore("default") {};

Bookstore::Bookstore(const char* name)
{
	setName(name);
	initBooks();
}

Bookstore::Bookstore(const Bookstore& other)
{
	copyFrom(other);
}

Bookstore& Bookstore::operator=(const Bookstore& other)
{
	if (this != &other)
	{
		free();
		copyFrom(other);
	}
	
	return *this;
}

Bookstore::~Bookstore()
{
	free();
}

double Bookstore::calcTotalPrice() const
{
	double res = 0;
	for (size_t i = 0; i < size; i++)
	{
		res += books[i].getPrice();
	}

	return res;
}

Bookstore& Bookstore::operator+=(const Book& book)
{
	if (size == capacity)
	{
		resize(capacity * 2);
	}

	books[size++] = book;
	return *this;
}

Bookstore& Bookstore::operator-=(unsigned id)
{
	for (size_t i = 0; i < size; i++)
	{
		if (books[i].getId() == id)
		{
			std::swap(books[i], books[size - 1]);
			size--;
			break;
		}
	}

	return *this;
}

void Bookstore::saveToBinary(std::ofstream& ofs)
{
	size_t nameSize = 0;
	ofs.write((const char*)&nameSize, sizeof(size_t));
	ofs.write((const char*)name, sizeof(char) * nameSize);

	ofs.write((const char*)&size, sizeof(size_t));
	ofs.write((const char*)&capacity, sizeof(size_t));

	for (size_t i = 0; i < size; i++)
	{
		books[i].saveToBinary(ofs);
	}
}

void Bookstore::readFromBinary(std::ifstream& ifs)
{
	free();

	size_t nameSize = 0;
	ifs.read((char*)&nameSize, sizeof(size_t));
	name = new char[nameSize + 1] {};
	ifs.read((char*)name, sizeof(char) * nameSize);

	ifs.read((char*)&size, sizeof(size_t));
	ifs.read((char*)&capacity, sizeof(size_t));

	books = new Book[capacity]{};
	for (size_t i = 0; i < size; i++)
	{
		books[i].readFromBinary(ifs);
	}
}

void Bookstore::print() const
{
	std::cout << "---[Bookstore]---" << name << std::endl;
	for (size_t i = 0; i < size; i++)
	{
		books[i].print();
	}
}

bool operator<(const Bookstore& lhs, const Bookstore& rhs)
{
	return lhs.calcTotalPrice() < rhs.calcTotalPrice();
}