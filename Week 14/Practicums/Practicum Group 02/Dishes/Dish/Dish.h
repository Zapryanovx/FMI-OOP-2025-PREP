#pragma once
#include <iostream>
#include "MyString.h"

namespace DishConstants {
	constexpr size_t MAX_DISHES = 100;
}

class Dish
{
public:
	Dish(const MyString* ingredients, size_t size);
	
	virtual void print() const = 0;

private:
	MyString ingredients[100]{};
	size_t size;
	size_t cookTime;

	void initIngredients(const MyString* ingedients, size_t size);
};

