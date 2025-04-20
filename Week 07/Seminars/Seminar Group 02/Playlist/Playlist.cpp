#include "Playlist.h"


void Playlist::copyFrom(const Playlist& other)
{
	size = other.size;
	capacity = other.capacity;

	songs = new Song[capacity]{};
	for (size_t i = 0; i < size; i++)
	{
		songs[i] = other.songs[i];
	}
}

void Playlist::free()
{
	delete[] songs;
	songs = nullptr;

	capacity = size = 0;
}

void Playlist::resize(size_t newCap)
{
	Song* newSongs = new Song[newCap]{};
	for (size_t i = 0; i < size; i++)
	{
		newSongs[i] = songs[i];
	}

	delete[] songs;
	songs = newSongs;
	newSongs = nullptr;

	capacity = newCap;
}

Playlist::Playlist()
{
	capacity = 8;
	size = 0;
	songs = new Song[capacity]{};
}

Playlist::Playlist(const Playlist& other)
{
	copyFrom(other);
}

Playlist& Playlist::operator=(const Playlist& other)
{
	if (this != &other)
	{
		free();
		copyFrom(other);
	}

	return *this;
}

Playlist::~Playlist()
{
	free();
}

void Playlist::addSong(const Song& s)
{
	if (size == capacity)
	{
		resize(capacity * 2);
	}

	songs[size++] = s;
}

double Playlist::calcPlaylistDuration() const
{
	double res = 0;
	for (size_t i = 0; i < size; i++)
	{
		res += songs[i].getDuration();
	}

	return res;
}

Playlist& Playlist::operator+=(const Playlist& other)
{
	for (size_t i = 0; i < other.size; i++)
	{
		addSong(other.songs[i]);
	}

	return *this;
}

void Playlist::saveToBinary(std::ofstream& ofs)
{
	ofs.write((const char*)&size, sizeof(size_t));
	ofs.write((const char*)&capacity, sizeof(size_t));
	
	for (size_t i = 0; i < size; i++)
	{
		songs[i].saveToBinary(ofs);
	}
}

void Playlist::readFromBinary(std::ifstream& ifs)
{
	ifs.read((char*)&size, sizeof(size_t));
	ifs.read((char*)&capacity, sizeof(size_t));

	delete[] songs;
	songs = new Song[capacity]{};

	for (size_t i = 0; i < size; i++)
	{
		songs[i].readFromBinary(ifs);
	}
}

Playlist operator+(const Playlist& lhs, const Playlist& rhs)
{
	Playlist res(lhs);
	res += rhs;
	return res;
}

std::ostream& operator<<(std::ostream& os, const Playlist& p)
{
	os << p.size << " " << p.capacity << std::endl;
	for (int i = 0; i < p.size; i++)
	{
		os << p.songs[i];
	}

	return os;
}

std::istream& operator>>(std::istream& is, Playlist& p)
{
	is >> p.size >> p.capacity;
	for (int i = 0; i < p.size; i++)
	{
		is >> p.songs[i];
	}

	return is;
}