#pragma once
#include <iostream>
#include "MyString.h"

class Device
{
public:
	
	Device();
	Device(const MyString& name, const MyString& maker, double price);

	virtual void turnOn() const = 0;
	virtual void turnOff() const = 0;
	virtual void printDetails() const = 0;
	
	const MyString& getName() const;
	const MyString& getMaker() const;
	double getPrice() const;

	virtual Device* clone() const = 0;

	virtual ~Device() = default;

private:
	MyString name;
	MyString maker;
	double price;
};

