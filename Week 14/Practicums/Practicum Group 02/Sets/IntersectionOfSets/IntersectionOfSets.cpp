#include "IntersectionOfSets.h"

IntersectionOfSets::IntersectionOfSets(const Set* const* sets, size_t size) {
	copySets(sets, size);
}
IntersectionOfSets::IntersectionOfSets(Set**&& sets, size_t size) {
	moveSets(std::move(sets), size);
}

bool IntersectionOfSets::accepts(unsigned int el) const {
	for (size_t i = 0; i < size; i++) {
		if (sets[i]->accepts(el)) {
			return true;
		}
	}

	return false;
}

Set* IntersectionOfSets::clone() const {
	return new IntersectionOfSets(*this);
}

void IntersectionOfSets::copySets(const Set* const* sets, size_t size) {
	this->sets = new Set * [size] {};
	this->size = size;

	for (size_t i = 0; i < size; i++) {
		this->sets[i] = sets[i]->clone();
	}
}

void IntersectionOfSets::moveSets(Set**&& sets, size_t size) {
	this->size = size;
	this->sets = sets;
}
