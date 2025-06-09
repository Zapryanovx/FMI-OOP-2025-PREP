#pragma once
#include "StoreItem.h"
#include "Fruit.h"
#include "Vegetable.h"

class Shop
{
public:
	Shop();

	Shop(const Shop& other);
	Shop& operator=(const Shop& other);

	Shop(Shop&& other) noexcept;
	Shop& operator=(Shop&& other) noexcept;

	~Shop();

	void addItem(const StoreItem& item);
	void removeItem(size_t at);

	void changePrice(size_t at, double newPrice);
	void changeName(size_t at, const char* newName);

	const StoreItem* findLowestCalories() const;
	void print() const;

private:
	StoreItem** items;
	size_t size;
	size_t capacity;

	void resize(size_t newCap);

	void free();
	void copyFrom(const Shop& other);
	void moveFrom(Shop&& other);
};

