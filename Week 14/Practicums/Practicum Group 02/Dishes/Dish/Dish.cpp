#include "Dish.h"

Dish::Dish(const MyString* ingredients, size_t size, size_t cookTime) {
	initIngredients(ingredients, size);
	setCookTime(cookTime);
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
	std::cout << "[Cook Time]: " << cookTime << std::endl;
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

void Dish::setCookTime(size_t cookTime) {
	this->cookTime = cookTime;
}
