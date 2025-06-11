#pragma once
#include <iostream>

template <typename T>
class Sorted {
public:
	Sorted();

	Sorted(const Sorted<T>& other);
	Sorted<T>& operator=(const Sorted<T>& other);

	Sorted(Sorted<T>&& other) noexcept;
	Sorted<T>& operator=(Sorted<T>&& other) noexcept;

	~Sorted();

	void add(const T& elem);
	void remove(const T& elem);
	void print() const;

private:
	T* arr;
	size_t size;
	size_t capacity;

	void resize(size_t newCap);
	size_t lower_bound(const T& obj) const;
	void shiftRight(size_t from);
	void shiftLeft(size_t from);

	void free();
	void copyFrom(const Sorted<T>& other);
	void moveFrom(Sorted<T>&& other);
};

template <typename T> 
Sorted<T>::Sorted() {
	capacity = 8;
	size = 0;
	arr = new T[capacity]{};
}

template <typename T>
Sorted<T>::Sorted(const Sorted<T>& other) {
	copyFrom(other);
}

template <typename T>
Sorted<T>& Sorted<T>::operator=(const Sorted<T>& other) {
	if (this != &other) {
		free();
		copyFrom(other);
	}

	return *this;
}

template <typename T>
Sorted<T>::Sorted(Sorted<T>&& other) noexcept {
	moveFrom(std::move(other));
}

template <typename T>
Sorted<T>& Sorted<T>::operator=(Sorted<T>&& other) noexcept {
	if (this != &other) {
		free();
		moveFrom(std::move(other));
	}

	return *this;
}

template <typename T>
Sorted<T>::~Sorted() {
	free();
}

template <typename T>
void Sorted<T>::add(const T& elem) {
	if (size == capacity) {
		resize(capacity * 2);
	}
	
	size_t at = lower_bound(elem);
	shiftRight(at);
	arr[at] = elem;
	size++;
}

template <typename T>
void Sorted<T>::remove(const T& elem) {
	size_t at = lower_bound(elem);

	if (at == size) {
		throw std::invalid_argument("el not found");
	}

	arr[at].~T();
	shiftLeft(at);
	size--;
}

template <typename T>
void Sorted<T>::print() const {
	for (size_t i = 0; i < size; i++) {
		std::cout << arr[i];

		if (i != size - 1) {
			std::cout << " | ";
		}
	}

	std::cout << std::endl;
}

template <typename T>
void Sorted<T>::resize(size_t newCap) {
	T* newArr = new T[newCap]{};
	for (size_t i = 0; i < size; i++) {
		newArr[i] = arr[i];
	}

	delete[] arr;
	arr = newArr;
	newArr = nullptr;

	capacity = newCap;
}

template <typename T>
size_t Sorted<T>::lower_bound(const T& obj) const {
	for (size_t i = 0; i < size; i++) {
		if (arr[i] >= obj) {
			return i;
		}
	}

	return size;
}

template <typename T>
void Sorted<T>::shiftRight(size_t from) {
	for (size_t i = size; i > from; i--) {
		arr[i] = arr[i - 1];
	}
}

template <typename T>
void Sorted<T>::shiftLeft(size_t from) {
	for (size_t i = from; i < size - 1; i++) {
		arr[i] = arr[i + 1];
	}
}


template <typename T>
void Sorted<T>::free() {
	delete[] arr;
	arr = nullptr;
	
	capacity = size = 0;
}

template <typename T>
void Sorted<T>::copyFrom(const Sorted<T>& other) {
	arr = new T[other.capacity]{};
	for (size_t i = 0; i < other.size; i++) {
		arr[i] = other.arr[i];
	}

	size = other.size;
	capacity = other.capacity;
}

template <typename T>
void Sorted<T>::moveFrom(Sorted<T>&& other) {
	arr = other.arr;
	other.arr = nullptr;

	size = other.size;
	other.size = 0;

	capacity = other.capacity;
	other.capacity = 0;
}