#include "Vehicle.h"


void Vehicle::copyFrom(const Vehicle& other)
{
	desc = new char[std::strlen(other.desc) + 1] {};
	strcpy(desc, other.desc);
}

void Vehicle::moveFrom(Vehicle&& other)
{
	desc = other.desc;
	other.desc = nullptr;
}

void Vehicle::free()
{
	delete[] desc;
	desc = nullptr;
}

void Vehicle::setDesc(const char* desc)
{
	if (!desc)
	{
		throw std::invalid_argument("invalid desc");
	}

	this->desc = new char[std::strlen(desc) + 1] {};
	strcpy(this->desc, desc);
}

Vehicle::Vehicle(const char* desc, const Registration& reg): reg(reg)
{
	setDesc(desc);
}

Vehicle::Vehicle(const Vehicle& other): reg(other.reg)
{
	copyFrom(other);
}

Vehicle& Vehicle::operator=(const Vehicle& other)
{
	if (this != &other)
	{
		free();
		copyFrom(other);
	}

	return *this;
}

Vehicle::Vehicle(Vehicle&& other) noexcept : reg(std::move(other.reg))
{
	moveFrom(std::move(other));
}

Vehicle& Vehicle::operator=(Vehicle&& other) noexcept
{
	if (this != &other)
	{
		free();
		moveFrom(std::move(other));
	}

	return *this;
}

const Registration& Vehicle::getRegistration() const
{
	return reg;
}

void Vehicle::print() const
{
	std::cout << desc << " " << reg.getNumber() << std::endl;
}