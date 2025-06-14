#pragma once
#include "Dish.h"
#include "MeatDish.h"
#include "SeafoodDish.h"

class SurfAndTurf: public MeatDish, public SeafoodDish {
public:

	SurfAndTurf(const MyString* ingredients, size_t size, const MyString& meat, const MyString& seafood);

	void print() const override;
};

