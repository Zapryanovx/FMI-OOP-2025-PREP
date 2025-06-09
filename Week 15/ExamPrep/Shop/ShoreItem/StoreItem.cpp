#include "StoreItem.h"

StoreItem::StoreItem(Type type, unsigned calories, double price, const char* name) {
	setType(type);
	setCalories(calories);
	setPrice(price);
	setName(name);
}

StoreItem::StoreItem(const StoreItem& other) {
	copyFrom(other);
}

StoreItem& StoreItem::operator=(const StoreItem& other) {
	if (this != &other)
	{
		free();
		copyFrom(other);
	}

	return *this;
}

StoreItem::StoreItem(StoreItem&& other) noexcept {
	moveFrom(std::move(other));
}

StoreItem& StoreItem::operator=(StoreItem&& other) noexcept {
	if (this != &other)
	{
		free();
		moveFrom(std::move(other));
	}

	return *this;
}

StoreItem::~StoreItem() {
	free();
}

void StoreItem::setType(Type type) {
	if ((int) type >= 2) {
		this->type = Type::None;
		return;
	}

	this->type = type;
}

void StoreItem::setCalories(unsigned calories) {
	this->calories = calories;
}

void StoreItem::setPrice(double price) {
	if (price < 0) {
		throw std::invalid_argument("negative price");
	}

	this->price = price;
}

Type StoreItem::getType() const
{
	return type;
}

unsigned StoreItem::getCalories() const {
	return calories;
}

double StoreItem::getPrice() const {
	return price;
}

const char* StoreItem::getName() const {
	return name;
}

void StoreItem::setName(const char* name) {
	if (!name || this->name == name) {
		return;
	}

	delete[] this->name;
	this->name = new char[std::strlen(name) + 1] {};
	strcpy(this->name, name);
}

void StoreItem::print() const {
	std::cout << "[Type]: " << Helpers::convertTypeToStr(type) << std::endl;
	std::cout << "[Name]: " << name << std::endl;
	std::cout << "[Calories]: " << calories << std::endl;
	std::cout << "[Price]: " << price << std::endl;

}

void StoreItem::copyFrom(const StoreItem& other) {
	type = other.type;

	name = new char[std::strlen(other.name) + 1] {};
	strcpy(name, other.name);

	calories = other.calories;
	price = other.price;
}

void StoreItem::moveFrom(StoreItem&& other) {
	type = other.type;
	other.type = Type::None;

	name = other.name;
	other.name = nullptr;

	calories = other.calories;
	price = other.price;

	other.calories = other.price = 0;
}

void StoreItem::free() {
	type = Type::None;

	delete[] name;
	name = nullptr;

	calories = price = 0;
}