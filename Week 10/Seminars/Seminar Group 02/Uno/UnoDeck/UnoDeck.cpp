#include "UnoDeck.h"

void UnoDeck::copyFrom(const UnoDeck& other)
{
	cards = new UnoCard*[other.capacity]{};
	size = other.size;
	capacity = other.capacity;

	for (size_t i = 0; i < size; i++)
	{
		cards[i] = other.cards[i]->clone();
	}
}

void UnoDeck::moveFrom(UnoDeck&& other)
{
	cards = other.cards;
	other.cards = nullptr;

	size = other.size;
	capacity = other.capacity;

	other.capacity = other.size = 0;
}

void UnoDeck::free()
{
	for (size_t i = 0; i < size; i++)
	{
		delete cards[i];
	}

	delete[] cards;
}

void UnoDeck::resize(size_t newCap)
{
	UnoCard** newCards = new UnoCard * [newCap] {};

	for (size_t i = 0; i < size; i++)
	{
		newCards[i] = cards[i];
	}

	delete[] cards;
	cards = newCards;
	newCards = nullptr;

	capacity = newCap;
}

UnoDeck::UnoDeck()
{
	capacity = 8;
	size = 0;
	cards = new UnoCard * [capacity] {};
}

UnoDeck::UnoDeck(const UnoDeck& other)
{
	copyFrom(other);
}

UnoDeck& UnoDeck::operator=(const UnoDeck& other)
{
	if (this != &other)
	{
		free();
		copyFrom(other);
	}

	return *this;
}

UnoDeck::UnoDeck(UnoDeck&& other) noexcept
{
	moveFrom(std::move(other));
}

UnoDeck& UnoDeck::operator=(UnoDeck&& other) noexcept
{
	if (this != &other)
	{
		free();
		moveFrom(std::move(other));
	}

	return *this;
}

UnoDeck::~UnoDeck()
{
	free();
}

void UnoDeck::add()
{
	if (size == capacity)
	{
		resize(capacity * 2);
	}

	cards[size++] = unoFactory();
}

void UnoDeck::remove(const NumberCard* card)
{
	for (size_t i = 0; i < size; i++)
	{
		if (cards[i]->isEqualTo(card))
		{
			std::swap(cards[i], cards[size - 1]);
			size--;
			return;
		}
	}

	add();
}

void UnoDeck::print() const
{
	std::cout << "---[Deck]---" << std::endl;
	for (size_t i = 0; i < size; i++)
	{
		cards[i]->print();
	}
	
	std::cout << std::endl;
}