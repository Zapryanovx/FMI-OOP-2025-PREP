#include "SeafoodDish.h"

SeafoodDish::SeafoodDish(const MyString* ingredients, size_t size, size_t cookTime, const MyString& seafood) : 
	Dish(ingredients, size, cookTime) {
	setSeafood(seafood);
}

void SeafoodDish::print() const {
	Dish::print();
	std::cout << "[Seafood]: ";
	std::cout << seafood.c_str() << std::endl;

}

void SeafoodDish::setSeafood(const MyString& seafood) {
	this->seafood = seafood;
}

const MyString& SeafoodDish::getSeafood() const {
	return seafood;
}
