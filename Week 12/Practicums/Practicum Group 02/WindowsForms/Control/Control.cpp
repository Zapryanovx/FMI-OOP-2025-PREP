#include "Control.h"

Control::Control(const Size& size, const Location& location): size(size), location(location) {}

void Control::setSize(const Size& size) {
	this->size = size;
}

void Control::setLocation(const Location& location) {
	this->location = location;
}