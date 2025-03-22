#include "MultiSetLessThanThree.h"

MultiSetLessThanThree::MultiSetLessThanThree(size_t limit) : limit(limit - 1)
{
	bucketsCount = getNeededBuckets(limit);
	buckets = new uint8_t[bucketsCount]{};
}

MultiSetLessThanThree::MultiSetLessThanThree(const MultiSetLessThanThree& other)
{
	copyFrom(other);
}

MultiSetLessThanThree& MultiSetLessThanThree::operator=(const MultiSetLessThanThree& other)
{
	if (this != &other)
	{
		free();
		copyFrom(other);
	}

	return *this;
}

MultiSetLessThanThree::~MultiSetLessThanThree()
{
	free();
}

void MultiSetLessThanThree::addNum(unsigned n)
{
	if (n > limit)
	{
		return;
	}

	size_t count = countOf(n);
	if (count == CONSTANTS::UPPER_BOUND_APPS)
	{
		return;
	}

	setCount(n, count + 1);
}


void MultiSetLessThanThree::removeNum(unsigned n)
{
	if (n > limit)
	{
		return;
	}

	size_t count = countOf(n);
	if (count == CONSTANTS::LOWER_BOUND_APPS)
	{
		return;
	}

	setCount(n, count - 1);
}

size_t MultiSetLessThanThree::countOf(unsigned n) const
{
	if (n > limit)
	{
		return 0;
	}

	size_t bucket = getBucketOf(n);
	size_t pos = getPosOf(n);

	return (buckets[bucket] >> pos) & CONSTANTS::UPPER_BOUND_APPS;
}

void MultiSetLessThanThree::print() const
{
	for (size_t i = 0; i <= limit; i++)
	{
		size_t count = countOf(i);
		for (size_t j = 0; j < count; j++)
		{
			std::cout << i << " ";
		}
	}

	std::cout << std::endl;
}

MultiSetLessThanThree MultiSetLessThanThree::intersectWith(const MultiSetLessThanThree& other) const
{
	size_t intersectionLimit = std::min(limit + 1, other.limit + 1);
	MultiSetLessThanThree intersection(intersectionLimit);

	for (size_t i = 0; i < intersectionLimit; i++)
	{
		size_t count = std::min(countOf(i), other.countOf(i));
		intersection.setCount(i, count);
	}

	return intersection;
}

void MultiSetLessThanThree::setCount(unsigned n, size_t count)
{
	size_t bucket = getBucketOf(n);
	size_t pos = getPosOf(n);

	buckets[bucket] &= ~(CONSTANTS::UPPER_BOUND_APPS << pos);
	buckets[bucket] |= count << pos;
}

size_t MultiSetLessThanThree::getNeededBuckets(size_t limit) const
{
	size_t count = limit / CONSTANTS::NUMS_IN_BUCKETS;
	if (limit % CONSTANTS::NUMS_IN_BUCKETS != 0)
	{
		count++;
	}

	return count;
}

size_t MultiSetLessThanThree::getBucketOf(unsigned n) const
{
	return n / CONSTANTS::NUMS_IN_BUCKETS;
}

size_t MultiSetLessThanThree::getPosOf(unsigned n) const
{
	return n % CONSTANTS::NUMS_IN_BUCKETS * CONSTANTS::BITS_PER_NUM;
}

void MultiSetLessThanThree::copyFrom(const MultiSetLessThanThree& other)
{
	limit = other.limit;
	bucketsCount = other.bucketsCount;

	buckets = new uint8_t[bucketsCount]{};
	for (size_t i = 0; i < bucketsCount; i++)
	{
		buckets[i] = other.buckets[i];
	}
}

void MultiSetLessThanThree::free()
{
	delete[] buckets;
	buckets = nullptr;

	bucketsCount = limit = 0;
}