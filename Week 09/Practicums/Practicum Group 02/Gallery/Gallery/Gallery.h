#pragma once
#include "Picture.h"

class Gallery
{
public:
	Gallery();
	Gallery(const Gallery& other);
	Gallery& operator=(const Gallery& other);
	~Gallery();

	Gallery(Gallery&& other) noexcept;
	Gallery& operator=(Gallery&& other) noexcept;

	void add(const Picture& p);
	void remove(size_t index);

	void filter(Mode mode, size_t index);
	void filterAll(Mode mode);

	const Picture& operator[](size_t index) const;
	Picture& operator[](size_t index);

	void print() const;

private:
	Picture* pics;
	size_t size;
	size_t capacity;

	void copyFrom(const Gallery& other);
	void moveFrom(Gallery&& other);
	void free();
	void resize(size_t newCap);
};

