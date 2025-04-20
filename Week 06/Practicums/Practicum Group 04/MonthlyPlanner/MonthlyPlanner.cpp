#include "MonthlyPlanner.h"


void MonthlyPlanner::addTask(const Task& task, unsigned day, unsigned hour)
{
	if (day >= Constants::DAYS_IN_MONTH || hour >= Constants::HOURS_IN_DAY || tasksPerDay[day] >= Constants::MAX_TASKS_PER_DAY)
	{
		return;
	}

	tasks[day][hour] = task;
	histogram[day][hour] = true;
	tasksPerDay[day]++;
}

void MonthlyPlanner::removeTask(unsigned day, unsigned index)
{
	if (day >= Constants::DAYS_IN_MONTH || index >= Constants::HOURS_IN_DAY)
	{
		return;
	}

	size_t count = 0;
	for (size_t i = 0; i < Constants::HOURS_IN_DAY; i++)
	{
		if (histogram[day][i])
		{
			count++;
		}

		if (count == index)
		{
			histogram[day][i] = false;
		}
	}

}

void MonthlyPlanner::printUnfinishedOn(unsigned day)
{
	if (day >= Constants::DAYS_IN_MONTH)
	{
		return;
	}

	for (size_t i = 0; i < Constants::HOURS_IN_DAY; i++)
	{
		if (histogram[day][i])
		{
			if (!tasks[day][i].getStatus())
			{
				tasks[day][i].print();
			}
		}
	}
}

void MonthlyPlanner::finish(unsigned day, unsigned hour)
{
	if (day >= Constants::DAYS_IN_MONTH || hour >= Constants::HOURS_IN_DAY)
	{
		return;
	}

	if (histogram[day][hour])
	{
		tasks[day][hour].setStatus(true);
	}
}

void MonthlyPlanner::saveToBinary(const char* fileName)
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

	saveToBinary(outFile);
	outFile.close();
}

void MonthlyPlanner::readFromBinary(const char* fileName)
{
	if (!fileName)
	{
		return;
	}

	std::ifstream inFile(fileName, std::ios::binary);
	if (!inFile.is_open())
	{
		return;
	}

	readFromBinary(inFile);
	inFile.close();
}

void MonthlyPlanner::saveToBinary(std::ofstream& outFile)
{
	outFile.write((const char*)&tasksPerDay, sizeof(tasksPerDay));
	outFile.write((const char*)&histogram, sizeof(histogram));

	for (size_t i = 0; i < Constants::DAYS_IN_MONTH; i++)
	{
		for (size_t j = 0; j < Constants::HOURS_IN_DAY; j++)
		{
			if (histogram[i][j])
			{
				tasks[i][j].saveToBinary(outFile);
			}
		}
	}
}

void MonthlyPlanner::readFromBinary(std::ifstream& inFile)
{
	inFile.read((char*)&tasksPerDay, sizeof(tasksPerDay));
	inFile.read((char*)&histogram, sizeof(histogram));

	for (size_t i = 0; i < Constants::DAYS_IN_MONTH; i++)
	{
		for (size_t j = 0; j < Constants::HOURS_IN_DAY; j++)
		{
			if (histogram[i][j])
			{
				tasks[i][j].readFromBinary(inFile);
			}
		}
	}
}