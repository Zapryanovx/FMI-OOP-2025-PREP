#pragma once
#pragma warning(disable:4996)
#include "StoreItem.h"

class Fruit: public StoreItem
{
public:
	Fruit(Type type, unsigned calories, double price, const char* name, const char* color);

	Fruit(const Fruit& other);
	Fruit& operator=(const Fruit& other);

	Fruit(Fruit&& other) noexcept;
	Fruit& operator=(Fruit&& other) noexcept;

	~Fruit();

	void setColor(const char* color);

	StoreItem* clone() const override;
	void print() const override;

private:
	char* color = nullptr;

	void copyFrom(const Fruit& other);
	void moveFrom(Fruit&& other);
	void free();
};

bool operator>(const Fruit& lhs, const Fruit& rhs);

