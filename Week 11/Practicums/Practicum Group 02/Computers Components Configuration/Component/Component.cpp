#include "Component.h"

void Component::setName(const char* name)
{
	if (!name)
	{
		throw std::invalid_argument("invalid name");
	}

	this->name = new char[std::strlen(name) + 1] {};
	strcpy(this->name, name);
}

void Component::copyFrom(const Component& other)
{
	name = new char[std::strlen(name) + 1] {};
	strcpy(name, other.name);
}

void Component::moveFrom(Component&& other)
{
	name = other.name;
	other.name = nullptr;
}

void Component::free()
{
	delete[] name;
	name = nullptr;
}

Component::Component(const char* name)
{
	setName(name);
}

Component::Component(const Component& other)
{
	copyFrom(other);
}

Component& Component::operator=(const Component& other)
{
	if (this != &other)
	{
		free();
		copyFrom(other);
	}

	return *this;
}

Component::Component(Component&& other) noexcept
{
	moveFrom(std::move(other));
}

Component& Component::operator=(Component&& other) noexcept
{
	if (this != &other)
	{
		free();
		moveFrom(std::move(other));
	}

	return *this;
}

Component::~Component()
{
	free();
}

const char* Component::getName() const
{
	return name;
}
