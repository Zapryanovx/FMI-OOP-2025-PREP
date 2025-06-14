#include "SurfAndTurf.h"

int main() {
    MyString ingredients[] = { MyString("a"), MyString("b") };
    SurfAndTurf sat(ingredients, 2, 30, MyString("pork"), MyString("seafood2dsaz"));

    sat.print();
}