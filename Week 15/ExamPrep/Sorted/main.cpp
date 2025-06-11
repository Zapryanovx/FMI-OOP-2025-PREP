#include <iostream>
#include "Sorted.hpp"

int main() {

    Sorted<int> s;
    std::cout << "Adding elements: 5, 1, 3, 4, 2" << std::endl;
    s.add(5);
    s.add(1);
    s.add(3);
    s.add(4);
    s.add(2);
    std::cout << "After adds: ";
    s.print();  // Expect: 1 | 2 | 3 | 4 | 5

    // Test removing elements
    std::cout << "Remove 3" << std::endl;
    s.remove(3);
    std::cout << "After remove(3): ";
    s.print();  // Expect: 1 | 2 | 4 | 5

    std::cout << "Remove 1" << std::endl;
    s.remove(1);
    std::cout << "After remove(1): ";
    s.print();  // Expect: 2 | 4 | 5

    try {
        std::cout << "Attempt remove 10" << std::endl;
        s.remove(10);
    }
    catch (const std::invalid_argument& e) {
        std::cout << "Caught exception: " << e.what() << std::endl;
    }
    
    std::cout << "Copying sorted to s2" << std::endl;
    Sorted<int> s2 = s;
    std::cout << "s2: "; s2.print();

    std::cout << "Moving s2 to s3" << std::endl;
    Sorted<int> s3 = std::move(s2);
    std::cout << "s3: "; s3.print();
    std::cout << "s2 after move (should be empty): "; s2.print();

    return 0;
}
