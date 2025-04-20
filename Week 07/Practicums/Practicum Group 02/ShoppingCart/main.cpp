#include "ShoppingCart.h"

int main()
{

	Item item1("Milk", Status::AVAILABLE, 2);
	Item item2("Eggs", Status::AVAILABLE, 3);
	Item item3("Cola", Status::AVAILABLE, 1.50);
	Item item4("Bread", Status::AVAILABLE, 3.60);
	Item item5("Protein ice cream", Status::AVAILABLE, 4.75);

	ShoppingCart cart;
	cart.addItem(item1);
	cart.addItem(item2);
	cart.addItem(item3);
	cart.addItem(item4);
	cart.addItem(item5);
	cart.print();

	std::cout << cart.exists("Cola") << std::endl;
	std::cout << cart.getPriceOf("Eggs") << std::endl;
	std::cout << cart.totalPrice() << std::endl << std::endl;

	cart.sortByName();
	cart.print();

	std::ofstream ofs("file.dat", std::ios::binary);
	cart.saveToBinary(ofs);
	ofs.close();

	ShoppingCart newCart;

	std::ifstream ifs("file.dat", std::ios::binary);
	newCart.readFromBinary(ifs);
	ifs.close();

	newCart.removeItem("Cola");
	newCart.print();

	return 0;

}