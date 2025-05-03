#pragma once
#include <iostream>

enum class Color
{
	Red,
	Green,
	Blue,
	Yellow,
	None
};

enum class Type
{
	Number,
	Action,
	Draw,
};

enum class Action
{
	Skip,
	Reverse,
	None,
};

namespace Helpers
{
	static const char* convertActionToStr(Action action)
	{
		switch (action)
		{
		case Action::Skip:
			return "Skip";
		case Action::Reverse:
			return "Reverse";
		default:
			return "None";
		}
	}

	static const char* convertColorToStr(Color color)
	{
		switch (color)
		{
		case Color::Red:
			return "Red";
		case Color::Green:
			return "Green";
		case Color::Blue:
			return "Blue";
		case Color::Yellow:
			return "Yellow";
		default:
			return "None";
		}
	}
}

class NumberCard;
class ActionCard;
class DrawCard;

class UnoCard
{
public:
	UnoCard(Color color, Type type);
	~UnoCard() = default;
	
	Color getColor() const;
	Type getType() const;

	virtual void print() const = 0;

	virtual bool isEqualTo(const UnoCard* other) const = 0;
	virtual bool isEqualToNumber(const NumberCard* other) const = 0;
	virtual bool isEqualToAction(const ActionCard* other) const = 0;
	virtual bool isEqualToDraw(const DrawCard* other) const = 0;

	virtual UnoCard* clone() const = 0;

private:
	Color color;
	Type type;
};

