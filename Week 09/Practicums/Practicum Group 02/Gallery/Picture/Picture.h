#include "Pixel.h"

enum class Mode
{
	Color,
	Grayscale,
	Monochrome,
	Negative,
	None,
};

class Picture
{
public:
	Picture() = default;
	Picture(const Pixel** pixels, size_t rows, size_t cols);
	Picture(const Picture& other);
	Picture& operator=(const Picture& other);
	~Picture();

	Picture(Picture&& other) noexcept;
	Picture& operator=(Picture&& other) noexcept;

	void grayscale();
	void monochrome();
	void negative();

	void print() const;

private:
	Pixel*** pixels = nullptr;
	size_t rows = 0;
	size_t cols = 0;
	Mode mode = Mode::Color;
	
	void setMatrix(const Pixel** pixels, size_t rows, size_t cols);
	int calcGray(const Pixel& p) const;

	void copyFrom(const Picture& other);
	void moveFrom(Picture&& other);
	void free();
};