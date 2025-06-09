#pragma once
#include "Set.hpp"

template <typename T>
class Range: public Set<T> {
public:
	Range(const T& a, const T& b);

	bool member(const T& el) const override;
	Set<T>* clone() const override;

	void serialize(std::ostream& os) const override;
	void deserialize(std::istream& is) override;

private:
	T a;
	T b;
};

template <typename T>
Range<T>::Range(const T& a, const T& b): a(a), b(b){}

template <typename T>
bool Range<T>::member(const T& el) const {
	return a <= el && el <= b;
}

template <typename T>
Set<T>* Range<T>::clone() const {
	return new Range(*this);
}

template <typename T>
void Range<T>::serialize(std::ostream& os) const {
	os << "[Start]: " << a << " [End]: " << b << std::endl;
	os << "[Array]: " << std::endl;
	for (int i = a; i <= b; i++) {
		os << i;

		if (i != b) {
			os << ", ";
		}
	}

	std::cout << std::endl;
}

template <typename T>
void Range<T>::deserialize(std::istream& is) {
	is >> a;
	is >> b;
}