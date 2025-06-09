#include "Vegetable.h"

Vegetable::Vegetable(Type type, unsigned calories, double price, const char* name, const char* sort) :
	StoreItem(type, calories, price, name){
	
	setSort(sort);
}

Vegetable::Vegetable(const Vegetable& other) : StoreItem(other) {
	copyFrom(other);
}

Vegetable& Vegetable::operator=(const Vegetable& other) {
	if (this != &other) {
		StoreItem::operator=(other);
		free();
		copyFrom(other);
	}

	return *this;
}

Vegetable::Vegetable(Vegetable&& other) noexcept : StoreItem(std::move(other)) {
	moveFrom(std::move(other));
}

Vegetable& Vegetable::operator=(Vegetable&& other) noexcept {
	if (this != &other) {
		StoreItem::operator=(std::move(other));
		free();
		moveFrom(std::move(other));
	}

	return *this;
}

Vegetable::~Vegetable() {
	free();
}

const char* Vegetable::getSort() const {
	return sort;
}

void Vegetable::setSort(const char* sort) {
	if (!sort || this->sort == sort) {
		return;
	}

	delete[] this->sort;
	this->sort = new char[std::strlen(sort) + 1] {};
	strcpy(this->sort, sort);
}

StoreItem* Vegetable::clone() const {
	return new Vegetable(*this);
}

void Vegetable::print() const {
	std::cout << "-----------------------" << std::endl;
	StoreItem::print();
	std::cout << "[Sort]: " << sort << std::endl;
	std::cout << "-----------------------" << std::endl;
}

void Vegetable::free() {
	delete[] sort;
	sort = nullptr;
}

void Vegetable::copyFrom(const Vegetable& other) {
	sort = new char[std::strlen(other.sort) + 1] {};
	strcpy(sort, other.sort);
}

void Vegetable::moveFrom(Vegetable&& other) {
	sort = other.sort;
	other.sort = nullptr;
}

bool operator==(const Vegetable & lhs, const Vegetable & rhs) {
	return !std::strcmp(lhs.getSort(), rhs.getSort());
}