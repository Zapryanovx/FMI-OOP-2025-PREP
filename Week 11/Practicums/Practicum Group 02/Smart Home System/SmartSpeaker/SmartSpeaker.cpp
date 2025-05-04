#include "SmartSpeaker.h"

SmartSpeaker::SmartSpeaker(const MyString& name, const MyString& maker, double price, unsigned volume) :
	Device(name, maker, price), volume(volume) {}

unsigned SmartSpeaker::getVolume() const
{
	return volume;
}

void SmartSpeaker::turnOn() const
{
	std::cout << "[Smart Speaker] " << getName().c_str() << " was turned on" << std::endl;
}
void SmartSpeaker::turnOff() const
{
	std::cout << "[Smart Speaker] " << getName().c_str() << " was turned off" << std::endl;
}

void SmartSpeaker::printDetails() const
{
	std::cout << "---[Smart Speaker]---" << std::endl
		<< "[Name]: " << getName().c_str() << std::endl
		<< "[Maker]: " << getMaker() << std::endl
		<< "[Price]: " << getPrice() << std::endl
		<< "[Volume] " << volume << std::endl;
}

Device* SmartSpeaker::clone() const
{
	return new SmartSpeaker(*this);
}
