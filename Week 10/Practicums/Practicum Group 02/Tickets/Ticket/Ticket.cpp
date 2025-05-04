#include "Ticket.h"

Ticket::Ticket(const MyString& name, double price) : name(name), price(price) {}

const MyString& Ticket::getName() const
{
	return name;
}

double Ticket::getPrice() const
{
	return price;
}