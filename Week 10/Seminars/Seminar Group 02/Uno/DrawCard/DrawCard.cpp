#include "DrawCard.h"

DrawCard::DrawCard(Color color, unsigned draw) : UnoCard(color, Type::Draw)
{
	setDraw(draw);
}

void DrawCard::print() const
{
	std::cout << "[Draw Card] " << draw << " Color: " << Helpers::convertColorToStr(getColor()) << std::endl;
}

void DrawCard::setDraw(unsigned draw)
{
	if (draw < 4 || draw > 6)
	{
		throw std::invalid_argument("invalid draw count");
	}

	this->draw = draw;
}

UnoCard* DrawCard::clone() const
{
	UnoCard* cpy = new DrawCard(*this);
	return cpy;
}

bool DrawCard::isEqualTo(const UnoCard* other) const
{
	return other->isEqualToDraw(this);
}

bool DrawCard::isEqualToNumber(const NumberCard* other) const
{
	return this->getColor() == other->getColor();
}

bool DrawCard::isEqualToAction(const ActionCard* other) const
{
	return this->getColor() == other->getColor();
}

bool DrawCard::isEqualToDraw(const DrawCard* other) const
{
	return this->getColor() == other->getColor();
}