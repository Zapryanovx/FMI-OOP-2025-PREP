#pragma once
#include "PriceTag.hpp"

namespace Constants {
	constexpr size_t MAX_SIZE_TAGS = 200;
}

template <typename T>
class PriceCatalog {
public:
	PriceCatalog(const PriceTag<T>* tag, size_t size);

	PriceCatalog<T>& operator+=(const PriceTag<T>& pt);

	template <typename V>
	friend std::ostream& operator<<(std::ostream& os, const PriceCatalog<V>& obj);

private:
	PriceTag<T> tags[Constants::MAX_SIZE_TAGS]{};
	size_t size = 0;

	void initTags(const PriceTag<T>* tags, size_t size);
};

template <typename T>
PriceCatalog<T>::PriceCatalog(const PriceTag<T>* tags, size_t size) {
	initTags(tags, size);
}


template <typename T>
void PriceCatalog<T>::initTags(const PriceTag<T>* tags, size_t size) {
	
	if (size > Constants::MAX_SIZE_TAGS) {
		throw std::invalid_argument("size must be <= 200");
	}

	for (size_t i = 0; i < size; i++) {
		*this += tags[i];
	}

}

template<typename T>
PriceCatalog<T>& PriceCatalog<T>::operator+=(const PriceTag<T>& tag) {
	if (this->size == Constants::MAX_SIZE_TAGS) {
		throw std::out_of_range("catalog limit exceeded");
	}

	this->tags[size++] = tag;
}

template <typename T>
std::ostream& operator<<(std::ostream& os, const PriceCatalog<T>& obj) {
	os << "[Catalog]" << std::endl;
	for (size_t i = 0; i < obj.size; i++) {
		os << obj.tags[i];
	}

	return os;
}