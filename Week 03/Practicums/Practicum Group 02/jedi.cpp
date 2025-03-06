#include <iostream>
#include <fstream>
#pragma warning(disable:4996)

namespace CONSTANTS
{
	constexpr int NAME_MAX_SIZE = 50;
	constexpr int JEDI_MAX_SIZE = 100;
	constexpr size_t COLORS_COUNT = 6;
	constexpr size_t TYPES_COUNT = 4;
}

enum class Color
{
	RED,
	YELLOW,
	GREEN,
	BLUE,
	PURPLE,
	NONE,
};

enum class Type
{
	SINGLEBLADED,
	DOUBLE_BLADED,
	CROSSGUARD,
	NONE,
};

struct LightSaber
{
	Color color = Color::NONE;
	Type type = Type::NONE;
};

struct Jedi
{
	char name[CONSTANTS::NAME_MAX_SIZE]{};
	unsigned age = 0;
	unsigned power = 0;
	LightSaber saber;
};

struct JediCollection
{
	Jedi jedi[CONSTANTS::JEDI_MAX_SIZE]{};
	size_t jediCount = 0;
};

Jedi createJedi(const char* name, unsigned age, unsigned power, const LightSaber& saber)
{
	if (!name)
	{
		return {};
	}

	Jedi jedi;

	std::strncpy(jedi.name, name, std::strlen(name) + 1);
	jedi.age = age;
	jedi.power = power;
	jedi.saber = saber;

	return jedi;
}

Jedi createJedi(const char* name, unsigned age, unsigned power, Color color, Type type)
{
	if (!name)
	{
		return {};
	}

	Jedi jedi;

	std::strncpy(jedi.name, name, std::strlen(name) + 1);
	jedi.age = age;
	jedi.power = power;
	
	LightSaber saber;
	saber.color = color;
	saber.type = type;

	jedi.saber = saber;

	return jedi;
}

void addJedi(JediCollection& collection, const Jedi& jedi)
{
	if (collection.jediCount >= CONSTANTS::JEDI_MAX_SIZE)
	{
		return;
	}

	collection.jedi[collection.jediCount++] = jedi;
}

int getIdxOfJediByName(const JediCollection& collection, const char* name)
{
	if (!name)
	{
		return -1;
	}

	for (size_t i = 0; i < collection.jediCount; i++)
	{
		if (strcmp(collection.jedi[i].name, name) == 0)
		{
			return i;
		}
	}

	return -1;
}

void removeJedi(JediCollection& collection, const char* name)
{
	if (!name)
	{
		return;
	}

	int idx = getIdxOfJediByName(collection, name);
	for (size_t i = idx; i < collection.jediCount - 1; i++)
	{
		collection.jedi[i] = collection.jedi[i + 1];
	}

	collection.jediCount--;
}

const char* convertColorToStr(Color color)
{
	switch (color)
	{
		case Color::RED:
			return "Red";
			break;
		case Color::YELLOW:
			return "Yellow";
			break;
		case Color::GREEN:
			return "Green";
			break;
		case Color::BLUE:
			return "Blue";
			break;
		case Color::PURPLE:
			return "Purple";
			break;
		case Color::NONE:
			return "None";
			break;
	}
}

const char* convertTypeToStr(Type type)
{
	switch (type)
	{
		case Type::SINGLEBLADED:
			return "Singleblaed";
			break;
		case Type::DOUBLE_BLADED:
			return "Double bladed";
			break;
		case Type::CROSSGUARD:
			return "Crossguard";
			break;
		case Type::NONE:
			return "None";
			break;
	}
}

void printJedi(const Jedi& jedi)
{
	std::cout << "[Name] " << jedi.name << " "
		<< "[Age] " << jedi.age << " "
		<< "[Power] " << jedi.power << " "
		<< "[Saber] " << "Color: " << convertColorToStr(jedi.saber.color) 
					 << " Type: " << convertTypeToStr(jedi.saber.type) << std::endl;

	std::cout << "---------------------------------------------------------------------" << std::endl;
}

void printJediCollection(const JediCollection& collection)
{
	for (size_t i = 0; i < collection.jediCount; i++)
	{
		printJedi(collection.jedi[i]);
	}
}

void saveJediBinary(std::ofstream& outFile, const Jedi& jedi)
{
	outFile.write((const char*)&jedi, sizeof(Jedi));
}

void saveJediBinary(const char* fileName, const Jedi& jedi)
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

	saveJediBinary(outFile, jedi);
	outFile.close();
}

void saveCollectionBinary(std::ofstream& outFile, const JediCollection& collection)
{
	outFile.write((const char*)&collection, sizeof(collection));
}

void saveCollectionBinary(const char* fileName, const JediCollection& collection)
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

	saveCollectionBinary(outFile, collection);
	outFile.close();
}

Jedi readJediBinary(std::ifstream& inFile)
{
	Jedi jedi;
	inFile.read((char*)&jedi, sizeof(Jedi));
	
	return jedi;
}

Jedi readJediBinary(const char* fileName)
{
	if (!fileName)
	{
		return {};
	}

	std::ifstream inFile(fileName, std::ios::binary);
	if (!inFile.is_open())
	{
		return {};
	}

	Jedi jedi = readJediBinary(inFile);
	
	inFile.close();
	return jedi;
}

