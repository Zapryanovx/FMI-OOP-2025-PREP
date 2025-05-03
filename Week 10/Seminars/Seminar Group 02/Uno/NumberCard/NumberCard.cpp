#include "NumberCard.h"

NumberCard::NumberCard(Color color, unsigned number) : UnoCard(color, Type::Number)
{
	setNumber(number);
}

unsigned NumberCard::getNumber() const
{
	return number;
}

void NumberCard::setNumber(unsigned number)
{
	if (number > 9)
	{
		throw std::invalid_argument("invalid card number");
	}

	this->number = number;
}

void NumberCard::print() const
{
	std::cout << "[Number Card] " << number << " Color: " << Helpers::convertColorToStr(getColor()) << std::endl;
}

UnoCard* NumberCard::clone() const
{
	UnoCard* cpy = new NumberCard(*this);
	return cpy;
}

bool NumberCard::isEqualTo(const UnoCard* other) const
{
	return other->isEqualToNumber(this);
}

bool NumberCard::isEqualToNumber(const NumberCard* other) const
{
	return this->getColor() == other->getColor() || this->getNumber() == other->getNumber();
}

bool NumberCard::isEqualToAction(const ActionCard* other) const
{
	return this->getColor() == other->getColor();
}

bool NumberCard::isEqualToDraw(const DrawCard* other) const
{
	return this->getColor() == other->getColor();
}