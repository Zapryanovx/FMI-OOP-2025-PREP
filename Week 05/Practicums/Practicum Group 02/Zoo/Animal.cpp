#include "Animal.h"

Animal::Animal(): type(AnimalType::NONE), age(0)
{
	setName(CONSTANTS::DEFAULT_NAME);
}

Animal::Animal(AnimalType type, const char* name, unsigned age) : type(type), age(age)
{
	setName(name);
}

Animal::Animal(const Animal& other)
{
	copyFrom(other);
}

Animal& Animal::operator=(const Animal& other)
{
	if (this != &other)
	{
		free();
		copyFrom(other);
	}

	return *this;
}

Animal::~Animal()
{
	free();
}

AnimalType Animal::getAnimalType() const
{
	return type;
}

const char* Animal::getName() const
{
	return name;
}

unsigned Animal::getAge() const
{
	return age;
}

void Animal::printAnimal() const
{
	std::cout << "Animal:" << std::endl;
	std::cout << "----Name: " << name << std::endl
		      << "----Type: " << convertTypeToStr() << std::endl
			  << "----Age: " << age << std::endl;
}

void Animal::setName(const char* name)
{
	if (!name)
	{
		return;
	}

	this->name = new char[std::strlen(name) + 1];
	std::strcpy(this->name, name);
}

const char* Animal::convertTypeToStr() const
{
	switch (type)
	{
		case AnimalType::MAMMAL:
			return "Mammal";
		case AnimalType::REPTILE:
			return "Reptile";
		case AnimalType::FISH:
			return "Fish";
		case AnimalType::BIRD:
			return "Bird";
		case AnimalType::AMPHIBIAN:
			return "Amphibian";
		case AnimalType::INVERTEBRATES:
			return "Invertebrates";
		case AnimalType::INSECT:
			return "Insect";
		case AnimalType::NONE:
			return "None";
	}
}

void Animal::saveToCSV(std::ofstream& outFile) const
{
	outFile << name << ',' << type << ',' << age << std::endl;
}

void Animal::copyFrom(const Animal& other)
{
	name = new char[std::strlen(other.name) + 1];
	strcpy(name, other.name);

	type = other.type;
	age = other.age;
}

void Animal::free()
{
	delete[] name;
	name = nullptr;

	type = AnimalType::NONE;
	age = 0;
}
