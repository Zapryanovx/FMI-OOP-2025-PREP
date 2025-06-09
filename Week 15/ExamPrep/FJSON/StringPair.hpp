#pragma once
#include <iostream>
#include <string>
#include "CustomPair.hpp"
#include "MyString.h"

template <typename K>
class StringPair : public CustomPair<K, MyString> {
public:
	
	StringPair(const K& key, const MyString& val);
	MyString generateFormat() const override;
	CustomPair<K, MyString>* clone() const override;
};

template <typename K>
StringPair<K>::StringPair(const K& key, const MyString& val) : CustomPair<K, MyString>(key, val){}

template <typename K>
CustomPair<K, MyString>* StringPair<K>::clone() const {
	return new StringPair(*this);
}

template <typename K>
MyString StringPair<K>::generateFormat() const {
	MyString res;
	res += "{";
	res += std::to_string(this->key).c_str();
	res += " : \"";
	res += this->value;
	res += "\"";
	res += "}";
	return res;
}
