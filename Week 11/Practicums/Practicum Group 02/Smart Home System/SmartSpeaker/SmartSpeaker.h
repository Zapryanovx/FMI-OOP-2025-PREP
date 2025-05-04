#pragma once
#include "Device.h"

class SmartSpeaker: public Device
{
public:
	SmartSpeaker(const MyString& name, const MyString& maker, double price, unsigned volume);

	unsigned getVolume() const;

	void turnOn() const override;
	void turnOff() const override;
	void printDetails() const override;

	Device* clone() const override;

private:
	unsigned volume;
};

