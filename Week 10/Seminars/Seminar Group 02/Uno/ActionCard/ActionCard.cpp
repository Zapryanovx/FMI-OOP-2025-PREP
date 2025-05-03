#include "ActionCard.h"

ActionCard::ActionCard(Color color, Action action) : UnoCard(color, Type::Action), action(action) {};

void ActionCard::print() const
{
	std::cout << "[Action Card] " << Helpers::convertActionToStr(action) << " Color: " << Helpers::convertColorToStr(getColor()) << std::endl;
}

UnoCard* ActionCard::clone() const
{
	UnoCard* cpy = new ActionCard(*this);
	return cpy;
}

bool ActionCard::isEqualTo(const UnoCard* other) const
{
	return other->isEqualToAction(this);
}

bool ActionCard::isEqualToNumber(const NumberCard* other) const
{
	return this->getColor() == other->getColor();
}

bool ActionCard::isEqualToAction(const ActionCard* other) const
{
	return this->getColor() == other->getColor();
}

bool ActionCard::isEqualToDraw(const DrawCard* other) const
{
	return this->getColor() == other->getColor();
}