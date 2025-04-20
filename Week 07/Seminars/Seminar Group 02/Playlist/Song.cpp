#include "Song.h"

void Song::setName(const char* name)
{
	if (!name || this->name == name)
	{
		return;
	}

	this->name = new char[std::strlen(name) + 1] {};
	std::strcpy(this->name, name);
}

void Song::setSinger(const char* singer)
{
	if (!singer || this->singer == singer)
	{
		return;
	}

	this->singer = new char[std::strlen(singer) + 1] {};
	std::strcpy(this->singer, singer);
}

void Song::setDuration(double duration)
{
	this->duration = duration;
}

void Song::free()
{
	delete[] name;
	name = nullptr;

	delete[] singer;
	singer = nullptr;

	duration = 0.0;
}

void Song::copyFrom(const Song& other)
{
	name = new char[std::strlen(other.name) + 1] {};
	std::strcpy(name, other.name);
	
	singer = new char[std::strlen(other.singer) + 1] {};
	std::strcpy(singer, other.singer);

	duration = other.duration;
}

Song::Song(const char* name, const char* singer, double duration)
{
	setName(name);
	setSinger(singer);
	setDuration(duration);
}

Song::Song(const Song& other)
{
	copyFrom(other);
}

Song& Song::operator=(const Song& other)
{
	if (this != &other)
	{
		free();
		copyFrom(other);
	}

	return *this;
}

Song::~Song()
{
	free();
}

const char* Song::getName() const
{
	return name;
}

const char* Song::getSinger() const
{
	return singer;
}

double Song::getDuration() const
{
	return duration;
}

void Song::saveToBinary(std::ofstream& ofs)
{
	size_t nameSize = std::strlen(name);
	ofs.write((const char*)&nameSize, sizeof(size_t));
	ofs.write((const char*)name, sizeof(char) * nameSize);

	size_t singerSize = std::strlen(singer);
	ofs.write((const char*)&singerSize, sizeof(size_t));
	ofs.write((const char*)singer, sizeof(char) * singerSize);

	ofs.write((const char*)&duration, sizeof(double));
}

void Song::readFromBinary(std::ifstream& ifs)
{
	delete[] name;
	delete[] singer;

	size_t nameSize = 0;
	ifs.read((char*)&nameSize, sizeof(size_t));
	name = new char[nameSize + 1] {};
	ifs.read((char*)name, sizeof(char) * nameSize);

	size_t singerSize = 0;
	ifs.read((char*)&singerSize, sizeof(size_t));
	singer = new char[singerSize + 1] {};
	ifs.read((char*)singer, sizeof(char) * singerSize);

	ifs.read((char*)&duration, sizeof(double));
}

std::istream& operator>>(std::istream& is, Song& s)
{
	size_t nameSize;
	is >> nameSize;

	delete[] s.name;
	s.name = new char[nameSize + 1] {};
	is >> s.name;

	size_t singerSize;
	is >> singerSize;

	delete[] s.singer;
	s.singer = new char[singerSize + 1] {};
	is >> s.singer;

	is >> s.duration;
	
	return is;
}

std::ostream& operator<<(std::ostream& os, Song& s)
{
	os << "[Song] - " << s.name << " by " << s.singer << " | " << s.duration << std::endl;
	return os;
}
