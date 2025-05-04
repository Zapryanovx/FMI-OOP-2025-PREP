#include "SmartLight.h"

SmartLight::SmartLight(const MyString& name, const MyString& maker, double price, unsigned brightnessLevel) :
	Device(name, maker, price), brightnessLevel(brightnessLevel){}

unsigned SmartLight::getBrightnessLevel() const
{
	return brightnessLevel;
}

void SmartLight::turnOn() const
{
	std::cout << "[Smart Light] " << getName().c_str() << " was turned on" << std::endl;
}
void SmartLight::turnOff() const
{
	std::cout << "[Smart Light] " << getName().c_str() << " was turned off" << std::endl;
}

void SmartLight::printDetails() const
{
	std::cout << "---[Smart Light]---" << std::endl
		<< "[Name]: " << getName().c_str() << std::endl
		<< "[Maker]: " << getMaker() << std::endl
		<< "[Price]: " << getPrice() << std::endl
		<< "[Brightness Level] " << brightnessLevel << std::endl;
}

Device* SmartLight::clone() const
{
	return new SmartLight(*this);
}