#include "Shop.h"

Shop::Shop() {
	capacity = 8;
	size = 0;
	items = new StoreItem * [8] {nullptr};
}

Shop::Shop(const Shop& other) {
	copyFrom(other);
}

Shop& Shop::operator=(const Shop& other) {
	if (this != &other) {
		free();
		copyFrom(other);
	}
	
	return *this;
}

Shop::Shop(Shop&& other) noexcept {
	moveFrom(std::move(other));
}

Shop& Shop::operator=(Shop&& other) noexcept {
	if (this != &other) {
		free();
		moveFrom(std::move(other));
	}

	return *this;
}

Shop::~Shop() {
	free();
}

void Shop::addItem(const StoreItem& item) {
	if (size == capacity) {
		resize(capacity * 2);
	}

	items[size++] = item.clone();
}


void Shop::removeItem(size_t at) {
	if (at >= size) {
		throw std::out_of_range("invalid index");
	}

	delete items[at];
	for (size_t i = at; i < size - 1; i++) {
		items[i] = items[i + 1];
	}

	size--;
}

void Shop::changePrice(size_t at, double newPrice) {
	if (at >= size) {
		throw std::out_of_range("invalid index");
	}

	items[at]->setPrice(newPrice);
}

void Shop::changeName(size_t at, const char* newName) {
	if (at >= size) {
		throw std::out_of_range("invalid index");
	}

	items[at]->setName(newName);
}

const StoreItem* Shop::findLowestCalories() const {
	
	if (size == 0)
	{
		throw std::logic_error("shop is empty");
	}

	size_t maxIdx = 0;
	unsigned maxCalories = items[0]->getCalories();

	for (size_t i = 1; i < size; i++) {
		if (items[i]->getCalories() > maxCalories) {
			maxIdx = i;
			maxCalories = items[i]->getCalories();
		}
	}

	return items[maxIdx];
}

void Shop::print() const {
	for (size_t i = 0; i < size; i++)
	{
		items[i]->print();
	}
}

void Shop::resize(size_t newCap) {
	StoreItem** newItems = new StoreItem * [newCap] {};
	for (size_t i = 0; i < size; i++) {
		newItems[i] = items[i];
	}

	delete[] items;
	items = newItems;
	newItems = nullptr;

	capacity = newCap;
}

void Shop::free() {
	for (size_t i = 0; i < size; i++) {
		delete items[i];
		items[i] = nullptr;
	}

	delete[] items;
	items = nullptr;

	capacity = size = 0;
}

void Shop::copyFrom(const Shop& other) {
	items = new StoreItem * [other.capacity] {};
	for (size_t i = 0; i < other.size; i++) {
		items[i] = other.items[i]->clone();
	}

	size = other.size;
	capacity = other.capacity;
}

void Shop::moveFrom(Shop&& other) {
	items = other.items;
	other.items = nullptr;

	size = other.size;
	other.size = 0;

	capacity = other.capacity;
	other.capacity = 0;
}