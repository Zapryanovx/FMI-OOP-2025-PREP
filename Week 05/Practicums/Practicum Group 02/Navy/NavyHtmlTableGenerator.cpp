#include "NavyHtmlTableGenerator.h"

NavyHtmlTableGenerator::NavyHtmlTableGenerator(const Navy& navy, const char* fileName): navy(&navy)
{
	setFileName(fileName);
}

void NavyHtmlTableGenerator::setFileName(const char* fileName)
{
	if (!fileName)
	{
		std::strcpy(this->fileName, CONSTANTS::DEFAULT_FILE);
		return;
	}
	
	std::strcpy(this->fileName, fileName);
}

void NavyHtmlTableGenerator::saveToHtmlTable() const
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

	saveToHtmlTable(outFile);
	outFile.close();
}

void NavyHtmlTableGenerator::saveToHtmlTable(std::ofstream& outFile) const
{
	outFile << "<table>" << std::endl;
	
	size_t size = navy->getSize();
	for (size_t i = 0; i < size; i++)
	{
		outFile << "    <tr>" << std::endl;
		saveShipToHtmlTable(outFile, navy->getShips()[i]);
		outFile << "    </tr>" << std::endl;

	}
	
	outFile << "</table>" << std::endl;
}

void NavyHtmlTableGenerator::saveShipToHtmlTable(std::ofstream& outFile, const Ship& ship) const
{
	outFile << "        <th>" << ship.getName() << "</th>" << std::endl;
	outFile << "        <th>" << ship.getLaunched() << "</th>" << std::endl;
	outFile << "        <th>" << ship.getShipClassStr() << "</th>" << std::endl;
	outFile << "        <th>" << ship.getNumGuns() << "</th>" << std::endl;
}
