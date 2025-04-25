#include "ComputerStore.h"
#include "ConsultantUtils.h"

int main()
{
	Computer c1("Asus 2011", "i5", 3060, 3, 2, 1800, 1300, 1);
	Computer c2("Lenovo 2014", "NVIDIA", 3080, 3, 3, 1976, 2000, 1);
	Computer c3("Lenovo 2010", "i7", 3016, 3, 3, 1000, 978, 1);
	Computer c4("Acer", "RTX", 14, 3080, 3, 2000, 3000, 1);

	ComputerStore store("Gotinite");
	store.add(c1);
	store.add(c1);
	store.add(c1);
	store.add(c1);
	store.add(c2);
	store.add(c2);
	store.add(c3);
	store.add(c4);
	store.printAll();

	store.buy("Asus 2011", 5000);
	store.buy("Lenovo 2010", 5000);
	store.printAll();

	return 0;
}