#include "Task.h"

void Task::setDesc(const char* desc)
{
	if (!desc)
	{
		return;
	}

	this->desc = new char[std::strlen(desc) + 1] {};
	strcpy(this->desc, desc);
}

void Task::setPriority(unsigned priority)
{
	this->priority = priority;
}

void Task::setStatus(bool status)
{
	if (this->status)
	{
		return;
	}

	this->status = status;
}

void Task::setDuration(unsigned duration)
{
	this->duration = duration;
}

void Task::copyFrom(const Task& other)
{
	desc = new char[std::strlen(other.desc) + 1] {};
	strcpy(desc, other.desc);

	priority = other.priority;
	status = other.status;
	duration = other.duration;
}

void Task::free()
{
	delete[] desc;
	desc = nullptr;

	status = true;
	priority = duration = 0;
}

const char* Task::getDesc() const
{
	return desc;
}

unsigned Task::getPriority() const
{
	return priority;
}

bool Task::getStatus() const
{
	return status;
}

unsigned Task::getDuration() const
{
	return duration;
}

Task::Task(const char* desc, unsigned priority, unsigned duration)
{
	setDesc(desc);
	setPriority(priority);
	setStatus(false);
	setDuration(duration);
}

Task::Task(const char* fileName)
{
	readFromBinary(fileName);
}

Task::Task(const Task& other)
{
	copyFrom(other);
}

Task& Task::operator=(const Task& other)
{
	if (this != &other)
	{
		free();
		copyFrom(other);
	}

	return *this;
}

Task::~Task()
{
	free();
}

bool Task::compareWith(const Task& other)
{
	if (priority == other.priority)
	{
		return duration < other.duration;
	}

	return priority > other.priority;
}

void Task::saveToBinary(const char* fileName) const
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

void Task::print() const
{
	std::cout << desc << " " << priority << " " << status << " " << duration << std::endl;
}

void Task::readFromBinary(const char* fileName)
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

void Task::readFromBinary(std::ifstream& inFile)
{
	size_t descSize;
	inFile.read((char*)&descSize, sizeof(size_t));
	this->desc = new char[descSize + 1] {};
	inFile.read(desc, sizeof(char) * descSize);

	inFile.read((char*)&priority, sizeof(unsigned));
	inFile.read((char*)&status, sizeof(bool));
	inFile.read((char*)&duration, sizeof(unsigned));
}

void Task::saveToBinary(std::ofstream& outFile) const
{
	size_t descSize = std::strlen(desc);
	outFile.write((const char*)&descSize, sizeof(size_t));
	outFile.write((const char*)desc, sizeof(char) * descSize);

	outFile.write((const char*)&priority, sizeof(unsigned));
	outFile.write((const char*)&status, sizeof(bool));
	outFile.write((const char*)&duration, sizeof(unsigned));
}