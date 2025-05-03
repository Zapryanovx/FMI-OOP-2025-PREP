#pragma once
#include "UnoCard.h"
#include "DrawCard.h"
#include "NumberCard.h"

class ActionCard: public UnoCard
{
public:
	ActionCard(Color color, Action action);
	
	void print() const override;

	bool isEqualTo(const UnoCard* other) const override;
	bool isEqualToNumber(const NumberCard* other) const override;
	bool isEqualToAction(const ActionCard* other) const override;
	bool isEqualToDraw(const DrawCard* other) const override;

	UnoCard* clone() const override;

private:
	Action action;
};

