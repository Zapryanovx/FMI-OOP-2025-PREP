#pragma once
#include "Song.h"

class Playlist
{
public:
	Playlist();
	Playlist(const Playlist& other);
	Playlist& operator=(const Playlist& other);
	~Playlist();

	void addSong(const Song& s);
	double calcPlaylistDuration() const;

	Playlist& operator+=(const Playlist& other);

	void saveToBinary(std::ofstream& ofs);
	void readFromBinary(std::ifstream& ifs);

	friend std::ostream& operator<<(std::ostream& os, const Playlist& p);
	friend std::istream& operator>>(std::istream& is, Playlist& p);

private:
	Song* songs;
	size_t size;
	size_t capacity;
	
	void copyFrom(const Playlist& other);
	void free();
	void resize(size_t newCap);
};

Playlist operator+(const Playlist& lhs, const Playlist& rhs);
