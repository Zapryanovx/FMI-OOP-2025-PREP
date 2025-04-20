#include "ArithmeticProgression.h"

int main()
{
    ArithmeticProgression ap;
    ArithmeticProgression ap2;

    ArithmeticProgression ap3 = ap + ap2;

    ap3 &= 3;
    std::cout << ap3[1];

    return 0;
}