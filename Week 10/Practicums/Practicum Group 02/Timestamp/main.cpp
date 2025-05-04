#include "Ticket.h"
#include "Timestamp.h"
#include "TimestampWithDescription.h"


int main()
{

	TimestampWithDescription twd1(321, "asdwq");
	std::cout << twd1 << std::endl;

	std::cout << twd1.getDecs() << std::endl;
	std::cout << twd1.getSeconds() << std::endl;

	twd1 += 1;
	std::cout << twd1 << std::endl;


	return 0;

}