JediCollection readCollectionBinary(std::ifstream& inFile)
{
	JediCollection collection;
	inFile.read((char*)&collection, sizeof(collection));

	return collection;
}

JediCollection readCollectionBinary(const char* fileName)
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

	JediCollection collection = readCollectionBinary(inFile);

	inFile.close();
	return collection;
}

void saveJediToTxt(std::ofstream& outFile, const Jedi& jedi)
{
	outFile << jedi.name << "," << jedi.age << "," << jedi.power << "," << (int)jedi.saber.color << "," << (int)jedi.saber.type;
}

void saveJediToTxt(const char* fileName, const Jedi& jedi)
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

	saveJediToTxt(outFile, jedi);
}

void saveCollectionToTxt(std::ofstream& outFile, const JediCollection& collection)
{
	outFile << collection.jediCount << std::endl;
	for (size_t i = 0; i < collection.jediCount; i++)
	{
		saveJediToTxt(outFile, collection.jedi[i]);

		if (i != collection.jediCount - 1)
		{
			outFile << std::endl;
		}
	}
}

void saveCollectionToTxt(const char* fileName, const JediCollection& collection)
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

	saveCollectionToTxt(outFile, collection);
}

LightSaber createLightSaber(Color color, Type type)
{
	return { color, type };
}

Jedi readJediFromTxt(std::ifstream& inFile)
{
	Jedi jedi;

	inFile.getline(jedi.name, CONSTANTS::NAME_MAX_SIZE + 1, ',');
	inFile >> jedi.age;
	inFile.ignore();
	inFile >> jedi.power;
	inFile.ignore();

	int color, type;
	inFile >> color;
	inFile.ignore();
	inFile >> type;

	jedi.saber = createLightSaber((Color)color, (Type)type);

	return jedi;
}

Jedi readJediFromTxt(const char* fileName)
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

	Jedi jedi = readJediFromTxt(inFile);

	inFile.close();
	return jedi;
}


JediCollection readCollectionFromTxt(std::ifstream& inFile)
{
	JediCollection collection;
	inFile >> collection.jediCount;
	inFile.ignore();

	for (size_t i = 0; i < collection.jediCount; i++)
	{
		collection.jedi[i] = readJediFromTxt(inFile);
		inFile.ignore();
	}

	return collection;
}

JediCollection readCollectionFromTxt(const char* fileName)
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

	JediCollection collection = readCollectionFromTxt(inFile);

	inFile.close();
	return collection;
}

bool ageCriteria(const Jedi& lhs, const Jedi& rhs)
{
	return lhs.age > rhs.age;
}

bool powerCriteria(const Jedi& lhs, const Jedi& rhs)
{
	return lhs.power > rhs.power;
}

void sortByCriteria(JediCollection& collection, bool (*criteria)(const Jedi& lhs, const Jedi& rhs))
{
	for (size_t i = 0; i < collection.jediCount - 1; i++)
	{
		size_t minIdx = i;
		for (size_t j = i + 1; j < collection.jediCount; j++)
		{
			if (criteria(collection.jedi[minIdx], collection.jedi[j]))
			{
				minIdx = j;
			}
		}

		if (minIdx != i)
		{
			std::swap(collection.jedi[minIdx], collection.jedi[i]);
		}
	}
}

void sortByAge(JediCollection& collection)
{
	sortByCriteria(collection, ageCriteria);
}

void sortByPower(JediCollection& collection)
{
	sortByCriteria(collection, powerCriteria);
}

Color mostPopularSaberColor(const JediCollection& collection)
{
	int colorCounter[CONSTANTS::COLORS_COUNT]{};
	for (size_t i = 0; i < collection.jediCount; i++)
	{
		colorCounter[int(collection.jedi[i].saber.color)]++;
	}

	int maxType = 0;
	for (size_t i = 0; i < CONSTANTS::COLORS_COUNT; i++)
	{
		if (colorCounter[i] >= colorCounter[maxType])
		{
			maxType = i;
		}
	}

	return Color(maxType);
}

Type mostPopularSaberType(const JediCollection& collection)
{
	int typeCounter[CONSTANTS::TYPES_COUNT]{};
	for (size_t i = 0; i < collection.jediCount; i++)
	{
		typeCounter[int(collection.jedi[i].saber.type)]++;
	}

	int maxType = 0;
	for (size_t i = 0; i < CONSTANTS::TYPES_COUNT; i++)
	{
		if (typeCounter[i] >= typeCounter[maxType])
		{
			maxType = i;
		}
	}

	return Type(maxType);
}

int main()
{
	JediCollection collection = {
		{
			{"jedi1", 3, 552, {Color::GREEN, Type::CROSSGUARD}},
			{ "jedi2", 2, 521, { Color::BLUE, Type::CROSSGUARD}},
			{ "jedi3", 1, 500, { Color::BLUE, Type::CROSSGUARD }},
		},

		3
	};

	saveCollectionToTxt("text.txt", collection);
	JediCollection collection2 = readCollectionFromTxt("text.txt");
	sortByPower(collection2);
	printJediCollection(collection2);

	std::cout << (int) mostPopularSaberColor(collection2) << std::endl;


	return 0;
}