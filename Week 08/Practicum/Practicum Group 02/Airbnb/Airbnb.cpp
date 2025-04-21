#include "Airbnb.h"

void Airbnb::copyFrom(const Airbnb& other)
{
	size = other.size;
	capacity = other.capacity;

	accs = new Accommodation[capacity]{};
	for (size_t i = 0; i < size; i++)
	{
		accs[i] = other.accs[i];
	}
}

void Airbnb::free()
{
	delete[] accs;
	accs = nullptr;

	capacity = size = 0;
}
void Airbnb::resize(size_t newCap)
{
	Accommodation* newAccs = new Accommodation[newCap]{};
	for (size_t i = 0; i < size; i++)
	{
		newAccs[i] = accs[i];
	}
	
	delete[] accs;
	accs = newAccs;
	newAccs = nullptr;

	capacity = newCap;
}

Airbnb::Airbnb()
{
	capacity = 8;
	size = 0;
	accs = new Accommodation[capacity]{};
}

Airbnb::Airbnb(const Airbnb& other)
{
	copyFrom(other);
}

Airbnb& Airbnb::operator=(const Airbnb& other)
{
	if (this != &other)
	{
		free();
		copyFrom(other);
	}

	return *this;
}

Airbnb::~Airbnb()
{
	free();
}

int Airbnb::getIndexOf(unsigned id)
{
	for (size_t i = 0; i < size; i++)
	{
		if (accs[i].getId() == id)
		{
			return i;
		}
	}
}

void Airbnb::addAcc(const Accommodation& acc)
{
	if (size == capacity)
	{
		resize(capacity * 2);
	}

	accs[size++] = acc;
}

void Airbnb::removeAcc(unsigned id)
{
	int idx = getIndexOf(id);
	if (idx == -1)
	{
		throw std::invalid_argument("invalid id");
	}

	if (accs[idx].isReserved())
	{
		throw std::logic_error("already reserved");
	}

	std::swap(accs[idx], accs[size - 1]);
	size--;
}

void Airbnb::reserve(unsigned id, unsigned duration)
{
	int idx = getIndexOf(id);
	if (idx == -1)
	{
		throw std::invalid_argument("invalid id");
	}

	accs[idx].reserve();
	accs[idx].setDuration(duration);
	totalProfit += accs[idx].total();
	currProfit += accs[idx].total();
}

void Airbnb::unreserve(unsigned id)
{
	int idx = getIndexOf(id);
	if (idx == -1)
	{
		throw std::invalid_argument("invalid id");
	}

	accs[idx].unreserve();
	accs[idx].setDuration(0);
	currProfit -= accs[idx].total();
}

double Airbnb::getProfit() const
{
	return currProfit;
}

double Airbnb::getAlltimeProfit() const
{
	return totalProfit;
}

void Airbnb::print() const
{
	for (int i = 0; i < size; i++)
	{
		if (accs[i].isReserved())
		{
			accs[i].print();
		}
	}

	std::cout << std::endl;
}

const Accommodation& Airbnb::getClosest(const Point& location) const
{
	int minIdx = 0;
	for (size_t i = 1; i < size; i++)
	{
		if (accs[i].getLocation().calculateDistance(location) < accs[minIdx].getLocation().calculateDistance(location))
		{
			minIdx = i;
		}
	}
	
	return accs[minIdx];
}
