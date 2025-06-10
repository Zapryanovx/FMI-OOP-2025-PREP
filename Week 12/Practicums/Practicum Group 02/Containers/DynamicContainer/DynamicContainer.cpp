#include "DynamicContainer.h"

DynamicContainer::DynamicContainer(const double* data, size_t N) {
	this->data = new double[N] {};
	this->N = N;

	for (size_t i = 0; i < N; i++) {
		this->data[i] = data[i];
	}
}

DynamicContainer::DynamicContainer(const DynamicContainer& other) {
	copyFrom(other);
}

DynamicContainer& DynamicContainer::operator=(const DynamicContainer& other) {
	if (this != &other) {
		free();
		copyFrom(other);
	}

	return *this;
}

DynamicContainer::DynamicContainer(DynamicContainer&& other) noexcept {
	moveFrom(std::move(other));
}

DynamicContainer& DynamicContainer::operator=(DynamicContainer&& other) noexcept {
	if (this != &other) {
		free();
		moveFrom(std::move(other));
	}

	return *this;
}

DynamicContainer::~DynamicContainer() {
	free();
}

DynamicContainer::DynamicContainer(size_t N) : N(N) {
	data = new double[N] {};
}

void DynamicContainer::free() {
	delete[] data;
	data = nullptr;

	N = 0;
}

void DynamicContainer::copyFrom(const DynamicContainer& other) {
	data = new double[other.N] {};
	for (size_t i = 0; i < other.N; i++) {
		data[i] = other.data[i];
	}

	N = other.N;
}

void DynamicContainer::moveFrom(DynamicContainer&& other) {
	data = other.data;
	other.data = nullptr;

	N = other.N;
	other.N = 0;
}

bool DynamicContainer::member(double x) const {
	for (size_t i = 0; i < N; i++) {
		if (std::abs(data[i] - x) <= DCConstants::EPSILON) {
			return true;
		}
	}

	return false;
}

double& DynamicContainer::operator[](size_t i) {
	if (i >= N) {
		throw std::out_of_range("exceeded container");
	}

	return data[i];
}

const double& DynamicContainer::operator[](size_t i) const {
	if (i >= N) {
		throw std::out_of_range("exceeded container");
	}

	return data[i];
}

int DynamicContainer::count() const {
	return N;
}