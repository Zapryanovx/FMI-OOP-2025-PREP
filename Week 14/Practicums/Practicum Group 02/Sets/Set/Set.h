#pragma once
#include <iostream>

class Set
{
public:

	virtual bool accepts(unsigned int el) const = 0;
	virtual Set* clone() const = 0;
	~Set() = default;

};

