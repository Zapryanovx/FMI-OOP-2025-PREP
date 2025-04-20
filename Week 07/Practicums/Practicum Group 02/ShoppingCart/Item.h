#pragma once
#include <iostream>
#include <fstream>
#include "MyString.h"

enum class Status
{
	AVAILABLE,
	UNAVAILABLE,
	NONE,
};

class Item
{
public:

	Item();
	Item(const MyString& name, Status status, double price);
	Item(const char* name, Status status, double price);

	MyString getName() const;
	double getPrice() const;
	Status getStatus() const;

	void print() const;

	void saveToBinary(std::ofstream& ofs);
	void readFromBinary(std::ifstream& ifs);

private:
	MyString name;
	Status status;
	double price;

	const char* convertStatusToStr(Status status) const;

};

