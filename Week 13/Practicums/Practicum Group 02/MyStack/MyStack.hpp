#pragma once
#include <iostream>

template <typename T>
class MyStack {
public:
	MyStack();

	MyStack(const MyStack<T>& other);
	MyStack<T>& operator=(const MyStack<T>& other);

	MyStack(MyStack<T>&& other) noexcept;
	MyStack<T>& operator=(MyStack<T>&& other) noexcept;

	~MyStack();

	void push(const T& elem);
	void push(T&& elem);
	void pop();

	const T& top() const;
	bool empty() const;
	size_t getSize() const;

private:
	T* arr;
	size_t size;
	size_t capacity;

	void resize(size_t newCap);

	void free();
	void copyFrom(const MyStack<T>& other);
	void moveFrom(MyStack<T>&& other);
};

template <typename T>
MyStack<T>::MyStack() {
	capacity = 8;
	size = 0;
	arr = new T[capacity]{};
}

template <typename T>
MyStack<T>::MyStack(const MyStack<T>& other) {
	copyFrom(other);
}

template <typename T>
MyStack<T>& MyStack<T>::operator=(const MyStack<T>& other) {
	if (this != &other) {
		free();
		copyFrom(other);
	}

	return *this;
}

template <typename T>
MyStack<T>::MyStack(MyStack<T>&& other) noexcept {
	moveFrom(std::move(other));
}

template <typename T>
MyStack<T>& MyStack<T>::operator=(MyStack<T>&& other) noexcept {
	if (this != &other) {
		free();
		moveFrom(std::move(other));
	}

	return *this;
}

template <typename T>
MyStack<T>::~MyStack() {
	free();
}

template <typename T>
void MyStack<T>::push(const T& elem) {
	if (size == capacity) {
		resize(capacity * 2);
	}

	arr[size++] = elem;
}

template <typename T>
void MyStack<T>::push(T&& elem) {
	if (size == capacity) {
		resize(capacity * 2);
	}

	arr[size++] = std::move(elem);
}

template <typename T>
void MyStack<T>::pop() {
	size--;
	arr[size].~T();
}

template <typename T>
const T& MyStack<T>::top() const {
	return arr[size - 1];
}

template <typename T>
bool MyStack<T>::empty() const {
	return size == 0;
}

template <typename T>
size_t MyStack<T>::getSize() const {
	return size;
}

template <typename T>
void MyStack<T>::resize(size_t newCap) {
	T* newArr = new T[newCap]{};
	for (size_t i = 0; i < size; i++) {
		newArr[i] = arr[i];
	}

	capacity = newCap;
}

template <typename T>
void MyStack<T>::free() {
	delete[] arr;
	arr = nullptr;

	capacity = size = 0;
}

template <typename T>
void MyStack<T>::copyFrom(const MyStack<T>& other) {
	arr = new T[other.capacity]{};

	for (size_t i = 0; i < other.size; i++) {
		arr[i] = other.arr[i];
	}

	size = other.size;
	capacity = other.capacity;
}

template <typename T>
void MyStack<T>::moveFrom(MyStack<T>&& other) {
	arr = other.arr;
	other.arr = nullptr;

	size = other.size;
	other.size = 0;

	capacity = other.capacity;
	other.capacity = 0;
}