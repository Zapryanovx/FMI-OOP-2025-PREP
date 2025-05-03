#include "UnoCard.h"

UnoCard::UnoCard(Color color, Type type): color(color), type(type) {}

Color UnoCard::getColor() const
{
	return color;
}

Type UnoCard::getType() const
{
	return type;
}