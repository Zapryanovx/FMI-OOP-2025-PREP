#include <iostream>
#include "Sequence.hpp"
#include "ArithmeticProgression.hpp"
#include "GeometricProgression.hpp"
#include "Fibonacci.hpp"

int main() {
    ArithmeticProgression<int> ap1(1, 2);
    std::cout << "Arithmetic progression (1, step 2):\n";
    for (int i = 0; i < 5; ++i) {
        std::cout << "  a[" << i << "] = " << ap1.getNth(i) << "\n";
    }
    std::cout << "\n";

    GeometricProgression<int> gp1(2, 3);
    std::cout << "Geometric progression (2, ratio 3):\n";
    for (int i = 0; i < 5; ++i) {
        std::cout << "  g[" << i << "] = " << gp1.getNth(i) << "\n";
    }
    std::cout << "\n";

    Fibonacci<int> fib(5);
    std::cout << "Fibonacci sequence (cache size = " << fib.getCacheSize() << "):\n";
    for (int i = 0; i < 5; ++i) {
        std::cout << "  F[" << i << "] = " << fib.getNth(i) << "\n";
    }
    std::cout << "\n";

    fib.setCacheSize(10);
    std::cout << "New Fibonacci cache size = " << fib.getCacheSize() << "\n\n";
    for (int i = 0; i < 10; ++i) {
        std::cout << "  F[" << i << "] = " << fib.getNth(i) << "\n";
    }
    std::cout << "\n";

    ArithmeticProgression<int> ap2(5, 5);

    Sequence<int>* sequences[4] = { &ap1, &gp1, &fib, &ap2 };
    const char* names[4] = { "AP1", "GP1", "Fibonacci", "AP2" };

    int bestIndex = 0;
    int bestValue = sequences[0]->getNth(4);
    for (int i = 1; i < 4; ++i) {
        int value = sequences[i]->getNth(4);
        if (value > bestValue) {
            bestValue = value;
            bestIndex = i;
        }
    }

    std::cout << "The sequence with the largest element at index 5 is \""
        << names[bestIndex] << "\" with value "
        << bestValue << "\n";

    return 0;
}
