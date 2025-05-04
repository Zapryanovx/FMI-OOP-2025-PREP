#include "GroupTicket.h"

GroupTicket::GroupTicket(const MyString& name, double price) : Ticket(name, price * 0.8){}

void GroupTicket::print() const
{
	std::cout << "[Group Ticket] " << getName().c_str() << " " << "$" << getPrice() << std::endl;
}