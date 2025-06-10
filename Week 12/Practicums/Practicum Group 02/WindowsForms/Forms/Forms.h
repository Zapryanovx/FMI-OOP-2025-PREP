#pragma once
#include "Control.h"
#include "Size.h"
#include "Location.h"

class Forms
{
public:
	Forms(const char* name, const Size& size);

	Forms(const Forms& other);
	Forms& operator=(const Forms& other);

	Forms(Forms&& other) noexcept;
	Forms& operator=(Forms&& other) noexcept;

	~Forms();

	void addControl(const Control& c);
	void changeSize(const Size& s);
	void changeLocation(const Location& l);
	void change(size_t index);

private:
	Control** controls = nullptr;
	size_t cnt = 0;
	size_t capacity = 0;

	char* name;
	Size size;

	void setName(const char* name);

	void resize(size_t newCap);
	
	void free();
	void copyFrom(const Forms& other);
	void moveFrom(Forms&& other);

};

