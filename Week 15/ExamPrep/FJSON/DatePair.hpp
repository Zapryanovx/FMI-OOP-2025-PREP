#include "CustomPair.hpp"
#include "Date.h"

template <typename K>
class DatePair : public CustomPair<K, Date> {
public:
	DatePair(const K& key, const Date& val);
	MyString generateFormat() const override;
	CustomPair<K, Date>* clone() const override;

};

template <typename K>
DatePair<K>::DatePair(const K& key, const Date& val) : CustomPair<K, Date>(key, val) {}

template <typename K>
CustomPair<K, Date>* DatePair<K>::clone() const {
	return new DatePair(*this);
}

template<typename K>
MyString DatePair<K>::generateFormat() const {
	MyString res;
	res += "{";
	res += std::to_string(this->key).c_str();
	res += " : ";
	res += this->value.generateFormat();  
	res += "}";
	return res;
}