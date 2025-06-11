#include <iostream>
#include <string>
#include "MyVector.hpp"

template <typename T>
void printVector(const MyVector<T>& vec, const std::string& name) {
    std::cout << name << " (size=" << vec.getSize()
        << ", capacity=" << vec.getCapacity() << "): ";
    for (size_t i = 0; i < vec.getSize(); ++i) {
        std::cout << vec[i] << ' ';
    }
    std::cout << std::endl;
}

int main() {
    MyVector<int> vec;
    for (int i = 1; i <= 5; ++i) {
        vec.push_back(i * 10);
    }
    printVector(vec, "vec after push_back");

    vec.pop_back();
    printVector(vec, "vec after pop_back");

    vec.insert(1, 25);
    printVector(vec, "vec after insert(1, 25)");

    vec.erase(2);
    printVector(vec, "vec after erase(2)");

    std::cout << "front: " << vec.front()
        << ", back: " << vec.back() << std::endl;

    vec.clear();
    std::cout << "vec.empty() after clear(): "
        << std::boolalpha << vec.empty() << std::endl;

    MyVector<std::string> strVec(3, "hello");
    printVector(strVec, "strVec(3, \"hello\")");

    MyVector<std::string> copyVec = strVec;
    copyVec.push_back("world");
    printVector(strVec, "strVec after copy");
    printVector(copyVec, "copyVec");

    MyVector<std::string> movedVec = std::move(copyVec);
    printVector(movedVec, "movedVec");
    std::cout << "copyVec.empty() after move: "
        << std::boolalpha << copyVec.empty() << std::endl;

    movedVec.shrink_to_fit();
    std::cout << "movedVec capacity after shrink_to_fit: "
        << movedVec.getCapacity() << std::endl;

    return 0;
}
