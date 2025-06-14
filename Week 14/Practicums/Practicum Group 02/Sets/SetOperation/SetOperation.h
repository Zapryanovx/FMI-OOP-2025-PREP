#pragma once
#include "Set.h"

class SetOperation: public Set
{
public:

	SetOperation() = default;

	SetOperation(const SetOperation& other);
	SetOperation& operator=(const SetOperation& other);

	SetOperation(SetOperation&& other) noexcept;
	SetOperation& operator=(SetOperation&& other) noexcept;

	~SetOperation();

protected:
	Set** sets = nullptr;
	size_t size = 0;

	void free();
	void copyFrom(const SetOperation& other);
	void moveFrom(SetOperation&& other);
};

