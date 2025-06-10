#include "Matrix.h"

Matrix::Matrix(const double* const* data, size_t N) :
	DynamicContainer(N * N), dim(N) {

	size_t at = 0;

	for (size_t i = 0; i < dim; i++) {
		for (size_t j = 0; j < dim; j++) {
			this->data[at++] = data[i][j];
		}
	}
}

void Matrix::write() const {
	for (size_t i = 0; i < dim; i++) {
		std::cout << "( ";
		for (size_t j = 0; j < dim; j++) {
			std::cout << this->data[2*i + j];

			if (j != dim - 1) {
				std::cout << ", ";
			}
		}

		std::cout << " )" << std::endl;
	}
}

DynamicContainer* Matrix::clone() const {
	return new Matrix(*this);
}