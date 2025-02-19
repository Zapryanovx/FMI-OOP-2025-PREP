#include <iostream>

namespace CONSTANTS
{
	constexpr int NAME_SIZE = 31;
}

enum class Drink
{
	Whiskey,
	Vodka,
	Cola,
	Fanta,
	Water,
	Wine,
	Rum,
	Juice,
};

struct Client
{
  char name[CONSTANTS::NAME_SIZE + 1]{};
  uint8_t likedDrinks;
};


bool isLike(const Client& client, Drink drink)
{
	return (client.likedDrinks >> int(drink)) & 1;
}

void makeLike(Client& client, Drink drink)
{
	client.likedDrinks |= (1 << int(drink));
}

void makeNotLike(Client& client, Drink drink)
{
	client.likedDrinks &= ~(1 << int(drink));
}

int main()
{
	Client client;

	makeLike(client, Drink::Fanta);
	std::cout << isLike(client, Drink::Fanta) << std::endl;

	makeNotLike(client, Drink::Fanta);
	std::cout << isLike(client, Drink::Fanta) << std::endl;

	return 0;
}

