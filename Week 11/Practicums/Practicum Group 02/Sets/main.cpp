#include "IntSet.h"
#include "ArraySet.h"
#include "IntRange.h"


int main()
{

	ArraySet a(5);
	a.insert(3);
	a.insert(5);
	a.insert(8);
	a.print();

	ArraySet b(5);
	b.insert(5);
	b.insert(8);
	b.print();

	IntRange r1(2, 6);
	r1.print();

	IntRange r2(10, 15);
	r2.print();

	std::cout << a.member(5) << std::endl;
	std::cout << r1.member(6) << std::endl;

	std::cout << a.intersects(&r1) << std::endl;
	std::cout << a.intersects(&r2) << std::endl;

	std::cout << b.isSubsetOf(&a) << std::endl;
	std::cout << a.isSubsetOf(&r1) << std::endl;

	std::cout << std::endl;
	a.remove(5);
	a.print();

	std::cout << a.member(5) << std::endl;
	std::cout << a.intersects(&r1) << std::endl;

	return 0;

}