#include "Bookstore.h"

int main()
{

	Book b1("Mystery island", "Yoan Baychev", 2014, 100);
	Book b2("The programmer", "Ilian Zaprqnov", 2002, 63);
	Book b3("How to be dumb as F", "Ivailo Kunchev", 1978, 25);
	Book b4("Happy", "Kaloyan Markov", 2025, 76);
	Bookstore store("FMI");
	store += b1;
	store += b2;
	store += b3;
	store += b4;
	store.print();

	std::ofstream ofs("file.dat", std::ios::binary);
	store.saveToBinary(ofs);
	ofs.close();

	Bookstore newStore;

	std::ifstream ifs("file.dat", std::ios::binary);
	newStore.readFromBinary(ifs);
	ifs.close();

	newStore -= 2;
	newStore.print();

	return 0;

}