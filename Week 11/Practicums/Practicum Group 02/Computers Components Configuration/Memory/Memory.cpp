#include "Memory.h"

Memory::Memory(const char* name, unsigned short capacity) : Component(name)
{
	setCapacity(capacity);
}

unsigned short Memory::getCapacity() const
{
	return capacity;
}

double Memory::price() const
{
	return capacity * MemoryConstants::PRICE_PER_GB;
}

void Memory::output(std::ostream& os) const
{
	os << "---Memory Component---" << std::endl
		<< "[Name]: " << getName() << std::endl
		<< "[Capacity]: " << capacity << "GB" << std::endl
		<< "[Price]: " << price() << std::endl;
}

Component* Memory::clone() const
{
	return new Memory(*this);
}

void Memory::setCapacity(unsigned short capacity)
{
	if (capacity < MemoryConstants::CAP_LOWER_BOUND || capacity > MemoryConstants::CAP_UPPER_BOUND)
	{
		throw std::invalid_argument("invalid capacity");
	}

	this->capacity = capacity;
}