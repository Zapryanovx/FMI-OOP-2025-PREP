#include "Size.h"

Size::Size() : Size(2, 2) {}

Size::Size(size_t height, size_t width): height(height), width(width) {}

void Size::setHeight(size_t height) {
	this->height = height;
}

void Size::setWidth(size_t width) {
	this->width = width;
}