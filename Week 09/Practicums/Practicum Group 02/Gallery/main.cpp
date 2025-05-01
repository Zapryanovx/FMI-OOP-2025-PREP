#include <iostream>
#include <stdexcept>
#include "Gallery.h"

int main()
{
    const size_t rows = 2;
    const size_t cols = 3;

    Pixel** pixels = new Pixel * [rows];
    pixels[0] = new Pixel[cols]{ {255, 0, 0}, {0, 255, 0}, {0, 0, 255} };
    pixels[1] = new Pixel[cols]{ {255, 255, 0}, {0, 255, 255}, {255, 0, 255} };

    const Pixel** cPixels = new const Pixel * [rows];
    for (size_t i = 0; i < rows; ++i)
        cPixels[i] = pixels[i];

    try
    {
        Picture original(cPixels, rows, cols);
        Picture gray(original);
        Picture neg(original);

        Gallery gal;
        gal.add(original);
        gal.add(gray);
        gal.add(neg);

        std::cout << "--- Gallery after add ---\n";
        gal.print();

        gal[1].monochrome();
        std::cout << "--- Gallery after gal[1].monochrome() ---\n";
        gal.print();

        gal.remove(0);
        std::cout << "--- Gallery after remove(0) ---\n";
        gal.print();

    }
    catch (const std::exception& ex)
    {
        std::cerr << "Exception: " << ex.what() << '\n';
    }

    for (size_t i = 0; i < rows; ++i)
        delete[] pixels[i];
    delete[] pixels;
    delete[] cPixels;

    return 0;
}
