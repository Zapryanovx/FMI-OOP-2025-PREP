#include <iostream>
#include <fstream>
#include "Even.hpp"
#include "Range.hpp"
#include "Container.hpp"
#include "ManySets.hpp"

int main()
{

    ManySets<int> allSets;

    allSets.addSet(Even());
    allSets.addSet(Range<int>(5, 15));

    Container<int> c;
    c.add(3);
    c.add(7);
    c.add(11);
    allSets.addSet(c);

    int testValue = 7;

    std::cout << "Testing " << testValue << std::endl;

    for (int i = 0; i < 3; i++)
    {

        std::cout << "Set #" << i << ": "
            << (allSets[i]->member(testValue) ? "yes" : "no") << std::endl;

    }

    std::cout << allSets << std::endl;

    return 0;
}