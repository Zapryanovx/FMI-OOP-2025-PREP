#include "Dish.h"

Dish::Dish(const MyString* ingredients, size_t size) {
	initIngredients(ingredients, size);
}

void Dish::print() const {
	std::cout << "[Ingredients]: ";
	for (size_t i = 0; i < size; i++) {
		std::cout << ingredients[i].c_str();

		if (i != size - 1) {
			std::cout << ", ";
		}
	}
	std::cout << std::endl;
}

void Dish::initIngredients(const MyString* ingredients, size_t size) {
	if (size > DishConstants::MAX_DISHES) {
		throw std::out_of_range("size is too much");
	}

	for (size_t i = 0; i < size; i++) {
		this->ingredients[i] = ingredients[i];
	}

	this->size = size;
}