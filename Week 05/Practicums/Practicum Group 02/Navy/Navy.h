#pragma once
#include "Ship.h"
#pragma warning(disable:4996)

namespace CONSTANTS
{
	constexpr size_t SHIPS_MAX_SIZE = 30;
}

class Navy
{
public:

	Navy();
	Navy(const char* country, const Ship* ships, size_t size);
	Navy(const Navy& other);
	Navy& operator=(const Navy& other);
	~Navy();

	void addShip(const Ship& ship);
	void removeShip(const char* name);
	const Ship* getAt(size_t at) const;
	size_t getSize() const;
	const Ship* getShips() const;
	int compareWith(const Navy& other) const;

private:

	void copyFrom(const Navy& other);
	void free();

	void setCountry(const char* country);
	void setShips(const Ship* ships, size_t size);

	int getAtByName(const char* name) const;
	unsigned getTotalNumGuns() const;
	
	char* country;
	Ship ships[CONSTANTS::SHIPS_MAX_SIZE];
	size_t size;
};

