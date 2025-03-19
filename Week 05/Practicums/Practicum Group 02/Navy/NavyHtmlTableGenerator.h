#pragma once
#include "Navy.h"
#include <fstream>

namespace CONSTANTS
{
	constexpr size_t MAX_SIZE_FILE_NAME = 128;
	constexpr char DEFAULT_FILE[12] = "DEFAULT.TXT";
}

class NavyHtmlTableGenerator
{
public:
	NavyHtmlTableGenerator(const Navy& navy, const char* fileName);
	void saveToHtmlTable() const;

private:

	void setFileName(const char* fileName);

	void saveToHtmlTable(std::ofstream& outFile) const;
	void saveShipToHtmlTable(std::ofstream& outFile, const Ship& other) const;

	const Navy* navy;
	char fileName[CONSTANTS::MAX_SIZE_FILE_NAME];
};
