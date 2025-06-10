#include "Forms.h"

Forms::Forms(const char* name, const Size& size): size(size)
{
	capacity = 8;
	cnt = 0;
	controls = new Control*[capacity]{};

	setName(name);
}

Forms::Forms(const Forms& other) {
	copyFrom(other);
}

Forms& Forms::operator=(const Forms& other) {
	if (this != &other) {
		free();
		copyFrom(other);
	}

	return *this;
}

Forms::Forms(Forms&& other) noexcept {
	moveFrom(std::move(other));
}

Forms& Forms::operator=(Forms&& other) noexcept {
	if (this != &other) {
		free();
		moveFrom(std::move(other));
	}

	return *this;
}

Forms::~Forms() {
	free();
}

void Forms::resize(size_t newCap) {
	Control** newControls = new Control * [newCap] {};
	for (size_t i = 0; i < cnt; i++) {
		newControls[i] = controls[i];
	}

	delete[] controls;
	controls = newControls;
	
	newControls = nullptr;
	capacity = newCap;
}

void Forms::free() {
	for (size_t i = 0; i < cnt; i++) {
		delete controls[i];
		controls[i] = nullptr;
	}

	delete[] controls;
	controls = nullptr;

	capacity = cnt = 0;
}

void Forms::copyFrom(const Forms& other) {
	controls = new Control * [other.capacity] {};
	for (size_t i = 0; i < other.cnt; i++) {
		controls[i] = other.controls[i]->clone();
	}

	cnt = other.cnt;
	capacity = other.capacity;
}

void Forms::moveFrom(Forms&& other) {
	controls = other.controls;
	other.controls = nullptr;

	cnt = other.cnt;
	capacity = other.capacity;

	other.capacity = other.cnt = 0;
}

void Forms::setName(const char* name) {
	if (!name) {
		throw std::invalid_argument("invalid name");
	}

	this->name = new char[std::strlen(name) + 1] {};
	strcpy(this->name, name);
}

void Forms::addControl(const Control& c) {
	if (cnt == capacity) {
		resize(capacity * 2);
	}

	controls[cnt++] = c.clone();
}

void Forms::changeSize(const Size& s) {
	
	this->size = s;
	
	for (size_t i = 0; i < cnt; i++) {
		controls[i]->setSize(s);
	}
}

void Forms::changeLocation(const Location& l) {
	for (size_t i = 0; i < cnt; i++) {
		controls[i]->setLocation(l);
	}
}

void Forms::change(size_t index) {
	if (index >= cnt) {
		throw std::out_of_range("err");
	}

	controls[index]->setDataDialog();
}