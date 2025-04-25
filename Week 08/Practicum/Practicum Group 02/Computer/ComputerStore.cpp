#include "ComputerStore.h"

void ComputerStore::setName(const char* name)
{
	if (!name)
	{
		return;
	}

	this->name = new char[std::strlen(name) + 1] {};
	strcpy(this->name, name);
}

void ComputerStore::copyFrom(const ComputerStore& other)
{
	name = new char[std::strlen(other.name) + 1] {};
	strcpy(name, other.name);

	computers = new Computer[other.capacity]{};
	for (size_t i = 0; i < size; i++)
	{
		computers[i] = other.computers[i];
	}

	size = other.size;
	capacity = other.capacity;
}

void ComputerStore::free()
{
	delete[] name;
	name = nullptr;

	delete[] computers;
	computers = nullptr;

	capacity = size = 0;
}

void ComputerStore::resize(size_t newCap)
{
	Computer* newComputers = new Computer[newCap]{};
	for (size_t i = 0; i < size; i++)
	{
		newComputers[i] = computers[i];
	}
	
	delete[] computers;
	computers = newComputers;
	newComputers = nullptr;

	capacity = newCap;
}

ComputerStore::ComputerStore(const char* name)
{
	setName(name);
	capacity = 8;
	size = 0;
	computers = new Computer[capacity]{};
}

ComputerStore::ComputerStore(const ComputerStore& other)
{
	copyFrom(other);
}

ComputerStore& ComputerStore::operator=(const ComputerStore& other)
{
	if (this != &other)
	{
		free();
		copyFrom(other);
	}

	return *this;
}

ComputerStore::~ComputerStore()
{
	free();
}

void ComputerStore::add(const Computer& computer)
{
	if (size == capacity)
	{
		resize(capacity * 2);
	}
	
	int at = getIndexOf(computer);
	if (at == -1)
	{
		computers[size++] = computer;
		return;
	}

	computers[at]++;
}

void ComputerStore::buy(const char* brand, double cash)
{
	if (!brand)
	{
		return;
	}

	for (size_t i = 0; i < size; i++)
	{
		if (!std::strcmp(computers[i].getBrand(), brand))
		{
			if (computers[i].getPrice() <= cash)
			{
				computers[i]--;
			}
		}
	}
}

void ComputerStore::printAvailable() const
{
	std::cout << "--------[Store] " << name << "--------" << std::endl;
	for (size_t i = 0; i < size; i++)
	{
		if (computers[i].getQuantity() > 0)
		{
			computers[i].print();
		}
	}
}

void ComputerStore::printAll() const
{
	std::cout << "--------[Store] " << name  << "--------" << std::endl;
	for (size_t i = 0; i < size; i++)
	{
		computers[i].print();
	}
}

int ComputerStore::getIndexOf(const Computer& computer)
{
	for (size_t i = 0; i < size; i++)
	{
		if (!std::strcmp(computers[i].getBrand(), computer.getBrand()))
		{
			return i;
		}
	}

	return -1;
}
