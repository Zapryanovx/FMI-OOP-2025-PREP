#pragma once
#include <iostream>
#include <fstream>
#pragma warning(disable:4996)

class Component
{
public:
	Component(const char* name);

	Component(const Component& other);
	Component& operator=(const Component& other);

	Component(Component&& other) noexcept;
	Component& operator=(Component&& other) noexcept;

	virtual ~Component();

	const char* getName() const;

	virtual double price() const = 0;
	virtual void output(std::ostream& os) const = 0;

	virtual Component* clone() const = 0;

private:
	char* name;

	void setName(const char* name);

	void copyFrom(const Component& other);
	void moveFrom(Component&& other);
	void free();
};

