#pragma once
#include "Dish.h"

class MeatDish : virtual public Dish
{
public:
	MeatDish(const MyString* ingredients, size_t size, const MyString& meat);

	virtual void print() const override;

protected:
	const MyString& getMeat() const;

private:

	void setMeat(const MyString& meat);

	MyString meat;
};

