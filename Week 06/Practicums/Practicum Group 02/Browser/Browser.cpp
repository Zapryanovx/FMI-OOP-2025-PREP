#include "Browser.h"

void Browser::addPage(const WebPage& page)
{
	if (size == Constants::PAGES_MAX_SIZE)
	{
		return;
	}

	pages[size++] = page;
}

void Browser::removePage(const char* address, const char* ipAddress)
{
	if (!address || !ipAddress)
	{
		return;
	}

	for (size_t i = 0; i < size; i++)
	{
		if (!std::strcmp(pages[i].getAddress(), address)
			&& !std::strcmp(pages[i].getIpAddress(), ipAddress))
		{
			std::swap(pages[i], pages[size - 1]);
			size--;
			break;
		}
	}
}

Browser& Browser::operator+=(const WebPage& page)
{
	addPage(page);
	return *this;
}

Browser& Browser::operator-=(size_t index)
{
	if (index < 0 || index >= size)
	{
		throw std::invalid_argument("err");
	}

	removePage(pages[index].getAddress(), pages[index].getIpAddress());
	return *this;
}

void Browser::print() const
{
	for (int i = 0; i < size; i++)
	{
		std::cout << pages[i];
	}

	std::cout << std::endl;
}