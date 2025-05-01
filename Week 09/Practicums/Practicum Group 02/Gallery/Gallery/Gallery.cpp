#include "Gallery.h"

void Gallery::copyFrom(const Gallery& other)
{
	pics = new Picture[other.capacity]{};
	size = other.size;
	capacity = other.capacity;

	for (size_t i = 0; i < size; i++)
	{
		pics[i] = other.pics[i];
	}
}

void Gallery::moveFrom(Gallery&& other)
{
	pics = other.pics;
	other.pics = nullptr;

	size = other.size;
	capacity = other.capacity;

	other.capacity = other.size = 0;
}

void Gallery::free()
{
	delete[] pics;
	pics = nullptr;

	capacity = size = 0;
}

void Gallery::resize(size_t newCap)
{
	Picture* newPics = new Picture[newCap]{};
	for (size_t i = 0; i < size; i++)
	{
		newPics[i] = pics[i];
	}
	
	delete[] pics;
	pics = newPics;
	newPics = nullptr;

	capacity = newCap;
}

Gallery::Gallery()
{
	capacity = 8;
	size = 0;
	pics = new Picture[capacity]{};
}

Gallery::Gallery(const Gallery& other)
{
	copyFrom(other);
}

Gallery& Gallery::operator=(const Gallery& other)
{
	if (this != &other)
	{
		free();
		copyFrom(other);
	}

	return *this;
}

Gallery::~Gallery()
{
	free();
}

Gallery::Gallery(Gallery&& other) noexcept
{
	moveFrom(std::move(other));
}

Gallery& Gallery::operator=(Gallery&& other) noexcept
{
	if (this != &other)
	{
		free();
		moveFrom(std::move(other));
	}

	return *this;
}

void Gallery::add(const Picture& p)
{
	if (size == capacity)
	{
		resize(capacity * 2);
	}

	pics[size++] = p;
}

void Gallery::remove(size_t index)
{
	if (index >= size)
	{
		throw std::invalid_argument("invalid index");
	}

	for (size_t i = index; i < size - 1; i++)
	{
		pics[i] = pics[i + 1];
	}

	size--;
}

void Gallery::filter(Mode mode, size_t index)
{
	if (index >= size)
	{
		throw std::invalid_argument("invalid index");
	}

	if (mode == Mode::Grayscale)
	{
		pics[index].grayscale();
	}

	else if (mode == Mode::Monochrome)
	{
		pics[index].monochrome();
	}

	else if (mode == Mode::Negative)
	{
		pics[index].negative();
	}

	throw std::invalid_argument("not a valid filter");
}

void Gallery::filterAll(Mode mode)
{
	for (size_t i = 0; i < size; i++)
	{
		filter(mode, i);
	}
}

const Picture& Gallery::operator[](size_t index) const
{
	if (index >= size)
	{
		throw std::invalid_argument("invalid index");
	}

	return pics[index];
}

Picture& Gallery::operator[](size_t index)
{
	if (index >= size)
	{
		throw std::invalid_argument("invalid index");
	}

	return pics[index];
}

void Gallery::print() const
{
	std::cout << "---[Gallery]---" << std::endl;
	for (size_t i = 0; i < size; i++)
	{
		pics[i].print();
		
	}
}
