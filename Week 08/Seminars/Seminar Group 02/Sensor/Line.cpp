#include "Line.h"

Line::Line(const char* id, const char* timestamp, double temp, int humidity)
{
	setId(id);
	setTimestamp(timestamp);
	setTemperature(temp);
	setHumidity(humidity);

	try
	{
		validateId();
		validateTimestamp();
		validateTemperature();
		validateHumidity();
	}

	catch (...)
	{
		isValid = false;
	}
}

bool Line::valid() const
{
	return isValid;
}

void Line::validateId() const
{
	if (std::strlen(id) < 4 || std::strlen(id) > 8)
	{
		throw std::invalid_argument("invalid id length");
	}
}

void Line::validateTimestamp() const
{
	if (std::strlen(timestamp) != Constants::SIZE_FOR_TIMESTAMP)
	{
		throw std::invalid_argument("invalid timestamp");
	}

	if (timestamp[4] != '-' || timestamp[7] != '-')
	{
		throw std::invalid_argument("invalid timestamp");
	}

	if (timestamp[13] != ':' || timestamp[16] != ':')
	{
		throw std::invalid_argument("invalid timestamp");
	}

	if (timestamp[10] != ' ')
	{
		throw std::invalid_argument("invalid timestamp");
	}

	for (size_t i = 0; i < Constants::SIZE_FOR_TIMESTAMP; i++)
	{
		if (i != 4 && i != 7 && i != 13 && i != 16 && i != 10)
		{
			if (!Helpers::isDigit(timestamp[i]))
			{
				throw std::invalid_argument("invalid timestamp");
			}
		}
	}
}

void Line::validateTemperature() const
{
	if (-50.0 > temperature || temperature > 100.0)
	{
		throw std::invalid_argument("invalid temperature");
	}
}

void Line::validateHumidity() const
{
	if (0 > humidity || humidity > 100)
	{
		throw std::invalid_argument("invalid humidity");
	}
}

void Line::setId(const char* id)
{
	if (!id)
	{
		throw std::invalid_argument("id is empty");
	}

	strcpy(this->id, id);
}

void Line::setTimestamp(const char* timestamp)
{
	if (!timestamp)
	{
		throw std::invalid_argument("timestamp is empty");
	}

	strcpy(this->timestamp, timestamp);
}

void Line::setTemperature(double temp)
{
	this->temperature = temp;
}

void Line::setHumidity(int humidity)
{
	this->humidity = humidity;
}

