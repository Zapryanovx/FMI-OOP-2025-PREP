#pragma once
#include "Set.hpp"

template <typename T>
class Container : public Set<T> {
public:
	Container();

	Container(const Container<T>& other);
	Container<T>& operator=(const Container<T>& other);

	Container(Container<T>&& other) noexcept;
	Container<T>& operator=(Container<T>&& other) noexcept;

	~Container();

	void serialize(std::ostream& os) const override;
	void deserialize(std::istream& is) override;

	void add(const T& element);

	const T* getArr() const;
	size_t getSize() const;

	bool contains(const T& element) const;

	bool member(const T& element) const override;
	Set<T>* clone() const override;

private:
	T* arr;
	size_t size;
	size_t capacity;

	void resize(size_t newCap);

	void free();
	void copyFrom(const Container& other);
	void moveFrom(Container&& other);
};

template <typename T>
void Container<T>::add(const T& element) {
	if (size == capacity) {
		resize(capacity * 2);
	}

	if (!contains(element)) {
		arr[size++] = element;
	}
}

template <typename T>
Container<T>::Container() {
	capacity = 8;
	size = 0;
	arr = new T[capacity]{};
}

template <typename T>
Container<T>::Container(const Container<T>& other): Set<T>(other) {
	copyFrom(other);
}

template <typename T>
Container<T>& Container<T>::operator=(const Container<T>& other) {
	if (this != &other) {
		Set<T>::operator=(other);
		free();
		copyFrom(other);
	}

	return *this;
}

template <typename T>
Container<T>::Container(Container<T>&& other) noexcept: Set<T>(std::move(other)) {
	moveFrom(std::move(other));
}

template <typename T>
Container<T>& Container<T>::operator=(Container<T>&& other) noexcept {
	if (this != &other) {
		Set<T>::operator=(other);
		free();
		moveFrom(std::move(other));
	}

	return *this;
}

template <typename T>
Container<T>::~Container() {
	delete[] arr;
	arr = nullptr;

	capacity = size = 0;
}


template <typename T>
size_t Container<T>::getSize() const {
	return size;
}

template <typename T>
const T* Container<T>::getArr() const {
	return arr;
}

template <typename T>
bool Container<T>::contains(const T& element) const { 
	for (size_t i = 0; i < size; i++) {
		if (arr[i] == element) {
			return true;
		}
	}

	return false;
}

template <typename T>
bool Container<T>::member(const T& element) const {
	return contains(element);
}

template <typename T>
Set<T>* Container<T>::clone() const {
	return new Container(*this);
}

template <typename T>
Container<T> operator+(const Container<T>& lhs, const Container<T>& rhs) {
	
	Container<T> res;

	for (size_t i = 0; i < lhs.getSize(); i++) {
		if (!res.contains(lhs.getArr()[i])) {
			res.add(lhs.getArr()[i]);
		}
	}

	for (size_t i = 0; i < rhs.getSize(); i++) {
		if (!res.contains(rhs.getArr()[i])) {
			res.add(lhs.getArr()[i]);
		}
	}

	return res;
}

template <typename T>
void Container<T>::resize(size_t newCap) {
	T* newArr = new T[newCap]{};
	for (size_t i = 0; i < size; i++) {
		newArr[i] = arr[i];
	}

	delete[] arr;
	arr = newArr;
	
	capacity = newCap;
}

template <typename T>
void Container<T>::free() {
	delete[] arr;
	arr = nullptr;

	capacity = size = 0;
}

template <typename T>
void Container<T>::copyFrom(const Container<T>& other) {
	arr = new T[other.capacity]{};
	for (size_t i = 0; i < other.size; i++) {
		arr[i] = other.arr[i];
	}

	size = other.size;
	capacity = other.capacity;
}

template <typename T>
void Container<T>::moveFrom(Container<T>&& other) {
	arr = other.arr;
	other.arr = nullptr;

	size = other.size;
	capacity = other.capacity;
	
	other.capacity = other.size = 0;
}

template <typename T>
void Container<T>::serialize(std::ostream& os) const {
	os << "[Size]: " << size << std::endl;
	os << "[Array]: " << std::endl;

	for (int i = 0; i < size; i++)
	{
		os << arr[i];
		
		if (i != size - 1) {
			os << ", ";
		}
	}

	std::cout << std::endl;
}

template <typename T>
void Container<T>::deserialize(std::istream& is) {
	is.ignore();
	is >> size;
	is.ignore();
	is.ignore();

	capacity = size;
	
	delete[] arr;
	arr = new T[capacity];

	for (int i = 0; i < size; i++)
	{
		is >> arr[i];
	}

}