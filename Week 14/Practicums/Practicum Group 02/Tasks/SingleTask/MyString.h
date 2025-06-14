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

	const char* c_str() const;
	size_t length() const;

private:
	char* str;
	size_t size;

	void setStr(const char* str);
	void setSize(size_t size);

	void free();
	void copyFrom(const MyString& other);
	void moveFrom(MyString&& other);
};

