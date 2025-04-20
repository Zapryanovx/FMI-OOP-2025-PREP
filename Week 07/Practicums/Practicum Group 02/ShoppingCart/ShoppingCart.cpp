#include "ShoppingCart.h"

void ShoppingCart::copyFrom(const ShoppingCart& other)
{
	size = other.size;
	capacity = other.capacity;

	items = new Item[capacity]{};
	for (size_t i = 0; i < size; i++)
	{
		items[i] = other.items[i];
	}
}

void ShoppingCart::free()
{
	delete[] items;
	items = nullptr;

	capacity = size = 0;
}

void ShoppingCart::resize(size_t newCap)
{
	Item* newItems = new Item[newCap]{};
	for (size_t i = 0; i < size; i++)
	{
		newItems[i] = items[i];
	}

	delete[] items;
	items = newItems;
	newItems = nullptr;

	capacity = newCap;
}

ShoppingCart::ShoppingCart()
{
	size = 0;
	capacity = 8;
	items = new Item[capacity]{};
}

ShoppingCart::ShoppingCart(const ShoppingCart& other)
{
	copyFrom(other);
}

ShoppingCart& ShoppingCart::operator=(const ShoppingCart& other)
{
	if (this != &other)
	{
		free();
		copyFrom(other);
	}

	return *this;
}

ShoppingCart::~ShoppingCart()
{
	free();
}

void ShoppingCart::addItem(const Item& item)
{
	if (exists(item.getName().c_str()))
	{
		return;
	}

	if (size == capacity)
	{
		resize(capacity * 2);
	}

	items[size++] = item;
}

void ShoppingCart::removeItem(const char* name)
{
	if (!name || !exists(name))
	{
		return;
	}
	
	for (size_t i = 0; i < size; i++)
	{
		if (!std::strcmp(items[i].getName().c_str(), name))
		{
			std::swap(items[i], items[size - 1]);
			size--;
			break;
		}
	}

}

size_t ShoppingCart::itemsCount() const
{
	return size;
}

bool ShoppingCart::exists(const char* name) const
{
	for (size_t i = 0; i < size; i++)
	{
		if (!std::strcmp(items[i].getName().c_str(), name))
		{
			return true;
		}
	}

	return false;
}

bool ShoppingCart::isEmpty() const
{
	return size == 0;
}

double ShoppingCart::getPriceOf(const char* name) const
{
	if (!name || !exists(name))
	{
		return 0;
	}

	for (size_t i = 0; i < size; i++)
	{
		if (!std::strcmp(items[i].getName().c_str(), name))
		{
			return items[i].getPrice();
		}
	}

	return 0;
}

double ShoppingCart::totalPrice() const
{
	double res = 0;
	for (size_t i = 0; i < size; i++)
	{
		res += items[i].getPrice();
	}

	return res;
}

void ShoppingCart::print() const
{
	std::cout << "---[Shopping Cart]---" << std::endl;
	for (size_t i = 0; i < size; i++)
	{
		items[i].print();
	}
}

void ShoppingCart::sortByName()
{
	for (size_t i = 0; i < size - 1; i++)
	{
		size_t minIdx = i;
		for (size_t j = 0; j < size; j++)
		{
			if (items[j].getName() < items[minIdx].getName())
			{
				minIdx = j;
			}
		}

		if (minIdx != i)
		{
			std::swap(items[minIdx], items[i]);
		}
	}
}

void ShoppingCart::saveToBinary(std::ofstream& ofs)
{
	ofs.write((const char*)&capacity, sizeof(size_t));
	ofs.write((const char*)&size, sizeof(size_t));

	for (size_t i = 0; i < size; i++)
	{
		items[i].saveToBinary(ofs);
	}
}

void ShoppingCart::readFromBinary(std::ifstream& ifs)
{
	free();

	ifs.read((char*)&capacity, sizeof(size_t));
	ifs.read((char*)&size, sizeof(size_t));

	items = new Item[capacity]{};
	for (size_t i = 0; i < size; i++)
	{
		items[i].readFromBinary(ifs);
	}
}