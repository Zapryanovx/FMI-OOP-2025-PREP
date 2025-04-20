#pragma once
#include <iostream>
#include <fstream>
#pragma warning(disable:4996)

class Task
{
public:
	Task() = default;
	Task(const char* desc, unsigned priority, unsigned duration);
	Task(const char* fileName);
	Task(const Task& other);
	Task& operator=(const Task& other);
	~Task();
	
	const char* getDesc() const;
	unsigned getPriority() const;
	bool getStatus() const;
	unsigned getDuration() const;

	void setPriority(unsigned priority);
	void setStatus(bool status);
	void setDuration(unsigned duration);

	bool compareWith(const Task& other);

	void readFromBinary(const char* fileName);
	void readFromBinary(std::ifstream& inFile);

	void saveToBinary(std::ofstream& outFile) const;
	void saveToBinary(const char* fileName) const;

	void print() const;

private:
	char* desc = nullptr;
	unsigned priority = 0;
	bool status = false;
	unsigned duration = 0;

	void setDesc(const char* desc);


	void copyFrom(const Task& other);
	void free();
};

