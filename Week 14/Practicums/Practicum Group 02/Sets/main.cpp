#include <iostream>
#include "SetByCriteria.hpp"
#include "UnionOfSets.h"
#include "IntersectionOfSets.h"

struct IsEven {
    bool operator()(unsigned int x) const {
        return x % 2 == 0;
    }
};

struct DivisibleByThree {
    bool operator()(unsigned int x) const {
        return x % 3 == 0;
    }
};

int main() {
    Set* even = new SetByCriteria<IsEven>(IsEven{});
    Set* div3 = new SetByCriteria<DivisibleByThree>(DivisibleByThree{});

    const Set* sets[] = { even, div3 };

    UnionOfSets unionSet(sets, 2);
    IntersectionOfSets intersectionSet(sets, 2);

    std::cout << "UNION (Conjuction)\n";
    for (unsigned int i = 1; i <= 10; ++i) {
        std::cout << i << ": " << unionSet.accepts(i) << '\n';
    }

    std::cout << "\nINTERSECTION (Disjunction):\n";
    for (unsigned int i = 1; i <= 10; ++i) {
        std::cout << i << ": " << intersectionSet.accepts(i) << '\n';
    }

    delete even;
    delete div3;

    return 0;
}
