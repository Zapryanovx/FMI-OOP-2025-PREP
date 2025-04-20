#pragma once
#include <iostream>
#pragma warning(disable:4996)

class Message
{
public:
	Message() = default;
	Message(const char* sender, const char* receiver, const char* message, int font);
	Message(const Message& other);
	Message& operator=(const Message& other);
	~Message();

	const char* getSender() const;
	const char* getReceiver() const;
	const char* getMessage() const;
	int getFont() const;

private:
	char* sender = nullptr;
	char* receiver = nullptr;
	char* message = nullptr;
	int font = 11;

	void copyFrom(const Message& other);
	void free();

	void setSender(const char* sender);
	void setReceiver(const char* receiver);
	void setMessage(const char* message);
	void setFont(int font);

};

