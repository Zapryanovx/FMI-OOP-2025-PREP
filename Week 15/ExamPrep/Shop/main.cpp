#include <iostream>
#include "Fruit.h"
#include "Vegetable.h"
#include "Shop.h"

int main() {
    try {
        // Create some fruits and vegetables
        Fruit apple(Type::Fruit, 95, 1.2, "Apple", "red");
        Fruit banana(Type::Fruit, 105, 0.8, "Banana", "yellow");
        Vegetable carrot(Type::Vegetable, 25, 0.5, "Carrot", "root");

        // Test comparison operator for Fruit
        std::cout << "Is banana > apple? " << (banana > apple ? "Yes" : "No") << std::endl;

        // Create shop and add items
        Shop shop;
        shop.addItem(apple);
        shop.addItem(banana);
        shop.addItem(carrot);

        std::cout << "\nInitial shop items:" << std::endl;
        shop.print();

        // Update price and name of an item
        shop.changePrice(1, 0.75);
        shop.changeName(1, "Banana Premium");

        std::cout << "\nAfter updating banana:" << std::endl;
        shop.print();

        // Find and display lowest-calorie item
        const StoreItem* lowCal = shop.findLowestCalories();
        std::cout << "\nLowest-calorie item:" << std::endl;
        lowCal->print();

        // Remove an item and display remaining
        shop.removeItem(0);
        std::cout << "\nAfter removing first item:" << std::endl;
        shop.print();

        // Test copy constructor of Shop
        Shop shopCopy(shop);
        std::cout << "\nCopied shop contents:" << std::endl;
        shopCopy.print();

        // Test move constructor of Shop
        Shop shopMove(std::move(shopCopy));
        std::cout << "\nMoved shop contents (shopCopy should now be empty):" << std::endl;
        shopMove.print();
    }
    catch (const std::exception& e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    return 0;
}
