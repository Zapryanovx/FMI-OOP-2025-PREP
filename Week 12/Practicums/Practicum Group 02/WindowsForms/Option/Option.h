#pragma once
#pragma warning(disable:4996)
#include <iostream>

class Option {
public:
	Option();
	Option(const char* text, bool selected);

	Option(const Option& other);
	Option& operator=(const Option& other);

	Option(Option&& other) noexcept;
	Option& operator=(Option&& other);

	~Option();

	bool getSelected() const;

	void setText(const char* text);
	void setSelected(bool selected);

private:
	char* text = nullptr;
	bool selected = false;

	void free();
	void copyFrom(const Option& other);
	void moveFrom(Option&& other);
};

