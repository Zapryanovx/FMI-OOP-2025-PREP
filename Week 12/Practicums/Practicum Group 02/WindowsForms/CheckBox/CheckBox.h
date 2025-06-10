#pragma once
#include "Control.h"

class CheckBox: public Control
{
public:
	CheckBox(const Size& size, const Location& location, const char* text, bool turned);

	CheckBox(const CheckBox& other);
	CheckBox& operator=(const CheckBox& other);

	CheckBox(CheckBox&& other) noexcept;
	CheckBox& operator=(CheckBox&& other) noexcept;

	~CheckBox();

	virtual void setDataDialog() override;
	virtual Control* clone() const override;

private:
	char* text = nullptr;
	bool turned = false;

	void setText(const char* text);

	void free();
	void copyFrom(const CheckBox& other);
	void moveFrom(CheckBox&& other);
};

