#pragma once
#pragma warning(disable:4996)
#include "Size.h"
#include "Location.h"
#include <iostream>

class Control
{
public:

	Control(const Size& size, const Location& location);

	virtual void setDataDialog() = 0;
	virtual Control* clone() const = 0;
	virtual ~Control() = default;

	void setSize(const Size& size);
	void setLocation(const Location& location);

protected:
	Size size;
	Location location;
};

