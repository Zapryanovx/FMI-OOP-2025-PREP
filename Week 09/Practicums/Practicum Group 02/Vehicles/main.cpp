#include "VehicleList.h"

int main()
{

	Registration r1("PK7777PK");
	Registration r2("A1234AK");
	Registration r3("SA1135PR");
	Registration r4("PE1198AA");

	Vehicle v1("Neshto si versiq 1", r1);
	Vehicle v2("Neshto si versiq 2", r2);
	Vehicle v3("Neshto si versiq 3", r3);
	Vehicle v4("Neshto si versiq 4", r4);

	VehicleList ves;

	ves.add(v1);
	ves.add(v2);
	ves.add(v3);
	ves.add(v4);

	ves.print();
	std::cout << ves.isEmpty() << std::endl;

	try
	{

		const Vehicle& ref1 = ves.find("PK7777PK");
		ref1.print();

		const Vehicle& ref2 = ves.find("SIKE");
		ref2.print();

	}
	catch (const std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}

	return 0;

}