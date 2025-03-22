#pragma once
#include <iostream>
#include <fstream>
#pragma warning(disable:4996)

namespace CONSTANTS
{
	constexpr size_t DEFAULT_NAME_MAX_SIZE = 7;
	constexpr char DEFAULT_NAME[DEFAULT_NAME_MAX_SIZE + 1] = "DEFAULT";
}

enum AnimalType
{
	MAMMAL,
	REPTILE,
	FISH,
	BIRD,
	AMPHIBIAN,
	INVERTEBRATES,
	INSECT,
	NONE
};

class Animal
{
public:
	Animal();
	Animal(AnimalType type, const char* name, unsigned age);
	Animal(const Animal& other);
	Animal& operator=(const Animal& other);
	~Animal();

	AnimalType getAnimalType() const;
	const char* getName() const;
	unsigned getAge() const;
	
	void saveToCSV(std::ofstream& outFile) const;
	void printAnimal() const;

private:
	
	void setName(const char* name);
	const char* convertTypeToStr() const;

	void copyFrom(const Animal& other);
	void free();

	AnimalType type;
	char* name;
	unsigned age;

};

