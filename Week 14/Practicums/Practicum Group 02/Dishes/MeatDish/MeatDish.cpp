#include "MeatDish.h"

MeatDish::MeatDish(const MyString* ingredients, size_t size, const MyString& meat): Dish(ingredients, size) {
	setMeat(meat);
}

void MeatDish::print() const {
	Dish::print();
	std::cout << "[Protein] :";
	std::cout << meat.c_str() << std::endl;
}

void MeatDish::setMeat(const MyString& meat) {
	if (meat != "chicken" && meat != "beef" && meat != "pork" && meat != "duck") {
		throw std::invalid_argument("invalid meat");
	}

	this->meat = meat;
}

const MyString& MeatDish::getMeat() const {
	return meat;
}