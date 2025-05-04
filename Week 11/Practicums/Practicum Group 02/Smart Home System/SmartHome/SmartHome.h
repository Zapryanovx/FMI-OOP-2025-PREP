#pragma once
#include "Device.h"
#include "SmartLight.h"
#include "SmartThermostat.h"
#include "SmartSpeaker.h"

class SmartHome
{
public:
	SmartHome();

	SmartHome(const SmartHome& other);
	SmartHome& operator=(const SmartHome& other);

	SmartHome(SmartHome&& other) noexcept;
	SmartHome& operator=(SmartHome&& other) noexcept;

	~SmartHome();

	void add(Device* d);
	void remove(const MyString& name);
	void print() const;

	void turnOn(size_t index) const;
	void turnOff(size_t index) const;

	double avgPriceOf(const MyString& maker) const;

private:
	Device** devices;
	size_t size;
	size_t capacity;

	void copyFrom(const SmartHome& other);
	void moveFrom(SmartHome&& other);
	void free();

	void resize(size_t newCap);
};

