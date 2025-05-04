#pragma once
#include "IntSet.h"

class ArraySet: public IntSet
{
public:
	ArraySet(unsigned n);

	ArraySet(const ArraySet& other);
	ArraySet& operator=(const ArraySet& other);

	ArraySet(ArraySet&& other) noexcept;
	ArraySet& operator=(ArraySet&& other) noexcept;

	~ArraySet();

	bool insert(int x);
	bool remove(int x);

	bool member(int x) const override;
	int get(int i) const override;

	bool isSubsetOf(const IntSet* s) const override;
	bool intersects(const IntSet* s) const override;

	void print() const override;

private:
	int* nums;
	size_t size;
	size_t capacity;

	void copyFrom(const ArraySet& other);
	void moveFrom(ArraySet&& other);
	void free();

};

