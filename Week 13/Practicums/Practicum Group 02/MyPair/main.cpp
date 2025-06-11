#include <iostream>
#include <string>
#include "MyPair.hpp"

int main() {
    std::cout << std::boolalpha;

    MyPair<int, int> p1(1, 2);
    MyPair<int, int> p2(1, 2);
    MyPair<int, int> p3(2, 1);

    std::cout << "p1 == p2: " << (p1 == p2) << std::endl;
    std::cout << "p1 != p2: " << (p1 != p2) << std::endl;
    std::cout << "p1 == p3: " << (p1 == p3) << std::endl;
    std::cout << "p1 != p3: " << (p1 != p3) << std::endl;

    std::cout << "p1 < p2: " << (p1 < p2) << std::endl;
    std::cout << "p1 < p3: " << (p1 < p3) << std::endl;
    std::cout << "p3 < p1: " << (p3 < p1) << std::endl;

    MyPair<std::string, double> ps1("apple", 3.14);
    MyPair<std::string, double> ps2("banana", 2.71);

    std::cout << "ps1 == ps2: " << (ps1 == ps2) << std::endl;
    std::cout << "ps1 != ps2: " << (ps1 != ps2) << std::endl;
    std::cout << "ps1 < ps2: " << (ps1 < ps2) << std::endl;
    std::cout << "ps2 < ps1: " << (ps2 < ps1) << std::endl;

    return 0;
}
