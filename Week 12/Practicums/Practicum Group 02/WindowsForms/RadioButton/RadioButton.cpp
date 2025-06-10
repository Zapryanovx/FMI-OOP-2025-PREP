#include "RadioButton.h"

RadioButton::RadioButton(const Size& size, const Location& location, const Option* options, size_t cnt) :
	Control(size, location) {

	initOptions(options, cnt);
}

RadioButton::RadioButton(const RadioButton& other) : Control(other) {
	copyFrom(other);
}

RadioButton& RadioButton::operator=(const RadioButton& other) {
	if (this != &other) {
		Control::operator=(other);
		free();
		copyFrom(other);
	}

	return *this;
}

RadioButton::RadioButton(RadioButton&& other) noexcept : Control(std::move(other)) {
	moveFrom(std::move(other));
}

RadioButton& RadioButton::operator=(RadioButton&& other) noexcept {
	if (this != &other) {
		Control::operator=(std::move(other));
		free();
		moveFrom(std::move(other));
	}

	return *this;
}

RadioButton::~RadioButton() {
	free();
}

void RadioButton::setDataDialog() {
	
	std::cout << "Set text to selected option:" << std::endl;
	std::cin.ignore();

	char buff[1024]{};
	std::cin.getline(buff, 1024);
	
	for (size_t i = 0; i < cnt; i++) {
		if (options[i].getSelected()) {
			options[i].setText(buff);
		}
	}

}

Control* RadioButton::clone() const {
	return new RadioButton(*this);
}

void RadioButton::initOptions(const Option* options, size_t cnt) {
	
	this->cnt = cnt;
	this->options = new Option[cnt]{};
	for (size_t i = 0; i < cnt; i++) {
		this->options[i] = Option(options[i]);
	}

}

void RadioButton::free() {
	delete[] options;
	options = nullptr;
	
	cnt = 0;
}

void RadioButton::copyFrom(const RadioButton& other) {
	
	options = new Option[other.cnt] {};
	
	for (size_t i = 0; i < other.cnt; i++) {
		options[i] = other.options[i];
	}

	cnt = other.cnt;
}

void RadioButton::moveFrom(RadioButton&& other) {
	options = other.options;
	other.options = nullptr;

	cnt = other.cnt;
	other.cnt = 0;
}