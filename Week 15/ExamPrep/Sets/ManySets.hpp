#pragma once
#include <iostream>
#include "Container.hpp"
#include "Even.hpp"
#include "Range.hpp"
#include "Set.hpp"

template <typename T>
class ManySets {
public:
	
	ManySets();

	ManySets(const ManySets<T>& other);
	ManySets<T>& operator=(const ManySets<T>& other);
	
	ManySets(ManySets<T>&& other) noexcept;
	ManySets<T>& operator=(ManySets<T>&& other) noexcept;

	~ManySets();

	void addSet(const Set<T>& set);

	const Set<T>* operator[](size_t index) const;
	Set<T>* operator[](size_t index);

	template <typename V>
	friend std::ostream& operator<<(std::ostream& os, const ManySets<V>& ms);

	template <typename V>
	friend std::istream& operator>>(std::istream& is, ManySets<V>& ms);

private:

	Set<T>** sets;
	size_t size;
	size_t capacity;

	void resize(size_t newCap);
	
	void free();
	void copyFrom(const ManySets<T>& other);
	void moveFrom(ManySets<T>&& other);
};

template <typename T>
ManySets<T>::ManySets() {
	capacity = 8;
	size = 0;
	sets = new Set<T>*[capacity] {};
}

template <typename T>
ManySets<T>::ManySets(const ManySets<T>& other) {
	copyFrom(other);
}

template <typename T>
ManySets<T>& ManySets<T>::operator=(const ManySets<T>& other) {
	if (this != &other) {
		free();
		copyFrom(other);
	}

	return *this;
}

template <typename T>
ManySets<T>::ManySets(ManySets<T>&& other) noexcept {
	moveFrom(std::move(other));
}

template <typename T>
ManySets<T>& ManySets<T>::operator=(ManySets<T>&& other) noexcept {
	if (this != &other) {
		free();
		moveFrom(std::move(other));
	}

	return *this;
}

template <typename T>
ManySets<T>::~ManySets() {
	for (size_t i = 0; i < size; i++) {
		delete sets[i];
	}

	delete[] sets;
	sets = nullptr;

	capacity = size = 0;
}

template <typename T>
void ManySets<T>::addSet(const Set<T>& set) {
	if (size == capacity) {
		resize(capacity * 2);
	}

	sets[size++] = set.clone();
}

template <typename T>
std::ostream& operator<<(std::ostream& os, const ManySets<T>& ms) {
	for (int i = 0; i < ms.size; i++) {
		ms.sets[i]->serialize(os);
	}

	return os;
}

template <typename T>
std::istream& operator>>(std::istream& is, ManySets<T>& ms) {
	for (int i = 0; i < ms.size; i++) {
		ms.sets[i]->deserialize(is);
	}

	return is;
}

template <typename T>
void ManySets<T>::resize(size_t newCap) {
	Set<T>** newSets = new Set<T>*[newCap] {};
	for (size_t i = 0; i < size; i++) {
		newSets[i] = sets[i];
	}

	delete[] sets;
	sets = newSets;
	newSets = nullptr;

	capacity = newCap;
}

template <typename T>
void ManySets<T>::free() {
	for (size_t i = 0; i < size; i++) {
		delete sets[i];
	}

	delete[] sets;
	sets = nullptr;

	capacity = size = 0;
}

template <typename T>
void ManySets<T>::copyFrom(const ManySets<T>& other) {
	sets = new Set<T>*[other.capacity] {};
	for (size_t i = 0; i < other.size; i++) {
		sets[i] = other.sets[i]->clone();
	}

	size = other.size;
	capacity = other.capacity;
}

template <typename T>
void ManySets<T>::moveFrom(ManySets<T>&& other) {
	sets = other.sets;
	other.sets = nullptr;

	size = other.size;
	other.size = 0;

	capacity = other.capacity;
	other.capacity = 0;
}

template <typename T>
const Set<T>* ManySets<T>::operator[](size_t index) const {
	if (index >= size) {
		throw std::out_of_range("invalid index");
	}

	return sets[index];
}

template <typename T>
Set<T>* ManySets<T>::operator[](size_t index) {
	if (index >= size) {
		throw std::out_of_range("invalid index");
	}

	return sets[index];
}