#include "WebPage.h"


void WebPage::copyFrom(const WebPage& other)
{
	address = new char[std::strlen(other.address) + 1] {};
	strcpy(address, other.address);

	ipAddress = new char[std::strlen(other.ipAddress) + 1] {};
	strcpy(ipAddress, other.ipAddress);
}

void WebPage::free()
{
	delete[] address;
	address = nullptr;

	delete[] ipAddress;
	ipAddress = nullptr;
}

const char* WebPage::getAddress() const
{
	return address;
}

const char* WebPage::getIpAddress() const
{
	return ipAddress;
}

void WebPage::setAddress(const char* address)
{
	if (!address)
	{
		return;
	}

	this->address = new char[std::strlen(address) + 1] {};
	strcpy(this->address, address);
}

void WebPage::setIpAddress(const char* ipAddress)
{
	if (!ipAddress)
	{
		return;
	}

	this->ipAddress = new char[std::strlen(ipAddress) + 1] {};
	strcpy(this->ipAddress, ipAddress);
}

WebPage::WebPage(const char* address, const char* ipAddress)
{
	setAddress(address);
	setIpAddress(ipAddress);
}

WebPage::WebPage(const WebPage& other)
{
	copyFrom(other);
}

WebPage& WebPage::operator=(const WebPage& other)
{
	if (this != &other)
	{
		free();
		copyFrom(other);
	}

	return *this;
}

WebPage::~WebPage()
{
	free();
}

std::ostream& operator<<(std::ostream& os, const WebPage& wp)
{
	os << strlen(wp.address) << " " << wp.address << std::endl;
	os << strlen(wp.ipAddress) << " " << wp.ipAddress << std::endl;
	return os;
}

std::istream& operator>>(std::istream& is, WebPage& wp)
{
	wp.free();

	int sizeAddress = 0;
	int sizeIpAddress = 0;

	is >> sizeAddress;
	wp.address = new char[sizeAddress + 1];
	is >> wp.address;

	is >> sizeIpAddress;
	wp.ipAddress = new char[sizeIpAddress + 1];
	is >> wp.ipAddress;

	return is;
}