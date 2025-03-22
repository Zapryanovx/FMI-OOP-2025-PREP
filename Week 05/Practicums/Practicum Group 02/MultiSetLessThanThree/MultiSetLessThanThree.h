#pragma once
#include <iostream>

namespace CONSTANTS
{
	constexpr size_t NUMS_IN_BUCKETS = 4;
	constexpr size_t BITS_PER_NUM = 2;
	constexpr size_t UPPER_BOUND_APPS = 3;
	constexpr size_t LOWER_BOUND_APPS = 0;

}

class MultiSetLessThanThree
{
public:
	MultiSetLessThanThree(size_t limit);
	MultiSetLessThanThree(const MultiSetLessThanThree& other);
	MultiSetLessThanThree& operator=(const MultiSetLessThanThree& other);
	~MultiSetLessThanThree();

	void addNum(unsigned n);
	void removeNum(unsigned n);
	size_t countOf(unsigned n) const;
	void print() const;
	MultiSetLessThanThree intersectWith(const MultiSetLessThanThree& other) const;

private:
	void copyFrom(const MultiSetLessThanThree& other);
	void free();

	void setCount(unsigned n, size_t count);

	size_t getNeededBuckets(size_t limit) const;
	size_t getBucketOf(unsigned n) const;
	size_t getPosOf(unsigned n) const;
	
	uint8_t* buckets;
	size_t bucketsCount;
	size_t limit;

};

