#include "CPU.h"

CPU::CPU(const char* name, unsigned short cores, unsigned short clockSpeed) : Component(name)
{
	setCores(cores);
	setClockSpeed(clockSpeed);
}

unsigned short CPU::getCores() const
{
	return cores;
}

unsigned short CPU::getClockSpeed() const
{
	return clockSpeed;
}

double CPU::price() const
{
	return cores * CPUConstants::PRICE_PER_CORE;
}

void CPU::output(std::ostream& os) const
{
	os << "---CPU Component---" << std::endl
		<< "[Name]: " << getName() << std::endl
		<< "[Cores]: " << cores << std::endl
		<< "[Clock Speed]: " << clockSpeed << std::endl
		<< "[Price]: " << price() << std::endl;
}

Component* CPU::clone() const
{
	return new CPU(*this);
}

void CPU::setCores(unsigned short cores)
{
	if (cores < CPUConstants::CORES_LOWER_BOUND || cores > CPUConstants::CORES_UPPER_BOUND)
	{
		throw std::invalid_argument("invalid cores size");
	}

	this->cores = cores;
}

void CPU::setClockSpeed(unsigned short clockSpeed)
{
	this->clockSpeed = clockSpeed;
}