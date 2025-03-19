#pragma once
#include <iostream>
#pragma warning(disable:4996)

enum class ShipClass
{
	BB,
	BC,
	NONE
};

class Ship
{
public:
	Ship();
	Ship(const char* name, unsigned launched, ShipClass shipClass, unsigned numGuns);
	Ship(const Ship& other);
	Ship& operator=(const Ship& other);
	~Ship();

	const char* getName() const;
	unsigned getLaunched() const;
	ShipClass getShipClass() const;
	const char* getShipClassStr() const;
	unsigned getNumGuns() const;

private:

	void copyFrom(const Ship& other);
	void free();

	void setName(const char* name);

	char* name;
	unsigned launched;
	ShipClass shipClass;
	unsigned numGuns;

};

