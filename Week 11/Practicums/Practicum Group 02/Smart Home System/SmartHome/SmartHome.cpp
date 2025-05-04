#include "SmartHome.h"

void SmartHome::copyFrom(const SmartHome& other)
{
	devices = new Device * [other.capacity] {};
	for (size_t i = 0; i < size; i++)
	{
		devices[i] = other.devices[i]->clone();
	}

	size = other.size;
	capacity = other.capacity;
}

void SmartHome::moveFrom(SmartHome&& other)
{
	devices = other.devices;
	other.devices = nullptr;

	size = other.size;
	capacity = other.capacity;

	other.capacity = other.size = 0;
}

void SmartHome::free()
{
	for (size_t i = 0; i < size; i++)
	{
		delete devices[i];
	}

	delete[] devices;
	devices = nullptr;

	capacity = size = 0;
}

void SmartHome::resize(size_t newCap)
{
	Device** newDevices = new Device * [newCap] {};
	for (size_t i = 0; i < size; i++)
	{
		newDevices[i] = devices[i];
	}

	delete[] devices;
	devices = newDevices;
	newDevices = nullptr;

	capacity = newCap;
}

SmartHome::SmartHome()
{
	capacity = 8;
	size = 0;
	devices = new Device * [capacity] {};
}

SmartHome::SmartHome(const SmartHome& other)
{
	copyFrom(other);
}

SmartHome& SmartHome::operator=(const SmartHome& other)
{
	if (this != &other)
	{
		free();
		copyFrom(other);
	}

	return *this;
}

SmartHome::SmartHome(SmartHome&& other) noexcept
{
	moveFrom(std::move(other));
}

SmartHome& SmartHome::operator=(SmartHome&& other) noexcept
{
	if (this != &other)
	{
		free();
		moveFrom(std::move(other));
	}

	return *this;
}

SmartHome::~SmartHome()
{
	free();
}

void SmartHome::add(const Device* d)
{
	if (size == capacity)
	{
		resize(capacity * 2);
	}

	devices[size++] = d->clone();
}

void SmartHome::remove(const MyString& name)
{
	for (size_t i = 0; i < size; i++)
	{
		if (devices[i]->getName() == name)
		{
			delete devices[i];
			std::swap(devices[i], devices[size - 1]);
			devices[size - 1] = nullptr;
			size--;
			return;
		}
	}

	throw std::invalid_argument("device not found");
}
void SmartHome::print() const
{
	std::cout << "<<<<< Smart Home >>>>>" << std::endl;
	for (size_t i = 0; i < size; i++)
	{
		devices[i]->printDetails();
	}

	std::cout << std::endl;
}

void SmartHome::turnOn(size_t index) const
{
	if (index >= size)
	{
		throw std::invalid_argument("invalid index");
	}

	devices[index]->turnOn();
}

void SmartHome::turnOff(size_t index) const
{
	if (index >= size)
	{
		throw std::invalid_argument("invalid index");
	}

	devices[index]->turnOff();
}

double SmartHome::avgPriceOf(const MyString& maker) const
{
	double avg = 0.0;
	size_t count = 0;

	for (size_t i = 0; i < size; i++)
	{
		if (devices[i]->getMaker() == maker)
		{
			avg += devices[i]->getPrice();
			count++;
		}
	}

	return avg / count;
}