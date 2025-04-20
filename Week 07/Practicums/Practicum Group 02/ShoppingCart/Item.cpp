#include "Item.h"

Item::Item() : Item("default", Status::NONE, 0) {};

Item::Item(const MyString& name, Status status, double price) : name(name), status(status), price(price) {};

Item::Item(const char* name, Status status, double price) : name(name), status(status), price(price) {};

MyString Item::getName() const
{
	return name;
}

double Item::getPrice() const
{
	return price;
}

Status Item::getStatus() const
{
	return status;
}

void Item::saveToBinary(std::ofstream& ofs)
{
	size_t nameSize = name.getSize();
	const char* str = name.c_str();

	ofs.write((const char*)&nameSize, sizeof(size_t));
	ofs.write((const char*)str, sizeof(char) * nameSize);

	ofs.write((const char*)&status, sizeof(Status));
	ofs.write((const char*)&price, sizeof(double));
}

void Item::readFromBinary(std::ifstream& ifs)
{
	size_t nameSize = 0;
	char* str = nullptr;

	ifs.read((char*)&nameSize, sizeof(size_t));
	str = new char[nameSize + 1] {};
	ifs.read((char*)str, sizeof(char) * nameSize);

	MyString temp(str);
	name = temp;

	ifs.read((char*)&status, sizeof(Status));
	ifs.read((char*)&price, sizeof(double));
}

const char* Item::convertStatusToStr(Status status) const
{
	switch (status)
	{
		case Status::AVAILABLE: return "Available";
		case Status::UNAVAILABLE: return "Unavailable";
		case Status::NONE: return "None";
	}
}

void Item::print() const
{
	std::cout << name << " " << price << " " << convertStatusToStr(status) << std::endl;
}