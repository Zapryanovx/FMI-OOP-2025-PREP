#include <iostream>
#include <fstream>

namespace CONSTANTS
{
	constexpr int CITY_NAME_MAX_SIZE = 63;
	constexpr int CITIES_MAX_SIZE = 20;
}

struct City
{
	char name[CONSTANTS::CITY_NAME_MAX_SIZE]{};
	size_t population = 0;
};

struct District
{
	City cities[CONSTANTS::CITIES_MAX_SIZE]{};
	size_t size = 0;
};


void saveCityToFile(std::ofstream& outFile, const City& c)
{
	outFile << c.name << " " << c.population << std::endl;
}

void saveCityToFile(const char* fileName, const City& c)
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

	saveCityToFile(outFile, c);
}


void saveDistrictToFile(std::ofstream& outFile, const District& d)
{
	outFile << d.size << std::endl;
	for (size_t i = 0; i < d.size; i++)
	{
		saveCityToFile(outFile, d.cities[i]);
	}
}

void saveDistrictToFile(const char* fileName, const District& d)
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

	saveDistrictToFile(outFile, d);
}

City readCityFromFile(std::ifstream& inFile)
{
	City c;
	inFile >> c.name >> c.population;
	return c;
}

City readCityFromFile(const char* fileName)
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

	City c = readCityFromFile(inFile);
	inFile.close();

	return c;
}

District readDistrictFromFile(std::ifstream& inFile)
{
	District d;
	inFile >> d.size;

	for (size_t i = 0; i < d.size; i++)
	{
		d.cities[i] = readCityFromFile(inFile);
	}

	return d;
}

District readDistrictFromFile(const char* fileName)
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

	District d = readDistrictFromFile(inFile);
	inFile.close();

	return d;
}

void printCity(const City& c)
{
	std::cout << "----[City] : " << c.name << " [Population] : " << c.population << std::endl;
}

void printDistrict(const District& d)
{
	std::cout << "[District Size] : " << d.size << std::endl;

	for (size_t i = 0; i < d.size; i++)
	{
		printCity(d.cities[i]);
	}
}

bool populationCriteria(const City& lhs, const City& rhs)
{
	return lhs.population < rhs.population;
}

void sortDistrict(District& d, bool(*criteria)(const City& lhs, const City& rhs))
{
	for (size_t i = 0; i < d.size - 1; i++)
	{
		size_t minIdx = i;
		for (size_t j = i + 1; j < d.size; j++)
		{
			if (criteria(d.cities[minIdx], d.cities[j]))
			{
				minIdx = j;
			}
		}

		if (minIdx != i)
		{
			std::swap(d.cities[minIdx], d.cities[i]);
		}
	}
}

int main()
{
	District d1 = {
		{
			{"city1", 1000},
			{ "city2", 2000 },
			{ "city3", 3000 },
		},

		3
	};

	saveDistrictToFile("district.txt", d1);
	
	District d2 = readDistrictFromFile("district.txt");
	sortDistrict(d2, populationCriteria);
	printDistrict(d2);

	saveDistrictToFile("sorted.txt", d2);
	printDistrict(d2);

	return 0;
}
