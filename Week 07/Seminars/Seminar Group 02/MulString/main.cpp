#include "MulString.h"

int main()
{

	MyString str1("dada");
	MyString str2(" dadad ");

	str1 += str2;

	MulString s1(str1);
	MulString s2("ABCDEFrrrru1111ahjdaaaaaaahu192");
	std::cout << s1;


	MulString result1 = s1 % s2;

	std::cout << result1;
	std::cout << s1 % MulString(" ");

	MulString s3("4");
	MulString result2 = s3 * 3;
	std::cout << result2;

	return 0;
}