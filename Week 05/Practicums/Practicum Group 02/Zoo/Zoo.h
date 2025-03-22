#pragma once
#include "Animal.h"
#include <iostream>
#include <fstream>
#pragma warning(disable:4996)


class Zoo
{
public:
	Zoo();
	Zoo(const char* name, size_t capacity);
	Zoo(const Zoo& other);
	Zoo& operator=(const Zoo& other);
	~Zoo();

	void addAnimal(const Animal& animal);
	void removeAnimal(const char* name);
	size_t countOf(AnimalType type) const;
	void printZoo() const;
	void saveToCSV(const char* fileName) const;

private:
	void setName(const char* name);
	void setAnimals(size_t capacity);

	int getIdxOf(const char* name);
	void saveToCSV(std::ofstream& outFile) const;

	void copyFrom(const Zoo& other);
	void free();

	char* name;
	Animal* animals;
	size_t size;
	size_t capacity;
};

