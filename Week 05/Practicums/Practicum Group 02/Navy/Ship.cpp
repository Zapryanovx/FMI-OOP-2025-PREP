#include "Ship.h"

Ship::Ship() : launched(0), shipClass(ShipClass::NONE), numGuns(0)
{
	setName("default");
}

Ship::Ship(const char* name, unsigned launched, ShipClass shipClass, unsigned numGuns):
	launched(launched), shipClass(shipClass), numGuns(numGuns)
{
	setName(name);
}

Ship::Ship(const Ship& other)
{
	copyFrom(other);
}

Ship& Ship::operator=(const Ship& other)
{
	if (this != &other)
	{
		free();
		copyFrom(other);
	}
	
	return *this;
}

Ship::~Ship()
{
	free();
}

const char* Ship::getName() const
{
	return name;
}

unsigned Ship::getLaunched() const
{
	return launched;
}

ShipClass Ship::getShipClass() const
{
	return shipClass;
}

const char* Ship::getShipClassStr() const
{
	switch (shipClass)
	{
		case ShipClass::BB:
			return "battleship";
		case ShipClass::BC:
			return "battlecruiser";
		case ShipClass::NONE:
			return "none";
	}
}

unsigned Ship::getNumGuns() const
{
	return numGuns;
}

void Ship::copyFrom(const Ship& other)
{
	name = new char[strlen(other.name) + 1];
	strcpy(name, other.name);

	launched = other.launched;
	shipClass = other.shipClass;
	numGuns = other.numGuns;
}

void Ship::free()
{
	delete[] name;
	name = nullptr;

	launched = 0;
	shipClass = ShipClass::NONE;
	numGuns = 0;
}


void Ship::setName(const char* name)
{
	if (!name)
	{
		return;
	}

	this->name = new char[std::strlen(name) + 1] {};
	strcpy(this->name, name);
}

