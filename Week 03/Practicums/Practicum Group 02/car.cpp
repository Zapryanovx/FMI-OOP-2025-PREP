#include <iostream>
#include <fstream>

namespace CONSTANTS
{
	constexpr int NAME_MAX_SIZE = 24;
	constexpr int OFFENSES_MAX_SIZE = 20;
}

enum class Brand
{
	BENZ,
	BMW,
	AUDI,
	PORSCHE,
	NONE
};

struct Car
{
	Brand brand = Brand::NONE;
	double avgSpeed = 0.00;
	double offenses[CONSTANTS::OFFENSES_MAX_SIZE]{};
	size_t offensesSize = 0;
};

double calcSumOfOffenses(const Car& car)
{
	double res = 0.0;

	for (size_t i = 0; i < car.offensesSize; i++)
	{
		res += car.offenses[i];
	}

	return res;
}

void addOffense(Car& car, double offense)
{
	if (car.offensesSize >= CONSTANTS::OFFENSES_MAX_SIZE)
	{
		return;
	}

	car.offenses[car.offensesSize++] = offense;
}

const char* convertBrandToStr(Brand brand)
{
	switch (brand)
	{
		case Brand::BENZ:
			return "Benz";
			break;
		case Brand::BMW:
			return "BMW";
			break;
		case Brand::AUDI:
			return "Audi";
			break;
		case Brand::PORSCHE:
			return "Porsche";
			break;
		case Brand::NONE:
			return "None";
			break;
	}
}

void printCar(const Car& car)
{
	std::cout << "[Brand]: " << convertBrandToStr(car.brand) << std::endl
			  << "[Avg. Speed]: " << car.avgSpeed << std::endl
	     	  << "[Offenses]: " << std::endl;

	for (size_t i = 0; i < car.offensesSize; i++)
	{
		std::cout << "> Offense: [" << i + 1 << "]: " << car.offenses[i] << std::endl;
	}
}

void saveCarToBinary(std::ofstream& outFile, const Car& car)
{
	outFile.write((const char*)&car, sizeof(Car));
}

void saveCarToBinary(const char* fileName, const Car& car)
{
	if (!fileName)
	{
		return;
	}

	std::ofstream outFile(fileName, std::ios::binary);
	if (!outFile.is_open())
	{
		return;
	}

	saveCarToBinary(outFile, car);
}

Car readCarFromBinary(std::ifstream& inFile)
{
	Car car;
	inFile.read((char*)&car, sizeof(Car));
	return car;
}

Car readCarFromBinary(const char* fileName)
{
	if (!fileName)
	{
		return {};
	}

	std::ifstream inFile(fileName);
	if (!inFile.is_open())
	{
		return {};
	}

	Car car = readCarFromBinary(inFile);

	inFile.close();
	return car;
}

int main()
{

	Car car = {
		Brand::BENZ, 120.0, {1, 2, 3}, 3
	};

	printCar(car);
	saveCarToBinary("car.txt", car);
	Car carCpy = readCarFromBinary("car.txt");
	printCar(car);


	return 0;
}