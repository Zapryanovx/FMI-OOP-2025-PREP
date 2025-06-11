#pragma once
#include <iostream>

template <typename T>
class PriceTag {
public:

	PriceTag();
	PriceTag(const T& product, double price);

	double getPrice() const;
	const T& getProduct() const;

	void discount(int percent);

	template <typename V>
	friend std::istream& operator>>(std::istream& is, PriceTag<V>& obj);

	template <typename V>
	friend std::ostream& operator<<(std::ostream& os, const PriceTag<V>& obj);

private:
	T product;
	double price;
};

template <typename T>
PriceTag<T>::PriceTag(): PriceTag(T(), 0.0) {}

template <typename T>
PriceTag<T>::PriceTag(const T& product, double price): product(product), price(price) {}

template <typename T>
double PriceTag<T>::getPrice() const {
	return price;
}

template <typename T>
const T& PriceTag<T>::getProduct() const {
	return product;
}

template <typename T>
void PriceTag<T>::discount(int percent) {
	price = price * (1.00 - percent / 100.0);
}

template <typename T>
std::istream& operator>>(std::istream& is, PriceTag<T>& pt) {
	is >> pt.product;
	is >> pt.price; 
	return is;
}

template <typename T>
std::ostream& operator<<(std::ostream& os, const PriceTag<T>& pt) {
	os << "--[Price Tag]" << std::endl;
	os << "----[Product] " << pt.product << std::endl;
	os << "----[Price] " << pt.price << std::endl;
	return os;
}



