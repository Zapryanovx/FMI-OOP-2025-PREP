#include <iostream>

bool isLittleEndian()
{
	union A
	{
		int n = 1;
		char ch;
	}obj;

	return (int)obj.ch == 1;
};

int main()
{
	std::cout << isLittleEndian();
}