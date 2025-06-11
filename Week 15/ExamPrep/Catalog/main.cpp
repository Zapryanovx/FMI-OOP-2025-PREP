#include <iostream>
#include <sstream>
#include "PriceTag.hpp"
#include "PriceCatalog.hpp"   
int main() {
    PriceTag<std::string> pt1("Apple", 1.00);
    std::cout << pt1;

    pt1.discount(10);
    std::cout << pt1;

    PriceTag<std::string> pt2("", 0.0);
    std::istringstream iss("Banana 2.50");
    iss >> pt2;
    std::cout << pt2;

    PriceTag<std::string> initialTags[] = {
        pt1,
        pt2,
        PriceTag<std::string>("Cherry", 3.00)
    };
    
    std::cout << std::endl;
    std::cout << std::endl;

    PriceCatalog<std::string> catalog(initialTags, 3);
    std::cout << catalog;

    std::cout << std::endl;
    std::cout << std::endl;

    catalog += PriceTag<std::string>("Date", 4.00);
    std::cout << catalog;

    return 0;
}
