#pragma once 
#include "Sequence.hpp"

template <typename T>
class Fibonacci : public Sequence<T> {
public:

	Fibonacci(size_t capacity);

	Fibonacci(const Fibonacci<T>& other);
	Fibonacci& operator=(const Fibonacci<T>& other);

	Fibonacci(Fibonacci<T>&& other) noexcept;
	Fibonacci& operator=(Fibonacci<T>&& other) noexcept;

	~Fibonacci();

	virtual T getNth(int nth) override;
	void setCacheSize(size_t newCapacity);
	size_t getCacheSize() const;

private:
	T* cache;
	size_t capacity;

	void initCache();

	void free();
	void copyFrom(const Fibonacci<T>& other);
	void moveFrom(Fibonacci<T>& other);
};

template <typename T>
Fibonacci<T>::Fibonacci(size_t capacity): capacity(capacity) {
	initCache();
}

template <typename T>
Fibonacci<T>::Fibonacci(const Fibonacci<T>& other): Sequence(other) {
	copyFrom(other);
}

template <typename T>
Fibonacci<T>& Fibonacci<T>::operator=(const Fibonacci<T>& other) {
	if (this != &other) {
		Sequence::operator=(other);
		free();
		copyFrom(other);
	}

	return *this;
}

template <typename T>
Fibonacci<T>::Fibonacci(Fibonacci<T>&& other) noexcept: Sequence(std::move(other)) {
	moveFrom(other);
}

template <typename T>
Fibonacci<T>& Fibonacci<T>::operator=(Fibonacci<T>&& other) noexcept {
	if (this != &other) {
		Sequence::operator=(std::move(other));
		free();
		moveFrom(std::move(other));
	}

	return *this;
}

template <typename T>
Fibonacci<T>::~Fibonacci() {
	free();
}

template <typename T>
void Fibonacci<T>::initCache() {
	if (capacity == 0) {
		throw std::invalid_argument("size of fib must be at least 1");
	}

	if (capacity == 1) {
		cache = new T[1]{};
		cache[0] = 0;
		return;
	}

	else if (capacity == 2) {
		cache = new T[2]{};
		cache[0] = 0;
		cache[1] = 1;
		return;
	}

	cache = new T[capacity]{};
	cache[0] = 0;
	cache[1] = 1;
	for (int i = 2; i < capacity; i++) {
		cache[i] = cache[i - 1] + cache[i - 2];
	}
}

template <typename T>
void Fibonacci<T>::free() {
	delete[] cache;
	cache = nullptr;

	capacity = 0;
}

template <typename T>
void Fibonacci<T>::copyFrom(const Fibonacci<T>& other) {
	cache = new T[other.capacity]{};
	for (int i = 0; i < other.capacity; i++) {
		cache[i] = other.cache[i];
	}

	capacity = other.capacity;
}

template <typename T>
void Fibonacci<T>::moveFrom(Fibonacci<T>& other) {
	cache = other.cache;
	other.cache = nullptr;

	capacity = other.capacity;
	other.capacity = 0;
}

template <typename T>
T Fibonacci<T>::getNth(int nth) {
	if (nth > capacity) {
		setCacheSize(nth);
	}

	return cache[nth];
}

template <typename T>
void Fibonacci<T>::setCacheSize(size_t newCapacity) {

	if (newCapacity < capacity) {
		return;
	}

	capacity = newCapacity;
	initCache();
}

template <typename T>
size_t Fibonacci<T>::getCacheSize() const {
	return capacity;
}