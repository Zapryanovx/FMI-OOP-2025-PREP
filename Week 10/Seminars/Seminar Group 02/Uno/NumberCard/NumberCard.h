#pragma once
#include "UnoCard.h"
#include "ActionCard.h"
#include "DrawCard.h"

class NumberCard: public UnoCard
{
public:
	NumberCard(Color color, unsigned number);

	unsigned getNumber() const;

	void print() const override;

	bool isEqualTo(const UnoCard* other) const override;
	bool isEqualToNumber(const NumberCard* other) const override;
	bool isEqualToAction(const ActionCard* other) const override;
	bool isEqualToDraw(const DrawCard* other) const override;

	virtual UnoCard* clone() const;

private:
	unsigned number;

	void setNumber(unsigned number);
};

