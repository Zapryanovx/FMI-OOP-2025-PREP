	#pragma once
	#include <iostream>

	template <typename T>
	class PolymorphicContainer {
	public:

		PolymorphicContainer();

		PolymorphicContainer(const PolymorphicContainer<T>& other);
		PolymorphicContainer& operator=(const PolymorphicContainer<T>& other);

		PolymorphicContainer(PolymorphicContainer<T>&& other) noexcept;
		PolymorphicContainer& operator=(PolymorphicContainer<T>&& other) noexcept;

		~PolymorphicContainer();

		void push_back(T* el);
		void remove_at(size_t at);

		const T& operator[](size_t index) const;
		T& operator[](size_t index);

	private:
		T** arr;
		size_t size;
		size_t capacity;

		void resize(size_t newCap);

		void free();
		void copyFrom(const PolymorphicContainer<T>& other);
		void moveFrom(PolymorphicContainer<T>&& other);

	};

	template <typename T>
	PolymorphicContainer<T>::PolymorphicContainer() {
		capacity = 8;
		size = 0;
		arr = new T * [capacity] {};
	}

	template <typename T>
	PolymorphicContainer<T>::PolymorphicContainer(const PolymorphicContainer<T>& other) {
		copyFrom(other);
	}

	template <typename T>
	PolymorphicContainer<T>& PolymorphicContainer<T>::operator=(const PolymorphicContainer<T>& other) {
		if (this != &other) {
			free();
			copyFrom(other);
		}

		return *this;
	}

	template <typename T>
	PolymorphicContainer<T>::PolymorphicContainer(PolymorphicContainer<T>&& other) noexcept {
		moveFrom(std::move(other));
	}

	template <typename T>
	PolymorphicContainer<T>& PolymorphicContainer<T>::operator=(PolymorphicContainer<T>&& other) noexcept {
		if (this != &other) {
			free();
			moveFrom(std::move(other));
		}

		return *this;
	}

	template <typename T>
	PolymorphicContainer<T>::~PolymorphicContainer() {
		free();
	}

	template <typename T>
	void PolymorphicContainer<T>::push_back(T* el) {
		if (size == capacity) {
			resize(capacity * 2);
		}

		arr[size++] = el;
	}

	template <typename T>
	void PolymorphicContainer<T>::remove_at(size_t at) {
		if (at >= size) {
			throw std::out_of_range("invalid index");
		}

		delete arr[at];
		arr[at] = nullptr;

		for (size_t i = at; i < size - 1; i++) {
			arr[i] = arr[i + 1];
		}

		arr[size - 1] = nullptr;
		size--;
	}

	template <typename T>
	const T& PolymorphicContainer<T>::operator[](size_t index) const {
		if (index >= size) {
			throw std::out_of_range("invalid index");
		}

		return *arr[index];
	}

	template <typename T>
	T& PolymorphicContainer<T>::operator[](size_t index) {
		if (index >= size) {
			throw std::out_of_range("invalid index");
		}

		return *arr[index];
	}

	template <typename T>
	void PolymorphicContainer<T>::resize(size_t newCap) {
	
		T** newArr = new T * [newCap] {};
	
		for (size_t i = 0; i < size; i++) {
			newArr[i] = arr[i];
		}
	
		delete[] arr;
		arr = newArr;
		newArr = nullptr;

		capacity = newCap;
	}

	template <typename T>
	void PolymorphicContainer<T>::free() {
		for (size_t i = 0; i < size; i++) {
			delete arr[i];
		}

		delete[] arr;
		arr = nullptr;
		capacity = size = 0;
	}

	template <typename T>
	void PolymorphicContainer<T>::copyFrom(const PolymorphicContainer<T>& other) {
		arr = new T * [other.capacity] {};
		for (size_t i = 0; i < other.size; i++) {
			arr[i] = other[i]->clone();
		}

		this->size = other.size;
		this->capacity = other.capacity;
	}

	template <typename T>
	void PolymorphicContainer<T>::moveFrom(PolymorphicContainer<T>&& other) {
		arr = other.arr;
		other.arr = nullptr;

		size = other.size;
		capacity = other.capacity;

		other.capacity = other.size = 0;
	}