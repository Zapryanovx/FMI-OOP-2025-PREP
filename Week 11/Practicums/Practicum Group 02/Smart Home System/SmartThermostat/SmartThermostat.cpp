#include "SmartThermostat.h"

SmartThermostat::SmartThermostat(const MyString& name, const MyString& maker, double price, int currTemp, int goalTemp) :
	Device(name, maker, price), currTemp(currTemp), goalTemp(goalTemp) {}

int SmartThermostat::getCurrTemp() const
{
	return currTemp;
}

int SmartThermostat::getGoalTemp() const
{
	return goalTemp;
}

void SmartThermostat::turnOn() const
{
	std::cout << "[Smart Thermostat] " << getName().c_str() << " was turned on" << std::endl;
}
void SmartThermostat::turnOff() const
{
	std::cout << "[Smart Thermostat] " << getName().c_str() << " was turned off" << std::endl;
}

void SmartThermostat::printDetails() const
{
	std::cout << "---[Smart Thermostat]---" << std::endl
		<< "[Name]: " << getName().c_str() << std::endl
		<< "[Maker]: " << getMaker() << std::endl
		<< "[Price]: " << getPrice() << std::endl
		<< "[Current Temperature] " << currTemp << std::endl
		<< "[Goal Temperature] " << goalTemp << std::endl;
}

Device* SmartThermostat::clone() const
{
	return new SmartThermostat(*this);
}