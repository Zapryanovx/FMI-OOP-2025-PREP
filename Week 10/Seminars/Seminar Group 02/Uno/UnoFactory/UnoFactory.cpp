#include "UnoCard.h"
#include "NumberCard.h"
#include "DrawCard.h"
#include "ActionCard.h"

UnoCard* unoFactory()
{
	Type type = Type(std::rand() % 3);
	Color color = Color(std::rand() % 4);

	if (type == Type::Number)
	{
		unsigned number = std::rand() % 10;
		return new NumberCard(color, number);
	}

	else if (type == Type::Action)
	{
		Action action = Action(std::rand() % 3);
		return new ActionCard(color, action);
	}

	unsigned draw = 4 + (std::rand() % 3);
	return new DrawCard(color, draw);
}