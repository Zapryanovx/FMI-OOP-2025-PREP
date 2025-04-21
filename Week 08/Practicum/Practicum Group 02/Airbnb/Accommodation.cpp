#include "Accommodation.h"

unsigned Accommodation::id = 0;

void Accommodation::setName(const char* name)
{
	if (!name)
	{
		throw std::invalid_argument("invalid name");
	}

	this->name = new char[std::strlen(name) + 1] {};
	strcpy(this->name, name);
}

void Accommodation::copyFrom(const Accommodation& other)
{
	currId = other.currId;

	name = new char[std::strlen(other.name) + 1] {};
	strcpy(name, other.name);

	type = other.type;
	location = other.location;
	price = other.price;
	reserved = other.reserved;
	duration = other.duration;
}

void Accommodation::free()
{
	delete[] name;
	name = nullptr;
}

Accommodation::Accommodation() : Accommodation("default", Type::None, { 0,0 }, 0, 0, 0) {};

Accommodation::Accommodation(const char* name, Type type, Point location, double price, bool reserved, unsigned duration) :
	type(type), location(location), price(price), reserved(reserved), duration(duration)
{
	setName(name);
	currId = id;
	id++;
}

Accommodation::Accommodation(const Accommodation& other)
{
	copyFrom(other);
}

Accommodation& Accommodation::operator=(const Accommodation& other)
{
	if (this != &other)
	{
		free();
		copyFrom(other);
	}

	return *this;
}

Accommodation::~Accommodation()
{
	free();
}

void Accommodation::reserve()
{
	reserved = true;
}

void Accommodation::unreserve()
{
	reserved = false;
}

double Accommodation::total() const
{
	if (!reserved)
	{
		return 0.0;
	}

	return price * duration;
}

void Accommodation::print() const
{
	std::cout << name << " ";
	std::cout << "{" << location.x << "," << location.y << "} ";
	std::cout << (int)type << " ";
	std::cout << "Price: " << price << " ";
	std::cout << "Reserved: " << reserved << " ";
	std::cout << "Days: " << duration << " ";
	std::cout << "Id: " << currId << std::endl;
}

unsigned Accommodation::getId() const
{
	return currId;
}

void Accommodation::setDuration(unsigned duration)
{
	this->duration = duration;
}

bool Accommodation::isReserved() const
{
	return reserved;
}

const Point& Accommodation::getLocation() const
{
	return location;
}