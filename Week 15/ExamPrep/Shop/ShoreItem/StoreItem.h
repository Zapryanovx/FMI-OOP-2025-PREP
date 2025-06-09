#pragma once
#pragma warning(disable:4996)
#include <iostream>
#include <stdexcept>

enum class Type {
	Fruit,
	Vegetable,
	None
};

namespace Helpers {
	static const char* convertTypeToStr(Type type) {
		switch (type) {
		case Type::Fruit:
			return "Fruit";
		case Type::Vegetable:
			return "Vegetable";
		default:
			return "None";
		}
	}
}

class StoreItem
{
public:
	StoreItem() = default;
	StoreItem(Type type, unsigned calories, double price, const char* name);

	StoreItem(const StoreItem& other);
	StoreItem& operator=(const StoreItem& other);

	StoreItem(StoreItem&& other) noexcept;
	StoreItem& operator=(StoreItem&& other) noexcept;

	virtual ~StoreItem();

	Type getType() const;
	void setType(Type type);

	unsigned getCalories() const;
	void setCalories(unsigned calories);

	double getPrice() const;
	void setPrice(double price);
	
	const char* getName() const;
	void setName(const char* name);

	virtual void print() const = 0;
	virtual StoreItem* clone() const = 0;

private:
	Type type = Type::None;
	char* name = nullptr;
	unsigned calories = 0;
	double price = 0.0;

	void copyFrom(const StoreItem& other);
	void moveFrom(StoreItem&& other);
	void free();
};

