#include "Bitset.h"

int main()
{
	Bitset b1(32);
	Bitset b2(8);

	b1.addNum(32);
	b1.addNum(31);
	b1.addNum(15);
	b1.addNum(3);
	b1.addNum(5);
	b1.removeNum(5);
	
	b1.printSet();
	std::cout << std::endl;

	b2.addNum(5);
	b2.addNum(3);

	b1.unionWith(b2).printSet();
	std::cout << std::endl;
	b1.intersectWith(b2).printSet();

	return 0;
}

