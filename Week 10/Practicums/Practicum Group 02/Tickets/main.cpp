#include "Ticket.h"
#include "GroupTicket.h"
#include "StudentTicket.h"

int main()
{

	StudentTicket st("st1", 1);
	GroupTicket gt("gt1", 2);

	st.print();
	gt.print();

	return 0;

}