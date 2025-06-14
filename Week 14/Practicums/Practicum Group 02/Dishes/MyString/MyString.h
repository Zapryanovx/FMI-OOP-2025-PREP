#pragma once
#include <iostream>
#pragma warning(disable:4996)

class MyString
{
public:

	MyString() = default;
	MyString(const char* str);

	MyString(const MyString& other);
	MyString& operator=(const MyString& other);

	MyString(MyString&& other) noexcept;
	MyString& operator=(MyString&& other) noexcept;

	~MyString();

	size_t length() const;
	const char* c_str() const;

private:
	char* str = nullptr;
	size_t size = 0;

	void setStr(const char* str);
	void setSize(size_t size);

	void free();
	void copyFrom(const MyString& other);
	void moveFrom(MyString&& other);
};

bool operator==(const MyString& lhs, const MyString& rhs);
bool operator!=(const MyString& lhs, const MyString& rhs);

