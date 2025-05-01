#include "Registration.h"

int main()
{

	try
	{

		Registration r1("C1234AB");
		Registration r2("XY1111YX");
		Registration r3 = r1;

		std::cout << r1.getNumber() << std::endl;
		std::cout << r2.getNumber() << std::endl;
		std::cout << (r1 == r2) << std::endl;
		std::cout << (r1 == r3) << std::endl;

		Registration r4("111145");

	}
	catch (const std::invalid_argument& e)
	{

		std::cout << e.what() << std::endl;

	}

	return 0;

}