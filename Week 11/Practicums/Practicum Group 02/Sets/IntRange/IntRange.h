#pragma once
#include "IntSet.h"

class IntRange: public IntSet
{
public:
	IntRange(int start, int end);

	bool member(int x) const override;
	int get(int i) const override;

	bool isSubsetOf(const IntSet* s) const override;
	bool intersects(const IntSet* s) const override;

	void print() const override;

private:
	int start;
	int end;
};

