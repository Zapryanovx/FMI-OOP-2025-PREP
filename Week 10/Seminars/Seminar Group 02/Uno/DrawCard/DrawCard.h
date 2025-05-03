#pragma once
#include "UnoCard.h"
#include "ActionCard.h"
#include "NumberCard.h"

class DrawCard : public UnoCard
{
public:
	DrawCard(Color color, unsigned draw);

	void print() const override;

	bool isEqualTo(const UnoCard* other) const override;
	bool isEqualToNumber(const NumberCard* other) const override;
	bool isEqualToAction(const ActionCard* other) const override;
	bool isEqualToDraw(const DrawCard* other) const override;

	virtual UnoCard* clone() const override;

private:
	unsigned draw;

	void setDraw(unsigned draw);
};

