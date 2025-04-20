#pragma once
#include "Item.h"

class ShoppingCart
{
public:
	ShoppingCart();
	ShoppingCart(const ShoppingCart& other);
	ShoppingCart& operator=(const ShoppingCart& other);
	~ShoppingCart();

	void addItem(const Item& item);
	void removeItem(const char* name);

	size_t itemsCount() const;
	bool exists(const char* name) const;
	bool isEmpty() const;
	
	double getPriceOf(const char* name) const;
	double totalPrice() const;

	void sortByName();

	void print() const;

	void saveToBinary(std::ofstream& ofs);
	void readFromBinary(std::ifstream& ifs);

private:
	Item* items;
	size_t size;
	size_t capacity;

	void copyFrom(const ShoppingCart& other);
	void free();
	void resize(size_t newCap);
};

