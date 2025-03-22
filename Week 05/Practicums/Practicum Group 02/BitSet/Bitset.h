#pragma once
#include <iostream>

namespace CONSTANTS
{
	constexpr size_t NUMS_IN_BUCKETS = 8;
}

class Bitset
{
public:
	Bitset(size_t limit);
	Bitset(const Bitset& other);
	Bitset& operator=(const Bitset& other);
	~Bitset();
	
	void addNum(unsigned n);
	void removeNum(unsigned n);
	bool contains(unsigned n) const;
	void printSet() const;

	Bitset unionWith(const Bitset& other) const;
	Bitset intersectWith(const Bitset& other) const;

private:

	void copyFrom(const Bitset& other);
	void free();

	size_t getNeededBuckets(size_t limit) const;
	size_t getBucketOf(unsigned n) const;
	size_t getPosOf(unsigned n) const;

	uint8_t* buckets;
	size_t bucketsCount;
	size_t limit;
};



