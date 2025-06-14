#include "SurfAndTurf.h"

SurfAndTurf::SurfAndTurf(const MyString* ingredients, size_t size, size_t cookTime, const MyString& meat, const MyString& seafood)
    : Dish(ingredients, size, cookTime), MeatDish(ingredients, size, cookTime, meat), SeafoodDish(ingredients, size, cookTime, seafood) {}


void SurfAndTurf::print() const {
    Dish::print();  

    std::cout << "[Protein] : " << getMeat().c_str() << std::endl;
    std::cout << "[Seafood]: " << getSeafood().c_str() << std::endl;
}