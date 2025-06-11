#pragma once
#include <iostream>

template <typename U, typename V>
class MyPair {
public:
	MyPair(const U& u, const V& v);

	const U& getU() const;
	const V& getV() const;

private: 
	U u;
	V v;
};

template <typename U, typename V>
MyPair<U,V>::MyPair(const U& u, const V& v): u(u), v(v) {}

template <typename U, typename V>
const U& MyPair<U, V>::getU() const {
	return u;
}

template <typename U, typename V>
const V& MyPair<U, V>::getV() const {
	return v;
}

template <typename U, typename V>
bool operator==(const MyPair<U, V>& lhs, const MyPair<U, V>& rhs) {
	return lhs.getU() == rhs.getU() && lhs.getV() == rhs.getV();
}

template <typename U, typename V>
bool operator!=(const MyPair<U, V>& lhs, const MyPair<U, V>& rhs) {
	return !(lhs == rhs);
}

template <typename U, typename V>
bool operator<(const MyPair<U, V>& lhs, const MyPair<U, V>& rhs) {
	if (lhs.getU() < rhs.getU()) {
		return true;
	}
	
	if (lhs.getU() == rhs.getU()) {
		return lhs.getV() < rhs.getV();
	}
}