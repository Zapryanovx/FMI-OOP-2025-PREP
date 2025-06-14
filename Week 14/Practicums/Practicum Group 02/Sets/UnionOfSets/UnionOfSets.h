#pragma once
#include "SetOperation.h"

class UnionOfSets : public SetOperation
{
public:
	UnionOfSets(const Set* const* sets, size_t size);
	UnionOfSets(Set**&& sets, size_t size);

	bool accepts(unsigned int el) const override;
	Set* clone() const override;

private:
	void copySets(const Set* const* sets, size_t size);
	void moveSets(Set**&& sets, size_t size);
};

