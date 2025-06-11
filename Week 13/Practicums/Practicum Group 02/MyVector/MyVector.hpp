#pragma once
#include <iostream>

template <typename T>
class MyVector {
public:
	MyVector();
	MyVector(size_t n);
	MyVector(size_t n, const T& elem);

	MyVector(const MyVector<T>& other);
	MyVector<T>& operator=(const MyVector<T>& other);

	MyVector(MyVector<T>&& other) noexcept;
	MyVector<T>& operator=(MyVector<T>&& other) noexcept;

	~MyVector();

	void push_back(const T& elem);
	void push_back(T&& elem);

	void pop_back();

	void insert(size_t idx, const T& elem);
	void insert(size_t idx, T&& elem);

	void erase(size_t idx);

	T& operator[](size_t idx);
	const T& operator[](size_t idx) const;

	void shrink_to_fit();

	void clear();

	const T& front() const;
	T& front();

	const T& back() const;
	T& back();

	bool empty() const;
	size_t getSize() const;
	size_t getCapacity() const;
	
private:
	T* arr;
	size_t size;
	size_t capacity;

	void resize(size_t newCap);

	void free();
	void copyFrom(const MyVector<T>& other);
	void moveFrom(MyVector<T>&& other);
};

template <typename T>
MyVector<T>::MyVector() {
	capacity = 8;
	size = 0;
	arr = new T[capacity]{};
}

template <typename T>
MyVector<T>::MyVector(size_t n) {
	capacity = n;
	size = n;
	arr = new T[capacity]{};
}

template <typename T>
MyVector<T>::MyVector(size_t n, const T& elem) {
	capacity = n;
	size = n;
	arr = new T[capacity]{};

	for (size_t i = 0; i < size; i++) {
		arr[i] = elem;
	}
}

template <typename T>
MyVector<T>::MyVector(const MyVector<T>& other) {
	copyFrom(other);
}

template <typename T>
MyVector<T>& MyVector<T>::operator=(const MyVector<T>& other) {
	if (this != &other) {
		free();
		copyFrom(other);
	}

	return *this;
}

template <typename T>
MyVector<T>::MyVector(MyVector<T>&& other) noexcept {
	moveFrom(std::move(other));
}

template <typename T>
MyVector<T>& MyVector<T>::operator=(MyVector<T>&& other) noexcept {
	if (this != &other) {
		free();
		moveFrom(std::move(other));
	}

	return *this;
}

template <typename T>
MyVector<T>::~MyVector() {
	free();
}

template <typename T>
void MyVector<T>::push_back(const T& elem) {
	if (size == capacity) {
		resize(capacity * 2);
	}

	arr[size++] = elem;
}

template <typename T>
void MyVector<T>::push_back(T&& elem) {
	if (size == capacity) {
		resize(capacity * 2);
	}

	arr[size++] = std::move(elem);
}

template <typename T>
void MyVector<T>::pop_back() {
	arr[size - 1].~T();
	size--;
}

template <typename T>
void MyVector<T>::insert(size_t idx, const T& elem) {
	if (idx > size) {
		throw std::out_of_range("invalid index");
	}

	if (size == capacity) {
		resize(capacity * 2);
	}

	for (size_t i = size; i > idx; i--) {
		arr[i] = arr[i - 1];
	}

	arr[idx] = elem;
	size++;
}

template <typename T>
void MyVector<T>::insert(size_t idx, T&& elem) {
	if (idx > size) {
		throw std::out_of_range("invalid index");
	}
	
	if (size == capacity) {
		resize(capacity * 2);
	}

	for (size_t i = size; i > idx; i--) {
		arr[i] = std::move(arr[i - 1]);
	}

	arr[idx] = std::move(elem);
	size++;
}

template <typename T>
T& MyVector<T>::operator[](size_t idx) {
	if (idx >= size) {
		throw std::out_of_range("invalid index");
	}

	return arr[idx];
}

template <typename T>
const T& MyVector<T>::operator[](size_t idx) const {
	if (idx >= size) {
		throw std::out_of_range("invalid index");
	}

	return arr[idx];
}

template <typename T>
void MyVector<T>::clear() {
	for (size_t i = 0; i < size; i++) {
		arr[i].~T();
	}

	size = 0;
}

template <typename T>
void MyVector<T>::shrink_to_fit() {
	resize(size);
}

template <typename T>
void MyVector<T>::erase(size_t idx) {
	if (idx >= size) {
		throw std::out_of_range("invalid index");
	}

	arr[idx].~T();
	for (size_t i = idx; i < size - 1; i++) {
		arr[i] = arr[i + 1];
	}

	size--;
	arr[size].~T();
}

template <typename T>
const T& MyVector<T>::front() const {
	return arr[0];
}

template <typename T>
T& MyVector<T>::front() {
	return arr[0];
}

template <typename T>
const T& MyVector<T>::back() const {
	return arr[size - 1];
}

template <typename T>
T& MyVector<T>::back() {
	return arr[size - 1];
}

template <typename T>
bool MyVector<T>::empty() const {
	return size == 0;
}

template <typename T>
size_t MyVector<T>::getSize() const {
	return size;
}

template <typename T>
size_t MyVector<T>::getCapacity() const {
	return capacity;
}

template <typename T>
void MyVector<T>::resize(size_t newCap) {
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
void MyVector<T>::free() {
	delete[] arr;
	arr = nullptr;

	capacity = size = 0;
}

template <typename T>
void MyVector<T>::copyFrom(const MyVector<T>& other) {
	arr = new T[other.capacity]{};
	for (size_t i = 0; i < other.size; i++) {
		arr[i] = other[i];
	}

	size = other.size;
	capacity = other.capacity;
}

template <typename T>
void MyVector<T>::moveFrom(MyVector<T>&& other) {
	arr = other.arr;
	other.arr = nullptr;

	size = other.size;
	capacity = other.capacity;

	other.capacity = other.size = 0;
}