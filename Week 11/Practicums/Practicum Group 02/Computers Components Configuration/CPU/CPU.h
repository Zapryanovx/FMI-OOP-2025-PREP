#pragma once
#include "Component.h"

namespace CPUConstants
{
	constexpr size_t CORES_LOWER_BOUND = 1;
	constexpr size_t CORES_UPPER_BOUND = 8;

	constexpr double PRICE_PER_CORE = 29.99;
}

class CPU: public Component
{
public:
	CPU(const char* name, unsigned short cores, unsigned short clockSpeed);

	unsigned short getCores() const;
	unsigned short getClockSpeed() const;

	double price() const override;
	void output(std::ostream& os) const override;

	Component* clone() const override;

private:
	unsigned short cores;
	unsigned short clockSpeed;

	void setCores(unsigned short cores);
	void setClockSpeed(unsigned short clockSpeed);
};

