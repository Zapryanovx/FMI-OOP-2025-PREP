#include "Option.h"

Option::Option() : Option("default", false) {}

Option::Option(const char* text, bool selected) {
	setText(text);
	setSelected(selected);
}

Option::Option(const Option& other) {
	copyFrom(other);
}

Option& Option::operator=(const Option& other) {
	if (this != &other) {
		free();
		copyFrom(other);
	}

	return *this;
}

Option::Option(Option&& other) noexcept {
	moveFrom(std::move(other));
}

Option& Option::operator=(Option&& other) {
	if (this != &other) {
		free();
		moveFrom(std::move(other));
	}

	return *this;
}

Option::~Option() {
	free();
}

bool Option::getSelected() const {
	return selected;
}

void Option::setText(const char* text) {
	if (!text || this->text == text) {
		return;
	}

	delete[] this->text;
	this->text = new char[std::strlen(text) + 1] {};
	strcpy(this->text, text);
}

void Option::setSelected(bool selected) {
	this->selected = selected;
}

void Option::free() {
	delete[] text;
	text = nullptr;

	selected = false;
}
void Option::copyFrom(const Option& other) {
	text = new char[std::strlen(other.text) + 1] {};
	strcpy(text, other.text);

	selected = other.selected;
}

void Option::moveFrom(Option&& other) {
	text = other.text;
	other.text = nullptr;

	selected = other.selected;
	other.selected = false;
}