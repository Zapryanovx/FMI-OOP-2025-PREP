#include "Pixel.h"

Pixel::Pixel() : Pixel(0, 0, 0) {};

Pixel::Pixel(unsigned r, unsigned g, unsigned b): r(r), g(g), b(b) {}

void Pixel::print() const
{
	std::cout << "(" << r << ", " << g << ", " << b << ")";
}