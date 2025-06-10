#include "TextBox.h"

TextBox::TextBox(const Size& size, const Location& location, const char* text) :
	Control(size, location) {

	setText(text);
}

TextBox::TextBox(const TextBox& other): Control(other) {
	copyFrom(other);
}

TextBox& TextBox::operator=(const TextBox& other) {
	if (this != &other) {
		Control::operator=(other);
		free();
		copyFrom(other);
	}

	return *this;
}

TextBox::TextBox(TextBox&& other) noexcept : Control(std::move(other)) {
	moveFrom(std::move(other));
}

TextBox& TextBox::operator=(TextBox&& other) noexcept {
	if (this != &other) {
		Control::operator=(std::move(other));
		free();
		moveFrom(std::move(other));
	}

	return *this;
}

TextBox::~TextBox() {
	free();
}

void TextBox::setDataDialog() {

	std::cout << "Set text to:" << std::endl;
	std::cin.ignore();

	char buff[1024]{};
	std::cin.getline(buff, 1024);

	delete[] this->text;
	this->text = new char[std::strlen(buff) + 1] {};
	strcpy(this->text, buff);
}

Control* TextBox::clone() const {
	return new TextBox(*this);
}

void TextBox::setText(const char* text) {
	if (!text) {
		throw std::invalid_argument("invalid text");
	}

	this->text = new char[std::strlen(text) + 1] {};
	strcpy(this->text, text);
}

void TextBox::free() {
	delete[] text;
	text = nullptr;
}

void TextBox::copyFrom(const TextBox& other) {
	text = new char[std::strlen(other.text) + 1] {};
	strcpy(text, other.text);
}

void TextBox::moveFrom(TextBox&& other) {
	text = other.text;
	other.text = nullptr;
}
