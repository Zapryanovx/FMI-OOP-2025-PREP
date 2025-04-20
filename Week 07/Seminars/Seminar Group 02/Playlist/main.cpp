#include "Song.h"
#include "Playlist.h"
#include <fstream>

int main()
{

	Song s1("s1", "s1", 3.18);
	Song s2("s2", "s2", 4.51);
	Song s3("s3", "s3", 2.68);
	Song s4("s4", "s4", 3.56);

	Playlist p1;
	p1.addSong(s1);
	p1.addSong(s2);
	p1.addSong(s3);
	p1.addSong(s4);
	std::cout << p1;

	std::ofstream ofs("file.bin", std::ios::binary);
	p1.saveToBinary(ofs);
	ofs.close();

	std::cout << std::endl;

	Playlist p2;
	
	std::ifstream ifs("file.bin", std::ios::binary);
	p2.readFromBinary(ifs);
	ifs.close();

	std::cout << p2;

	return 0;

}