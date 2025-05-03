#pragma once
#include "UnoCard.h"
#include "UnoDeck.h"
#include "NumberCard.h"
#include "UnoFactory.h"

class UnoDeck
{
public:
	UnoDeck();
	
	UnoDeck(const UnoDeck& other);
	UnoDeck& operator=(const UnoDeck& other);
	
	UnoDeck(UnoDeck&& other) noexcept;
	UnoDeck& operator=(UnoDeck&& other) noexcept;

	~UnoDeck();

	void add();
	void remove(const NumberCard* card);
	void print() const;

private:
	UnoCard** cards;
	size_t size;
	size_t capacity;

	void copyFrom(const UnoDeck& other);
	void moveFrom(UnoDeck&& other);
	void free();

	void resize(size_t newCap);

};

