#pragma once
#include "CustomPair.hpp"
#include <fstream>

template <typename K, typename V>
class FJSON
{
public:
	FJSON();

	FJSON(const FJSON& other);
	FJSON& operator = (const FJSON& other);

	FJSON(FJSON&& other) noexcept;
	FJSON& operator = (FJSON&& other) noexcept;

	~FJSON();

	void addPair(const CustomPair<K, V>& pair);
	void removePair(size_t index);
	void saveToFile(std::ofstream& file) const;

private:

	CustomPair<K, V>** pairs;
	size_t size = 0;
	size_t capacity = 8;

	void free();
	void copyFrom(const FJSON& other);
	void moveFrom(FJSON&& other);

	void resize(size_t newCap);

};

template <typename K, typename V>
FJSON<K, V>::FJSON() {
	capacity = 8;
	size = 0;
	pairs = new CustomPair<K, V>* [capacity] {};
}

template <typename K, typename V>
FJSON<K, V>::FJSON(const FJSON& other) {
	copyFrom(other);
}

template <typename K, typename V>
FJSON<K,V>& FJSON<K, V>::operator=(const FJSON& other) {
	if (this != &other) {
		free();
		copyFrom(other);
	}

	return*this;
}

template <typename K, typename V>
FJSON<K, V>::FJSON(FJSON&& other) noexcept {
	moveFrom(std::move(other));
}

template <typename K, typename V>
FJSON<K, V>& FJSON<K, V>::operator=(FJSON&& other) noexcept {
	if (this != &other) {
		free();
		moveFrom(std::move(other));
	}

	return *this;
}

template <typename K, typename V>
FJSON<K, V>::~FJSON() {
	free();
}

template <typename K, typename V>
void FJSON<K, V>::addPair(const CustomPair<K, V>& pair) {
	if (size == capacity) {
		resize(capacity * 2);
	}

	pairs[size++] = pair.clone();
}

template <typename K, typename V>
void FJSON<K, V>::removePair(size_t index) {
	if (index >= size) {
		throw std::out_of_range("invalid fjson");
	}

	delete pairs[index];
	pairs[index] = nullptr;
	std::swap(pairs[index], pairs[size - 1]);
}

template <typename K, typename V>
void FJSON<K, V>::saveToFile(std::ofstream& file) const {
	std::cout << "[Size]: " << size << std::endl;

	for (size_t i = 0; i < size; i++) {

		std::cout << "! " << pairs[i]->generateFormat() << " ! " << std::endl;

		file << pairs[i]->generateFormat();
	}
}

template <typename K, typename V>
void FJSON<K, V>::free() {
	for (int i = 0; i < size; i++) {
		delete pairs[i];
		pairs[i] = nullptr;
	}

	delete[] pairs;
	pairs = nullptr;
	capacity = size = 0;
}

template <typename K, typename V>
void FJSON<K, V>::copyFrom(const FJSON& other) {
	pairs = new CustomPair<K, V>* [other.capacity] {};
	for (size_t i = 0; i < other.size; i++) {
		pairs[i] = other.pairs[i]->clone();
	}

	size = other.size;
	capacity = other.capacity;
}

template <typename K, typename V>
void FJSON<K, V>::moveFrom(FJSON&& other) {
	pairs = other.pairs;
	other.pairs = nullptr;

	size = other.size;
	capacity = other.capacity;

	other.capacity = other.size = 0;
}

template <typename K, typename V>
void FJSON<K, V>::resize(size_t newCap) {
	CustomPair<K,V>** newPairs = new CustomPair<K, V>* [newCap] {};
	for (size_t i = 0; i < size; i++) {
		newPairs[i] = pairs[i];
	}

	delete[] pairs;
	pairs = newPairs;
	newPairs = nullptr;

	capacity = newCap;
}