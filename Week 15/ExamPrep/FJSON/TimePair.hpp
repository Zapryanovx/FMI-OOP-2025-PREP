#include "CustomPair.hpp"
#include "Time.h"

template <typename K>
class TimePair: public CustomPair<K, Time> {
public:
	TimePair(const K& key, const Time& val);
	MyString generateFormat() const override;
	CustomPair<K, Time>* clone() const override;

};

template <typename K>
TimePair<K>::TimePair(const K& key, const Time& val) : CustomPair<K, Time>(key, val) {}

template <typename K>
CustomPair<K, Time>* TimePair<K>::clone() const {
	return new TimePair(*this);
}

template<typename K>
MyString TimePair<K>::generateFormat() const {
	MyString res;
	res += "{";
	res += std::to_string(this->key).c_str();
	res += ", ";
	res += this->value.generateFormat();
	res += "}";
	return res;
}