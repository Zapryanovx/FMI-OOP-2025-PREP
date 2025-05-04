#pragma once
#include "Device.h"

class SmartThermostat : public Device
{
public:
	SmartThermostat(const MyString& name, const MyString& maker, double price, int currTemp, int goalTemp);

	int getCurrTemp() const;
	int getGoalTemp() const;

	void turnOn() const override;
	void turnOff() const override;
	void printDetails() const override;

	Device* clone() const override;

private:
	int currTemp;
	int goalTemp;
};

