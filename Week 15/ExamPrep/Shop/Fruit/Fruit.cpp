#include "Fruit.h"

Fruit::Fruit(Type type, unsigned calories, double price, const char* name, const char* color) :
	StoreItem(type, calories, price, name) {
	
	setColor(color);
}

Fruit::Fruit(const Fruit& other) : StoreItem(other) {
	copyFrom(other);
}

Fruit& Fruit::operator=(const Fruit& other) {
	if (this != &other) {
		StoreItem::operator=(other);
		free();
		copyFrom(other);
	}

	return *this;
}

Fruit::Fruit(Fruit&& other) noexcept: StoreItem(std::move(other)) {
	moveFrom(std::move(other));
}

Fruit& Fruit::operator=(Fruit&& other) noexcept {
	if (this != &other) {
		StoreItem::operator=(other);
		free();
		moveFrom(std::move(other));
	}

	return *this;
}

Fruit::~Fruit() {
	free();
}

void Fruit::setColor(const char* color) {
	if (!color || this->color == color) {
		return;
	}

	delete[] this->color;
	this->color = new char[std::strlen(color) + 1] {};
	strcpy(this->color, color);
}

StoreItem* Fruit::clone() const {
	return new Fruit(*this);
}

void Fruit::print() const {
	std::cout << "-----------------------" << std::endl;
	StoreItem::print();
	std::cout << "[Color]: " << color << std::endl;
	std::cout << "-----------------------" << std::endl;
}

void Fruit::copyFrom(const Fruit& other) {
	color = new char[std::strlen(other.color) + 1] {};
	strcpy(color, other.color);
}

void Fruit::moveFrom(Fruit&& other) {
	color = other.color;
	other.color = nullptr;
}

void Fruit::free() {
	delete[] color;
	color = nullptr;
}
bool operator>(const Fruit& lhs, const Fruit& rhs) {
	return lhs.getCalories() > rhs.getCalories();
}