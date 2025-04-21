#include "Airbnb.h"

int main()
{

	Point p1 = { 1,1 };
	Point p2 = { 1,0 };
	Point p3 = { 0,1 };
	Point p4 = { 0,0 };

	Accommodation acc1("Yoan Baychev", Type::Hotel, p1, 100, false, 0);
	Accommodation acc2("Ivo Kunchev", Type::Villa, p2, 31, false, 0);
	Accommodation acc3("Kokinator", Type::Apartment, p3, 26, false, 0);
	Accommodation acc4("Iliankata", Type::Villa, p4, 89, false, 0);

	Airbnb accs;
	accs.addAcc(acc1);
	accs.addAcc(acc2);
	accs.addAcc(acc3);
	accs.addAcc(acc4);
	accs.reserve(0, 10);
	accs.reserve(2, 11);
	accs.reserve(3, 5);
	accs.print();

	accs.removeAcc(1);
	accs.print();

	std::cout << accs.getAlltimeProfit() << std::endl;

	Point exampleCoords = { -56, 43 };
	const Accommodation& ref = accs.getClosest(exampleCoords);
	ref.print();

	return 0;

}