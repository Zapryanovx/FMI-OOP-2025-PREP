#pragma once
#include <iostream>

class Pixel
{
public:

	unsigned r;
	unsigned g;
	unsigned b;

	Pixel();
	Pixel(unsigned r, unsigned g, unsigned b);

	void print() const;

};

