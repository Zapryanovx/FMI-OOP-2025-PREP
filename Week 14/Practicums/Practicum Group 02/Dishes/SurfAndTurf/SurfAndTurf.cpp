#include "SurfAndTurf.h"

SurfAndTurf::SurfAndTurf(const MyString* ingredients, size_t size, const MyString& meat, const MyString& seafood)
    : Dish(ingredients, size), MeatDish(ingredients, size, meat), SeafoodDish(ingredients, size, seafood) {}


void SurfAndTurf::print() const {
    Dish::print(); 

    std::cout << "[Protein] : " << getMeat().c_str() << std::endl;
    std::cout << "[Seafood]: " << getSeafood().c_str() << std::endl;
}