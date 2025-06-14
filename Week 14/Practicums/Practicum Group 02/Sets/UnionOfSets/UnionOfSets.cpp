#include "UnionOfSets.h"

UnionOfSets::UnionOfSets(const Set* const* sets, size_t size) {
	copySets(sets, size);
}
UnionOfSets::UnionOfSets(Set**&& sets, size_t size) {
	moveSets(std::move(sets), size);
}

bool UnionOfSets::accepts(unsigned int el) const {
	for (size_t i = 0; i < size; i++) {
		if (!sets[i]->accepts(el)) {
			return false;
		}
	}

	return true;
}

Set* UnionOfSets::clone() const {
	return new UnionOfSets(*this);
}

void UnionOfSets::copySets(const Set* const* sets, size_t size) {
	this->sets = new Set * [size] {};
	this->size = size;
	
	for (size_t i = 0; i < size; i++) {
		this->sets[i] = sets[i]->clone();
	}
}

void UnionOfSets::moveSets(Set**&& sets, size_t size) {
	this->size = size;
	this->sets = sets;
}
