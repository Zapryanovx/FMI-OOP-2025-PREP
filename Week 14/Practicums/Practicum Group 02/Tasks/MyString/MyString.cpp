#include "MyString.h"

MyString::MyString(const char* str) {
	setStr(str);
	setSize(std::strlen(str));
}

MyString::MyString(const MyString& other) {
	copyFrom(other);
}

MyString& MyString::operator=(const MyString& other) {
	if (this != &other) {
		free();
		copyFrom(other);
	}

	return *this;
}

MyString::MyString(MyString&& other) noexcept {
	moveFrom(std::move(other));
}

MyString& MyString::operator=(MyString&& other) noexcept {
	if (this != &other) {
		free();
		moveFrom(std::move(other));
	}

	return *this;
}

MyString::~MyString() {
	free();
}

const char* MyString::c_str() const {
	return str;
}

size_t MyString::length() const {
	return size;
}

void MyString::setStr(const char* str) {
	if (!str) {
		throw std::invalid_argument("invalid str");
	}

	this->str = new char[std::strlen(str) + 1] {};
	strcpy(this->str, str);
}

void MyString::setSize(size_t size) {
	this->size = size;
}

void MyString::free() {
	delete[] str;
	str = nullptr;

	size = 0;
}

void MyString::copyFrom(const MyString& other) {
	str = new char[std::strlen(other.str) + 1] {};
	strcpy(str, other.str);

	size = other.size;
}

void MyString::moveFrom(MyString&& other) {
	str = other.str;
	other.str = nullptr;

	size = other.size;
	other.size = 0;
}