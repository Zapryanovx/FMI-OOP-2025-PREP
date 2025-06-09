#pragma once
#include <iostream>
#include "MyString.h"

template <typename K, typename V>
class CustomPair {
public:
	CustomPair(const K& key, const V& value);	

	virtual MyString generateFormat() const = 0;
	virtual CustomPair<K, V>* clone() const = 0;

	virtual ~CustomPair() = default;

protected:
	K key;
	V value;
};

template <typename K, typename V>
CustomPair<K,V>::CustomPair(const K& key, const V& value): key(key), value(value){}