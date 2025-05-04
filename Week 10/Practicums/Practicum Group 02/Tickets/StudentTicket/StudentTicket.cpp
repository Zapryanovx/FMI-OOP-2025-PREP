#include "StudentTicket.h"

StudentTicket::StudentTicket(const MyString& name, double price): Ticket(name, price /2){}

void StudentTicket::print() const
{
	std::cout << "[Student Ticket] " << getName().c_str() << " " << "$" << getPrice() << std::endl;
}