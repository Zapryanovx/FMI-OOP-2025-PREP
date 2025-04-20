#pragma once
#include "Task.h"

namespace Constants
{
	constexpr size_t DAYS_IN_MONTH = 30;
	constexpr size_t HOURS_IN_DAY = 24;
	constexpr size_t MAX_TASKS_PER_DAY = 10;
}

class MonthlyPlanner
{
public:
	MonthlyPlanner() = default;

	void addTask(const Task& task, unsigned day, unsigned hour);
	void removeTask(unsigned day, unsigned index);

	void printUnfinishedOn(unsigned day);
	void finish(unsigned day, unsigned hour);

	void saveToBinary(const char* fileName);
	void readFromBinary(const char* fileName);
	
private:
	Task tasks[Constants::DAYS_IN_MONTH][Constants::HOURS_IN_DAY]{};
	size_t tasksPerDay[Constants::DAYS_IN_MONTH]{};
	bool histogram[Constants::DAYS_IN_MONTH][Constants::HOURS_IN_DAY]{};

	void saveToBinary(std::ofstream& outFile);
	void readFromBinary(std::ifstream& inFile);
};

