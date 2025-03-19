#include "Navy.h"

Navy::Navy(): size(0)
{
	setCountry("default country");	
}

Navy::Navy(const char* country, const Ship* ships, size_t size)
{
	setCountry(country);
	setShips(ships, size);
}

Navy::Navy(const Navy& other)
{
	copyFrom(other);
}

Navy& Navy::operator=(const Navy& other)
{
	if (this != &other)
	{
		free();
		copyFrom(other);
	}

	return *this;
}

Navy::~Navy()
{
	free();
}

void Navy::addShip(const Ship& ship)
{
	if (size >= CONSTANTS::SHIPS_MAX_SIZE)
	{
		return;
	}

	ships[size++] = ship;
}

int Navy::getAtByName(const char* name) const
{
	if (!name)
	{
		return -1;
	}

	for (size_t i = 0; i < size; i++)
	{
		if (!strcmp(ships[i].getName(), name))
		{
			return i;
		}
	}

	return -1;
}

void Navy::removeShip(const char* name)
{
	if (!name)
	{
		return;
	}

	int at = getAtByName(name);
	if (at == -1)
	{
		return;
	}

	std::swap(ships[at], ships[size - 1]);
	size--;
}

size_t Navy::getSize() const
{
	return size;
}

const Ship* Navy::getShips() const
{
	return ships;
}

const Ship* Navy::getAt(size_t at) const
{
	if (at >= size)
	{
		return nullptr;
	}

	return &ships[at];
}

unsigned Navy::getTotalNumGuns() const
{
	unsigned sum = 0;

	for (size_t i = 0; i < size; i++)
	{
		sum += ships[i].getNumGuns();
	}

	return sum;
}

int Navy::compareWith(const Navy& other) const
{
	unsigned lhs = getTotalNumGuns();
	unsigned rhs = other.getTotalNumGuns();

	if (lhs > rhs)
	{
		return 1;
	}

	else if (lhs < rhs)
	{
		return -1;
	}

	return 0;
}

void Navy::copyFrom(const Navy& other)
{
	country = new char[std::strlen(other.country) + 1] {};
	strcpy(country, other.country);

	size = other.size;
	for (size_t i = 0; i < size; i++)
	{
		ships[i] = other.ships[i];
	}
}

void Navy::free()
{
	delete[] country;
	country = nullptr;

	size = 0;
}

void Navy::setCountry(const char* country)
{
	if (!country)
	{
		return;
	}

	this->country = new char[std::strlen(country) + 1] {};
	std::strcpy(this->country, country);
}

void Navy::setShips(const Ship* ships, size_t size)
{
	this->size = size;
	for (size_t i = 0; i < size; i++)
	{
		this->ships[i] = ships[i];
	}
}