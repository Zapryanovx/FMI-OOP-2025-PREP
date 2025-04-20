#pragma once
#include <iostream>
#include <fstream>
#pragma warning(disable:4996)

class Task
{
public:
	Task(const char* desc, unsigned priority, unsigned duration);
	Task(const char* fileName);
	Task(const Task& other);
	Task& operator=(const Task& other) = delete;
	~Task();
	
	const char* getDesc() const;
	unsigned getPriority() const;
	bool getStatus() const;
	unsigned getDuration() const;

	void setPriority(unsigned priority);
	void setStatus(bool status);
	void setDuration(unsigned duration);

	bool compareWith(const Task& other);

	void saveToBinary(const char* fileName) const;

private:
	char* desc;
	unsigned priority;
	bool status;
	unsigned duration;

	void setDesc(const char* desc);

	void readFromBinary(const char* fileName);
	void readFromBinary(std::ifstream& inFile);

	void saveToBinary(std::ofstream& outFile) const;

	void copyFrom(const Task& other);
	void free();
};

