#include <iostream>
#include "Line.h"
#include <fstream>

namespace FILES
{
	const char source[] = "sensorReadings.txt";
	const char valid[] = "processedReadings.log";
	const char invalid[] = "invalidReadings.log";
}

void filter()
{
	char id[Constants::BUFFER_SIZE]{};
	char timestamp[Constants::BUFFER_SIZE]{};
	double temp;
	int humidity;

	std::ifstream ifs(FILES::source);
	std::ofstream ofsValid(FILES::valid);
	std::ofstream ofsInvalid(FILES::invalid);

	if (!ifs.is_open() || !ofsValid.is_open() || !ofsInvalid.is_open())
	{
		throw std::invalid_argument("a file could not be opened");
	}

	while (true)
	{
		ifs.getline(id, Constants::BUFFER_SIZE, ';');
		ifs.getline(timestamp, Constants::BUFFER_SIZE, ';');
		ifs >> temp;
		ifs.ignore();
		ifs >> humidity;
		ifs.ignore();

		Line line(id, timestamp, temp, humidity);
		if (line.valid())
		{
			ofsValid << id << " at " << timestamp << ": Temp = " << temp << "°C, Humidity = " << humidity << "%" << std::endl;
		}

		else
		{
			ofsInvalid << id << " at " << timestamp << ": Temp = " << temp << "°C, Humidity = " << humidity << "%" << std::endl;
		}

		if (ifs.eof())
		{
			break;
		}
	}

	ifs.close();
	ofsValid.close();
	ofsInvalid.close();
	
}

int main()
{
	filter();
	return 0;
}