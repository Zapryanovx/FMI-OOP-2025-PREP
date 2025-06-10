#include "Vector.h"

Vector::Vector(const double* data, size_t N) :
	DynamicContainer(data, N) {};

void Vector::write() const {
	std::cout << "( ";
	for (size_t i = 0; i < N; i++) {
		std::cout << data[i];

		if (i != N - 1) {
			std::cout << ", ";
		}
	}

	std::cout << " )" << std::endl;
}

DynamicContainer* Vector::clone() const {
	return new Vector(*this);
}