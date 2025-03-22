#include "Bitset.h"

Bitset::Bitset(size_t limit): limit(limit - 1)
{
	bucketsCount = getNeededBuckets(limit);
	buckets = new uint8_t[bucketsCount]{};
}

Bitset::Bitset(const Bitset& other)
{
	copyFrom(other);
}

Bitset& Bitset::operator=(const Bitset& other)
{
	if (this != &other)
	{
		free();
		copyFrom(other);
	}

	return *this;
}

Bitset::~Bitset()
{
	free();
}

void Bitset::addNum(unsigned n)
{
	if (n > limit)
	{
		return;
	}

	size_t bucket = getBucketOf(n);
	size_t pos = getPosOf(n);

	buckets[bucket] |= (1 << pos);
}

void Bitset::removeNum(unsigned n)
{
	if (n > limit)
	{
		return;
	}

	size_t bucket = getBucketOf(n);
	size_t pos = getPosOf(n);

	buckets[bucket] &= ~(1 << pos);
}

bool Bitset::contains(unsigned n) const
{
	if (n > limit)
	{
		return false;
	}

	size_t bucket = getBucketOf(n);
	size_t pos = getPosOf(n);

	return buckets[bucket] & (1 << pos);
}

void Bitset::printSet() const
{
	for (size_t i = 0; i <= limit; i++)
	{
		if (contains(i))
		{
			std::cout << i << " ";
		}
	}
}

Bitset Bitset::unionWith(const Bitset& other) const
{
	size_t resLimit = std::max(limit, other.limit) + 1;
	Bitset res(resLimit);

	for (size_t i = 0; i < res.bucketsCount; i++)
	{
		uint8_t lhs = (i < bucketsCount) ? buckets[i] : 0;
		uint8_t rhs = (i < other.bucketsCount) ? other.buckets[i] : 0;
		
		res.buckets[i] = lhs | rhs;
	}
	
	return res;
}

Bitset Bitset::intersectWith(const Bitset& other) const
{
	size_t resLimit = std::min(limit, other.limit) + 1;
	Bitset res(resLimit);

	for (size_t i = 0; i < res.bucketsCount; i++)
	{
		res.buckets[i] = (buckets[i] & other.buckets[i]);
	}

	return res;
}

void Bitset::copyFrom(const Bitset& other)
{
	bucketsCount = other.bucketsCount;
	limit = other.limit;

	buckets = new uint8_t[bucketsCount]{};
	for (size_t i = 0; i < bucketsCount; i++)
	{
		buckets[i] = other.buckets[i];
	}
}

void Bitset::free()
{
	delete[] buckets;
	buckets = nullptr;

	bucketsCount = limit = 0;
}

size_t Bitset::getNeededBuckets(size_t limit) const
{
	size_t count = limit / 8;
	if (limit % CONSTANTS::NUMS_IN_BUCKETS != 0)
	{
		count++;
	}

	return count;
}

size_t Bitset::getBucketOf(unsigned n) const
{
	return n / CONSTANTS::NUMS_IN_BUCKETS;
}

size_t Bitset::getPosOf(unsigned n) const
{
	return n % CONSTANTS::NUMS_IN_BUCKETS;
}
