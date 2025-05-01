#include "Picture.h"

void Picture::setMatrix(const Pixel** pixels, size_t rows, size_t cols)
{
	if (!pixels)
	{
		throw std::invalid_argument("invalid pixels");
	}

	this->rows = rows;
	this->cols = cols;

	this->pixels = new Pixel**[rows] {};
	for (size_t i = 0; i < rows; i++)
	{
		this->pixels[i] = new Pixel*[cols]{};
		for (size_t j = 0; j < cols; j++)
		{
			if (pixels[i][j].r > 255 || pixels[i][j].g > 255 || pixels[i][j].b > 255)
			{
				throw std::invalid_argument("invalid pixel found");
			}

			this->pixels[i][j] = new Pixel(pixels[i][j]);
		}
	}
}

void Picture::copyFrom(const Picture& other)
{
	pixels = new Pixel**[other.rows] {};
	rows = other.rows;
	cols = other.cols;
	
	for (size_t i = 0; i < rows; i++)
	{
		pixels[i] = new Pixel * [other.cols]{};
		for (size_t j = 0; j < cols; j++)
		{
			pixels[i][j] = new Pixel(*other.pixels[i][j]);
		}
	}

	mode = other.mode;
}

void Picture::moveFrom(Picture&& other)
{
	pixels = other.pixels;
	other.pixels = nullptr;

	rows = other.rows;
	cols = other.cols;

	other.rows = other.cols = 0;

	mode = other.mode;
	other.mode = Mode::None;
}

void Picture::free()
{
	for (size_t i = 0; i < rows; i++)
	{
		for (size_t j = 0; j < cols; j++)
		{
			delete pixels[i][j];
		}

		delete[] pixels[i];
	}

	delete[] pixels;
	pixels = nullptr;

	rows = cols = 0;
}

Picture::Picture(const Pixel** pixels, size_t rows, size_t cols)
{
	setMatrix(pixels, rows, cols);
}

Picture::Picture(const Picture& other)
{
	copyFrom(other);
}

Picture& Picture::operator=(const Picture& other)
{
	if (this != &other)
	{
		free();
		copyFrom(other);
	}

	return *this;
}

Picture::~Picture()
{
	free();
}

Picture::Picture(Picture&& other) noexcept
{
	moveFrom(std::move(other));
}

Picture& Picture::operator=(Picture&& other) noexcept
{
	if (this != &other)
	{
		free();
		moveFrom(std::move(other));
	}

	return *this;
}

int Picture::calcGray(const Pixel& p) const
{
	return 0.299 * p.r + 0.587 * p.g + 0.114 * p.b;
}

void Picture::grayscale()
{
	if (mode != Mode::Color)
	{
		throw std::exception("cannot grayscale");
	}

	for (size_t i = 0; i < rows; i++)
	{

		for (size_t j = 0; j < cols; j++)
		{
			if (!pixels[i][j])
			{
				continue;
			}

			pixels[i][j]->r = calcGray(*pixels[i][j]);
			pixels[i][j]->g = calcGray(*pixels[i][j]);
			pixels[i][j]->b = calcGray(*pixels[i][j]);
		}
	}

	mode = Mode::Grayscale;
}

void Picture::monochrome()
{
	if (mode != Mode::Color)
	{
		throw std::exception("cannot monochrome");
	}

	for (size_t i = 0; i < rows; i++)
	{

		for (size_t j = 0; j < cols; j++)
		{
			if (!pixels[i][j])
			{
				continue;
			}

			if (calcGray(*pixels[i][j]) < 128)
			{
				pixels[i][j]->r = 0;
				pixels[i][j]->g = 0;
				pixels[i][j]->b = 0;
			}

			else
			{
				pixels[i][j]->r = 255;
				pixels[i][j]->g = 255;
				pixels[i][j]->b = 255;
			}
		}
	}
}

void Picture::negative()
{
	for (size_t i = 0; i < rows; i++)
	{

		for (size_t j = 0; j < cols; j++)
		{
			if (!pixels[i][j])
			{
				continue;
			}

			pixels[i][j]->r = 255 - pixels[i][j]->r;
			pixels[i][j]->g = 255 - pixels[i][j]->g;
			pixels[i][j]->b = 255 - pixels[i][j]->b;
		}
	}
}

void Picture::print() const
{
	for (size_t i = 0; i < rows; i++)
	{

		for (size_t j = 0; j < cols; j++)
		{
			if (!pixels[i][j])
			{
				std::cout << "(-, -, -)";
			}

			else
			{
				pixels[i][j]->print();
			}

			if (j != cols - 1)
			{
				std::cout << " ";
			}
		}

		std::cout << std::endl;
	}

	std::cout << std::endl;
}