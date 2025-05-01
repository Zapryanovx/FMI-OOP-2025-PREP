#include "VehicleList.h"


void VehicleList::copyFrom(const VehicleList& other)
{
	vehicles = new Vehicle*[other.capacity] {nullptr};
	size = other.size;
	capacity = other.capacity;
	
	for (size_t i = 0; i < other.size; i++)
	{
		vehicles[i] = new Vehicle(*other.vehicles[i]);
	}
}

void VehicleList::moveFrom(VehicleList&& other)
{
	vehicles = other.vehicles;
	other.vehicles = nullptr;

	size = other.size;
	capacity = other.capacity;

	other.capacity = other.size = 0;
}

void VehicleList::free()
{
	for (size_t i = 0; i < size; i++)
	{
		delete vehicles[i];
	}

	delete[] vehicles;
	vehicles = nullptr;

	capacity = size = 0;
}

void VehicleList::resize(size_t newCap)
{
	Vehicle** newVehicles = new Vehicle*[newCap] {nullptr};
	for (size_t i = 0; i < size; i++)
	{
		newVehicles[i] = vehicles[i];
	}

	delete[] vehicles;
	vehicles = newVehicles;
	newVehicles = nullptr;

	capacity = newCap;
}

VehicleList::VehicleList()
{
	capacity = 8;
	size = 0;
	vehicles = new Vehicle*[capacity] {nullptr};
}

VehicleList::VehicleList(const VehicleList& other)
{
	copyFrom(other);
}

VehicleList& VehicleList::operator=(const VehicleList& other)
{
	if (this != &other)
	{
		free();
		copyFrom(other);
	}

	return *this;
}

VehicleList::~VehicleList()
{
	free();
}

VehicleList::VehicleList(VehicleList&& other) noexcept
{
	moveFrom(std::move(other));
}

VehicleList& VehicleList::operator=(VehicleList&& other) noexcept
{
	if (this != &other)
	{
		free();
		moveFrom(std::move(other));
	}

	return *this;
}

void VehicleList::add(const Vehicle& v)
{
	try
	{
		find(v.getRegistration());
		throw std::exception("vehicle with that reg already in");
	}

	catch (std::invalid_argument& e)
	{
		if (size == capacity)
		{
			resize(capacity * 2);
		}

		vehicles[size++] = new Vehicle(v);
	}

}

const Vehicle& VehicleList::find(const Registration& reg) const
{
	for (size_t i = 0; i < size; i++)
	{
		if (reg == vehicles[i]->getRegistration())
		{
			return *vehicles[i];
		}
	}

	throw std::invalid_argument("vehicle with that reg is not found.");
}

const Vehicle& VehicleList::operator[](size_t index) const
{
	if (index >= size)
	{
		throw std::out_of_range("invalid index");
	}

	return *vehicles[index];
}

Vehicle& VehicleList::operator[](size_t index)
{
	if (index >= size)
	{
		throw std::out_of_range("invalid index");
	}

	return *vehicles[index];
}

bool VehicleList::isEmpty() const
{
	return size == 0;
}

size_t VehicleList::getSize() const
{
	return size;
}

size_t VehicleList::getCapacity() const
{
	return capacity;
}

void VehicleList::print() const
{
	for (int i = 0; i < size; i++)
	{
		vehicles[i]->print();
	}

	std::cout << std::endl;
}