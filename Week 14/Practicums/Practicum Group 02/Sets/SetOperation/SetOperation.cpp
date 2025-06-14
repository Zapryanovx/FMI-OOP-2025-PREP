#include "SetOperation.h"


SetOperation::SetOperation(const SetOperation& other) {
	copyFrom(other);
}

SetOperation& SetOperation::operator=(const SetOperation& other) {
	if (this != &other) {
		free();
		copyFrom(other);
	}

	return *this;
}

SetOperation::SetOperation(SetOperation&& other) noexcept {
	moveFrom(std::move(other));
}

SetOperation& SetOperation::operator=(SetOperation&& other) noexcept {
	if (this != &other) {
		free();
		moveFrom(std::move(other));
	}

	return *this;
}

SetOperation::~SetOperation() {
	free();
}

void SetOperation::free() {
	for (size_t i = 0; i < size; i++) {
		delete sets[i];
	}

	delete[] sets;
	sets = nullptr;

	size = 0;
}

void SetOperation::copyFrom(const SetOperation& other) {
	sets = new Set * [other.size] {};
	for (size_t i = 0; i < other.size; i++) {
		sets[i] = other.sets[i]->clone();
	}

	size = other.size;
}

void SetOperation::moveFrom(SetOperation&& other) {
	sets = other.sets;
	other.sets = nullptr;

	size = other.size;
	other.size = 0;
}