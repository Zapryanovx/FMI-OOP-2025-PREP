#include "ComplexNumber.h"

int main()
{

	ComplexNumber number(1, 1);
	ComplexNumber number1(1, 1);
	ComplexNumber number2(2, -11);
	ComplexNumber number3(3, 9);
	ComplexNumber number4(-6, 1);

	number1 *= number2;
	std::cout << number1;

	number2 += number3;
	std::cout << number2;

	number3 /= number1;
	std::cout << number3;

	number4 -= number3;
	std::cout << number4;

	ComplexNumber number5(0, 0);
	std::cin >> number5;
	std::cout << number5;

	return 0;

}