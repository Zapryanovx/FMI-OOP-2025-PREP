#pragma once
#include "WebPage.h"

namespace Constants
{
	constexpr size_t PAGES_MAX_SIZE = 30;
}

class Browser
{
public:
	Browser() = default;
	void addPage(const WebPage& page);
	void removePage(const char* address, const char* ipAddress);
	
	Browser& operator+=(const WebPage& page);
	Browser& operator-=(size_t index);

	void print() const;

private:
	WebPage pages[Constants::PAGES_MAX_SIZE]{};
	size_t size = 0;
};

