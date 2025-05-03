#include "UnoDeck.h"
#include "UnoFactory.h"

int main()
{
	UnoDeck d;
	d.add();
	d.add();
	d.print();

	NumberCard nc1(Color::Red, 3);
	NumberCard nc2(Color::Green, 4);
	NumberCard nc3(Color::Blue, 5);
	NumberCard nc4(Color::Yellow, 6);

	d.remove(&nc1);
	d.remove(&nc2);
	//d.remove(&nc3);
	//d.remove(&nc4);
	d.print();
	

	return 0;
}