#include "MultiSetLessThanThree.h"

int main()
{
	
	MultiSetLessThanThree ms1(10);
	MultiSetLessThanThree ms2(5);

	ms1.addNum(2);
	ms1.addNum(2);
	ms1.addNum(2);
	ms1.addNum(2);
	ms1.removeNum(2);
	ms1.removeNum(2);

	ms1.addNum(10);
	ms1.addNum(9);
	ms1.addNum(7);

	ms2.addNum(4);
	ms2.addNum(3);
	ms2.addNum(2);
	ms2.addNum(2);

	ms1.print();
	ms2.print();
	ms1.intersectWith(ms2).print();

	return 0;
}

