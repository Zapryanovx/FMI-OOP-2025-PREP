#pragma once
#include "Vehicle.h"

class VehicleList
{
public:
	VehicleList();
	VehicleList(const VehicleList& other);
	VehicleList& operator=(const VehicleList& other);
	~VehicleList();

	VehicleList(VehicleList&& other) noexcept;
	VehicleList& operator=(VehicleList&& other) noexcept;

	void add(const Vehicle& v);
	const Vehicle& find(const Registration& reg) const;

	const Vehicle& operator[](size_t index) const;
	Vehicle& operator[](size_t index);

	bool isEmpty() const;

	size_t getSize() const;
	size_t getCapacity() const;

	void print() const;

private:

	Vehicle** vehicles;
	size_t size;
	size_t capacity;

	void copyFrom(const VehicleList& other);
	void moveFrom(VehicleList&& other);
	void free();
	void resize(size_t newCap);

};

