#include "CheckBox.h"

CheckBox::CheckBox(const Size& size, const Location& location, const char* text, bool turned) :
	Control(size, location), turned(turned) {

	setText(text);
}

CheckBox::CheckBox(const CheckBox& other): Control(other) {
	copyFrom(other);
}

CheckBox& CheckBox::operator=(const CheckBox& other) {
	if (this != &other) {
		Control::operator=(other);
		free();
		copyFrom(other);
	}

	return *this;
}

CheckBox::CheckBox(CheckBox&& other) noexcept : Control(std::move(other)) {
	moveFrom(std::move(other));
}

CheckBox& CheckBox::operator=(CheckBox&& other) noexcept {
	if (this != &other) {
		Control::operator=(std::move(other));
		free();
		moveFrom(std::move(other));
	}

	return *this;
}

CheckBox::~CheckBox() {
	free();
}

void CheckBox::setDataDialog() {
	
	std::cout << "Set turned to: [1] on, [0] off" << std::endl;
	int temp;
	std::cin >> temp;
	turned = temp;
}

Control* CheckBox::clone() const {
	return new CheckBox(*this);
}

void CheckBox::free() {
	delete[] text;
	text = nullptr;

	turned = false;
}

void CheckBox::copyFrom(const CheckBox& other) {
	text = new char[std::strlen(other.text) + 1] {};
	strcpy(text, other.text);

	turned = other.turned;
}

void CheckBox::moveFrom(CheckBox&& other) {
	text = other.text;
	other.text = nullptr;

	turned = other.turned;
	other.turned = false;
}

void CheckBox::setText(const char* text) {
	if (!text) {
		throw std::invalid_argument("invalid text");
	}

	this->text = new char[std::strlen(text) + 1] {};
	strcpy(this->text, text);
}