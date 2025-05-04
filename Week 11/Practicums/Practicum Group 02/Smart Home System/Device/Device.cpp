#include "Device.h"

Device::Device() : Device(MyString("default"), MyString("default"), 0) {}

Device::Device(const MyString& name, const MyString& maker, double price): name(name), maker(maker), price(price){}

const MyString& Device::getName() const
{
	return name;
}

const MyString& Device::getMaker() const
{
	return maker;
}

double Device::getPrice() const
{
	return price;
}