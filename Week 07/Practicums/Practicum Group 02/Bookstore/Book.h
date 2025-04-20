#pragma once
#include <iostream>
#include <fstream>
#pragma warning(disable:4996)

class Book
{
public:
	Book();
	Book(const char* title, const char* author, unsigned published, double price);
	Book(const Book& other);
	Book& operator=(const Book& other);
	~Book();

	double getPrice() const;
	int getId() const;

	void saveToBinary(std::ofstream& ofs);
	void readFromBinary(std::ifstream& ifs);
	void print() const;

private:
	static int id;
	int currId;
	char* title;
	char* author;
	unsigned published;
	double price;

	void setTitle(const char* title);
	void setAuthor(const char* author);
	void setPublished(unsigned published);
	void setPrice(double price);

	void copyFrom(const Book& other);
	void free();
};
