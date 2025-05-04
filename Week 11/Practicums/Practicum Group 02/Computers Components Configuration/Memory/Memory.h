#pragma once
#include "Component.h"

namespace MemoryConstants
{
	constexpr size_t CAP_LOWER_BOUND = 1;
	constexpr size_t CAP_UPPER_BOUND = 1000;

	constexpr double PRICE_PER_GB = 89.99;
}

class Memory : public Component
{
public:
	Memory(const char* name, unsigned short capacity);

	unsigned short getCapacity() const;

	double price() const override;
	void output(std::ostream& os) const override;

	Component* clone() const override;

private:
	unsigned short capacity;

	void setCapacity(unsigned short capacity);
};
