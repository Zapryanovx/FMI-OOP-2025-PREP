#pragma once
class Size
{
public:
	Size();
	Size(size_t height, size_t width);

	void setHeight(size_t height);
	void setWidth(size_t width);

private:
	size_t height = 0;
	size_t width = 0;
};

