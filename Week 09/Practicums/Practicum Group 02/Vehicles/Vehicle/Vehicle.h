#pragma once
#include <iostream>
#include "Registration.h"
#pragma warning(disable:4996)

class Vehicle
{
public:
	Vehicle() = delete;
	Vehicle(const char* desc, const Registration& reg);
	Vehicle(const Vehicle& other);
	Vehicle& operator=(const Vehicle& other);

	Vehicle(Vehicle&& other) noexcept;
	Vehicle& operator=(Vehicle&& other) noexcept;
	 
	const Registration& getRegistration() const;
	void print() const;

private:

	Registration reg;
	char* desc;

	void copyFrom(const Vehicle& other);
	void moveFrom(Vehicle&& other);
	void free();

	void setDesc(const char* desc);

};

