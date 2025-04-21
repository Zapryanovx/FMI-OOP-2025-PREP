#pragma once
#include <iostream>
#include <stdexcept>
#pragma warning(disable:4996)

namespace Constants
{
	constexpr size_t BUFFER_SIZE = 1024;

	constexpr size_t ID_MIN_SIZE = 4;
	constexpr size_t ID_MAX_SIZE = 8;

	constexpr size_t SIZE_FOR_TIMESTAMP = 19;

	constexpr size_t SIZE_FOR_DATE_FORMAT = 11;
	constexpr size_t SIZE_FOR_YEAR_DATE_FORMAT = 5;
	constexpr size_t SIZE_FOR_MONTH_DATE_FORMAT = 3;
	constexpr size_t SIZE_FOR_DAY_DATE_FORMAT = 3;

	constexpr size_t SIZE_FOR_DAY_FORMAT = 9;
	constexpr size_t SIZE_FOR_HOURS_DAY_FORMAT = 3;
	constexpr size_t SIZE_FOR_MINUTES_DAY_FORMAT = 3;
	constexpr size_t SIZE_FOR_SECONDS_DAY_FORMAT = 3;

}

namespace Helpers
{
	static bool isAlpha(char ch)
	{
		return ch >= 'a' && ch <= 'z'
			|| ch >= 'A' && ch <= 'Z';
	}

	static bool isDigit(char ch)
	{
		return ch >= '0' && ch <= '9';
	}
}

class Line
{
public:
	Line(const char* id, const char* timestamp, double temp, int humidity);
	bool valid() const;

private:
	char id[Constants::BUFFER_SIZE]{};
	char timestamp[Constants::BUFFER_SIZE]{};
	double temperature;
	int humidity;
	bool isValid;

	void validateId() const;
	void validateTimestamp() const;
	void validateTemperature() const;
	void validateHumidity() const;

	void setId(const char* id);
	void setTimestamp(const char* timestamp);
	void setTemperature(double temp);
	void setHumidity(int humidity);

};

