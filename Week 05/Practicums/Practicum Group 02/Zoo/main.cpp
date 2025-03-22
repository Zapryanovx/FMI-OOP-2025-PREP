#include "Zoo.h"

int main()
{
	Animal a1;
	Animal a3;
	Animal a2;

	Zoo zoo;
	zoo.addAnimal(a1);
	zoo.addAnimal(a2);
	zoo.addAnimal(a3);

	zoo.removeAnimal(CONSTANTS::DEFAULT_NAME);

	std::cout << zoo.countOf(AnimalType::AMPHIBIAN) << zoo.countOf(AnimalType::NONE) << std::endl;

	zoo.printZoo();
	zoo.saveToCSV("zoo.txt");

	return 0;
}