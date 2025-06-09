#pragma once
#pragma warning(disable:4996)
#include "StoreItem.h"

class Vegetable: public StoreItem
{
public:
	Vegetable(Type type, unsigned calories, double price, const char* name, const char* sort);

	Vegetable(const Vegetable& other);
	Vegetable& operator=(const Vegetable& other);

	Vegetable(Vegetable&& other) noexcept;
	Vegetable& operator=(Vegetable&& other) noexcept;

	~Vegetable();

	const char* getSort() const;
	void setSort(const char* sort);

	StoreItem* clone() const override;
	void print() const override;

private:
	char* sort = nullptr;

	void free();
	void copyFrom(const Vegetable& other);
	void moveFrom(Vegetable&& other);
};

bool operator==(const Vegetable& lhs, const Vegetable& rhs);