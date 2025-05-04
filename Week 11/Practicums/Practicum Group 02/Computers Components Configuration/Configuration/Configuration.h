#pragma once
#include "Component.h"
#include "Memory.h"
#include "CPU.h"

class Configuration
{
public:
	Configuration();

	Configuration(const Configuration& other);
	Configuration& operator=(const Configuration& other);

	Configuration(Configuration&& other) noexcept;
	Configuration& operator=(Configuration&& other) noexcept;
	
	~Configuration();

	void insert(Component* component);
	double price() const;
	size_t count() const;

	const Component& operator[](size_t index) const;
	friend std::ostream& operator<<(std::ostream& os, const Configuration& config);

private:
	Component** components;
	size_t size;
	size_t capacity;

	void copyFrom(const Configuration& other);
	void moveFrom(Configuration&& other);
	void free();

	void resize(size_t newCap);
};

