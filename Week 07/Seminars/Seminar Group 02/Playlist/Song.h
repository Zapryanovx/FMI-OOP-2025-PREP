#pragma once
#include <iostream>
#include <fstream>
#pragma warning(disable:4996)

class Song
{
public:
	Song() = default;
	Song(const char* name, const char* singer, double duration);
	Song(const Song& other);
	Song& operator=(const Song& other);
	~Song();

	const char* getName() const;
	const char* getSinger() const;
	double getDuration() const;

	//void saveToBinary(const char* fileName);
	//void readFromBinary(const char* fileName);

	void saveToBinary(std::ofstream& ofs);
	void readFromBinary(std::ifstream& ifs);

	friend std::istream& operator>>(std::istream& is, Song& s);
	friend std::ostream& operator<<(std::ostream& os, Song& s);

private:
	char* name = nullptr;
	char* singer = nullptr;
	double duration = 0.0;

	void setName(const char* name);
	void setSinger(const char* singer);
	void setDuration(double duration);

	void free();
	void copyFrom(const Song& other);
};

