#include "Configuration.h"

void Configuration::copyFrom(const Configuration& other)
{
	components = new Component * [other.capacity] {};
	for (size_t i = 0; i < size; i++)
	{
		components[i] = other.components[i]->clone();
	}

	size = other.size;
	capacity = other.capacity;
}

void Configuration::moveFrom(Configuration&& other)
{
	components = other.components;
	other.components = nullptr;

	size = other.size;
	capacity = other.capacity;

	other.capacity = other.size = 0;
}

void Configuration::free()
{
	for (size_t i = 0; i < size; i++)
	{
		delete components[i];
	}

	delete[] components;
	components = nullptr;

	capacity = size = 0;
}

void Configuration::resize(size_t newCap)
{
	Component** newComponents = new Component * [newCap] {};
	for (size_t i = 0; i < size; i++)
	{
		newComponents[i] = components[i];
	}

	delete[] components;
	components = newComponents;
	newComponents = nullptr;

	capacity = newCap;
}

Configuration::Configuration()
{
	capacity = 8;
	size = 0;
	components = new Component * [capacity] {};
}

Configuration::Configuration(const Configuration& other)
{
	copyFrom(other);
}

Configuration& Configuration::operator=(const Configuration& other)
{
	if (this != &other)
	{
		free();
		copyFrom(other);
	}

	return *this;
}

Configuration::Configuration(Configuration&& other) noexcept
{
	moveFrom(std::move(other));
}

Configuration& Configuration::operator=(Configuration&& other) noexcept
{
	if (this != &other)
	{
		free();
		moveFrom(std::move(other));
	}

	return *this;
}

Configuration::~Configuration()
{
	free();
}

void Configuration::insert(Component* component)
{
	if (size == capacity)
	{
		resize(capacity * 2);
	}

	components[size++] = component;
}

double Configuration::price() const
{
	double res = 0.0;
	for (size_t i = 0; i < size; i++)
	{
		res += components[i]->price();
	}

	return res;
}

size_t Configuration::count() const
{
	return size;
}

const Component& Configuration::operator[](size_t index) const
{
	if (index >= size)
	{
		throw std::out_of_range("invalid index");
	}

	return *components[index];
}

std::ostream& operator<<(std::ostream& os, const Configuration& config)
{
	os << "<<<<< Configuration >>>>>" << std::endl;
	for (size_t i = 0; i < config.size; i++)
	{
		config.components[i]->output(os);
	}

	std::cout << "-------------------" << std::endl;
	std::cout << "[Total Price]: " << config.price() << std::endl;

	return os;
}