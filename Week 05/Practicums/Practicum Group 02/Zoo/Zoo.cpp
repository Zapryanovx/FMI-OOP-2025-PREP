#include "Zoo.h"

Zoo::Zoo(): size(0), capacity(8)
{
	setName(CONSTANTS::DEFAULT_NAME);
	setAnimals(capacity);
}

Zoo::Zoo(const char* name, size_t capacity): size(0), capacity(capacity)
{
	setName(name);
	setAnimals(capacity);
}

Zoo::Zoo(const Zoo& other)
{
	copyFrom(other);
}

Zoo& Zoo::operator=(const Zoo& other)
{
	if (this != &other)
	{
		free();
		copyFrom(other);
	}

	return *this;
}

Zoo::~Zoo()
{
	free();
}

void Zoo::addAnimal(const Animal& animal)
{
	if (size >= capacity)
	{
		return;
	}

	animals[size++] = animal;
}

void Zoo::removeAnimal(const char* name)
{
	if (!name)
	{
		return;
	}

	int at = getIdxOf(name);
	if (at == -1)
	{
		return;
	}

	std::swap(animals[at], animals[size - 1]);
	size--;
}

size_t Zoo::countOf(AnimalType type) const
{
	size_t count = 0;
	for (size_t i = 0; i < size; i++)
	{
		if (animals[i].getAnimalType() == type)
		{
			count++;
		}
	}

	return count;
}

void Zoo::saveToCSV(const char* fileName) const
{
	if (!fileName)
	{
		return;
	}

	std::ofstream outFile(fileName);
	if (!outFile.is_open())
	{
		return;
	}

	saveToCSV(outFile);
	outFile.close();
}

void Zoo::printZoo() const
{
	std::cout << "---------Zoo: " << name << std::endl;
	for (size_t i = 0; i < size; i++)
	{
		animals[i].printAnimal();
	}
}

void Zoo::setName(const char* name)
{
	if (!name)
	{
		return;
	}

	this->name = new char[std::strlen(name) + 1];
	std::strcpy(this->name, name);
}

void Zoo::setAnimals(size_t capacity)
{
	animals = new Animal[capacity];
}

int Zoo::getIdxOf(const char* name)
{
	if (!name)
	{
		return -1;
	}

	for (size_t i = 0; i < size; i++)
	{
		if (!std::strcmp(animals[i].getName(), name))
		{
			return i;
		}
	}

	return -1;
}

void Zoo::saveToCSV(std::ofstream& outFile) const
{
	outFile << "Name,Type,Age" << std::endl;
	for (size_t i = 0; i < size; i++)
	{
		animals[i].saveToCSV(outFile);
	}
}

void Zoo::copyFrom(const Zoo& other)
{
	name = new char[std::strlen(other.name) + 1];
	std::strcpy(name, other.name);
	
	animals = new Animal[other.capacity];
	for (size_t i = 0; i < other.size; i++)
	{
		animals[i] = other.animals[i];
	}

	size = other.size;
	capacity = other.capacity;
}

void Zoo::free()
{
	delete[] name;
	name = nullptr;

	delete[] animals;
	animals = nullptr;

	size = capacity = 0;
}