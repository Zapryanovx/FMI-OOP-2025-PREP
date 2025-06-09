#pragma once
#pragma warning(disable:4996)
#include <iostream>

class GrString
{
public:
	GrString(const char* str);

	GrString(const GrString& other);
	GrString& operator=(const GrString& other);

	GrString(GrString&& other) noexcept;
	GrString& operator=(GrString&& other) noexcept;

	~GrString();

	unsigned weight() const;
	const char* c_str() const;

	void setStr(const char* str);

	GrString& operator+=(const GrString& other);
	GrString& operator/=(const GrString& other);

	friend std::istream& operator>>(std::istream& is, GrString& obj);
	friend std::ostream& operator<<(std::ostream& os, const GrString& obj);

private:
	char* str = nullptr;

	void free();
	void copyFrom(const GrString& other);
	void moveFrom(GrString&& other);
};

GrString operator+(const GrString& lhs, const GrString& rhs);
bool operator==(const GrString& lhs, const GrString& rhs);
