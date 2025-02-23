//ОБЯСНЕНИЕ НА ЗАДАЧАТА:

//Като използвате union направте проста програма, 
//която симулира действието на IP адресите.#include <iostream>


#include <iostream>

//ip адресите всъщност представляват произволно число

//като разделим стойностите на байтовете на това число с точки
//получаваме ip адрес

union ipAddress
{
	int number;
	uint8_t parts[4];
} ip;

int main()
{
	ip.number = 2563931973;
	std::cout << (int) ip.parts[0] << "." << (int) ip.parts[1] << "." << (int) ip.parts[2] << "." << (int) ip.parts[3];

	return 0;
}