#pragma once
#include "MyString.h"

class Ticket
{
public:
	Ticket(const MyString& name, double price);

	const MyString& getName() const;
	double getPrice() const;
	
private: 
	MyString name;
	double price;
};

