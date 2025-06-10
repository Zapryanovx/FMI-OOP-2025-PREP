#include <iostream>
#include <utility> // for std::move
#include "Vector.h"
#include "Matrix.h"

int main() {
    // --- Test Vector functionality ---
    double arrV[] = { 1.0, 2.0, 3.0 };
    Vector v(arrV, 3);
    std::cout << "Original Vector v: "; v.write();
    std::cout << "v.count() = " << v.count() << std::endl;
    std::cout << "v.member(2.0) = " << std::boolalpha << v.member(2.0) << std::endl;
    std::cout << "v[1] = " << v[1] << std::endl;

    // Modify element and verify
    v[1] = 5.0;
    std::cout << "After v[1] = 5.0, v: "; v.write();

    // Copy constructor
    Vector vCopy = v;
    std::cout << "Copy-constructed Vector vCopy: "; vCopy.write();

    // Move constructor
    Vector vMoved = std::move(vCopy);
    std::cout << "Move-constructed Vector vMoved: "; vMoved.write();
    std::cout << "vCopy.count() after move = " << vCopy.count() << std::endl;

    // --- Test Matrix functionality ---
    const size_t N = 2;
    double row0[] = { 1.0, 2.0 };
    double row1[] = { 3.0, 4.0 };
    const double* data2[N] = { row0, row1 };
    Matrix m(data2, N);

    std::cout << "\nOriginal Matrix m:" << std::endl;
    m.write();
    std::cout << "m.count() = " << m.count() << std::endl;
    std::cout << "m.member(3.0) = " << std::boolalpha << m.member(3.0) << std::endl;
    std::cout << "m[2] = " << m[2] << std::endl;

    // Modify element and verify
    m[2] = 9.0;
    std::cout << "After m[2] = 9.0, m:" << std::endl;
    m.write();

    // Clone functionality
    DynamicContainer* cloneM = m.clone();
    std::cout << "Cloned Matrix cloneM:" << std::endl;
    cloneM->write();
    delete cloneM;

    return 0;
}