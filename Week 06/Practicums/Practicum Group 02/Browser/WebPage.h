#pragma once
#include <iostream>
#pragma warning(disable:4996)

class WebPage
{
public:
	WebPage() = default;
	WebPage(const char* address, const char* ipAdress);
	WebPage(const WebPage& other);
	WebPage& operator=(const WebPage& other);
	~WebPage();

	const char* getAddress() const;
	const char* getIpAddress() const;

	friend std::ostream& operator<<(std::ostream& os, const WebPage& wp);
	friend std::istream& operator>>(std::istream& is, WebPage& wp);

private:
	char* address = nullptr;
	char* ipAddress = nullptr;

	void setAddress(const char* address);
	void setIpAddress(const char* ipAddress);

	void copyFrom(const WebPage& other);
	void free();
};

