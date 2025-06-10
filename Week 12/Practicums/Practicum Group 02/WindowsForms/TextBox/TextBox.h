#pragma once
#include "Control.h"

class TextBox: public Control {
public:
	TextBox(const Size& size, const Location& location, const char* text);

	TextBox(const TextBox& other);
	TextBox& operator=(const TextBox& other);

	TextBox(TextBox&& other) noexcept;
	TextBox& operator=(TextBox&& other) noexcept;

	~TextBox();

	virtual void setDataDialog() override;
	virtual Control* clone() const override;

private:
	char* text = nullptr;

	void setText(const char* text);

	void free();
	void copyFrom(const TextBox& other);
	void moveFrom(TextBox&& other);
};

