#pragma once
#include "Dish.h"

class SeafoodDish: virtual public Dish
{
public:
	SeafoodDish(const MyString* ingredients, size_t size, const MyString& seafood);

	virtual void print() const override;

protected:
	const MyString& getSeafood() const;

private:

	void setSeafood(const MyString& seafood);
	
	MyString seafood;
};

