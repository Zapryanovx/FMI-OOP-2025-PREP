#include "CustomPair.hpp"
#include "DateTime.h"

template <typename K>
class DateTimePair : public CustomPair<K, DateTime> {
public:
	DateTimePair(const K& key, const DateTime& val);
	MyString generateFormat() const override;
	CustomPair<K, DateTime>* clone() const override;

};

template <typename K>
DateTimePair<K>::DateTimePair(const K& key, const DateTime& val): CustomPair<K, DateTime>(key, val) {}

template <typename K>
CustomPair<K, DateTime>* DateTimePair<K>::clone() const {
	return new DateTimePair(*this);
}

template<typename K>
MyString DateTimePair<K>::generateFormat() const {
	MyString res;
	res += "{";
	res += std::to_string(this->key).c_str();
	res += " : ";
	res += this->value.generateFormat();
	res += "}";
	return res;
}