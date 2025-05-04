#pragma once
#include "Device.h"

class SmartLight: public Device
{
public:
	SmartLight(const MyString& name, const MyString& maker, double price, unsigned brightnessLevel);
	
	unsigned getBrightnessLevel() const;

	void turnOn() const override;
	void turnOff() const override;
	void printDetails() const override;

	Device* clone() const override;

private:
	unsigned brightnessLevel;
};

