#include "GrString.h"

GrString::GrString(const char* str) {
	setStr(str);
}

GrString::GrString(const GrString& other) {
	copyFrom(other);
}

GrString& GrString::operator=(const GrString& other) {
	if (this != &other) {
		free();
		copyFrom(other);
	}

	return *this;
}

GrString::GrString(GrString&& other) noexcept {
	moveFrom(std::move(other));
}

GrString& GrString::operator=(GrString&& other) noexcept {
	if (this != &other) {
		free();
		moveFrom(std::move(other));
	}

	return *this;
}

GrString::~GrString() {
	free();
}

unsigned GrString::weight() const {
	size_t size = std::strlen(str);

	unsigned weight = 0;
	for (size_t i = 0; i <= size; i++) {
		weight += int(str[i]);
	}

	return weight;
}

const char* GrString::c_str() const {
	return str;
}

void GrString::setStr(const char* str) {
	if (!str || this->str == str) {
		return;
	}

	delete[] this->str;
	this->str = new char[std::strlen(str) + 1] {};
	strcpy(this->str, str);
}

GrString& GrString::operator+=(const GrString& other) {
	char* res = new char [std::strlen(str) + std::strlen(other.str) + 1] {};
	strcpy(res, str);
	strcat(res, other.str);
	setStr(res);
	return *this;
}

GrString& GrString::operator/=(const GrString& other) {
	
	char* res = new char[std::strlen(str) + 1] {};
	
	size_t at = 0;
	for (size_t i = 0; i < std::strlen(str); i++) {
		bool is_found = false;
		for (size_t j = 0; j < std::strlen(other.str); j++) {
			if (str[i] == other.str[j]) {
				is_found = true;
				break;
			}
		}

		if (!is_found) {
			res[at++] = str[i];
		}
	}
		
	res[at] = '\0';
	setStr(res);
	delete[] res;
	return *this;
}

void GrString::free() {
	delete[] str;
	str = nullptr;
}

void GrString::copyFrom(const GrString& other) {
	str = new char[std::strlen(other.str) + 1] {};
	strcpy(str, other.str);
}

void GrString::moveFrom(GrString&& other) {
	str = other.str;
	other.str = nullptr;
}

std::istream& operator>>(std::istream& is, GrString& obj) {
	char buff[1024];
	is >> buff;
	obj.setStr(buff);

	return is;
}

std::ostream& operator<<(std::ostream& os, const GrString& obj) {
	return os << obj.c_str();
}

GrString operator+(const GrString& lhs, const GrString& rhs) {
	GrString res(lhs.c_str());
	res += rhs;
	return res;
}

bool operator==(const GrString& lhs, const GrString& rhs) {
	return lhs.weight() == rhs.weight();
}