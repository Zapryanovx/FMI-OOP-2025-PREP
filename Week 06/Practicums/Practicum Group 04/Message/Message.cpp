#include "Message.h"

void Message::copyFrom(const Message& other)
{
	sender = new char[strlen(other.sender) + 1] {};
	std::strcpy(sender, other.sender);

	receiver = new char[strlen(other.receiver) + 1] {};
	std::strcpy(receiver, other.receiver);
	
	message = new char[strlen(other.message) + 1] {};
	std::strcpy(message, other.message);

	font = other.font;
}

void Message::free()
{
	delete[] sender;
	sender = nullptr;
	
	delete[] receiver;
	receiver = nullptr;
	
	delete[] message;
	message = nullptr;
	
	font = 0;
}

void Message::setSender(const char* sender)
{
	if (!sender || this->sender == sender)
	{
		return;
	}

	this->sender = new char[std::strlen(sender) + 1] {};
	std::strcpy(this->sender, sender);
}

void Message::setReceiver(const char* receiver)
{
	if (!receiver || this->receiver == receiver)
	{
		return;
	}

	this->receiver = new char[std::strlen(receiver) + 1] {};
	std::strcpy(this->receiver, receiver);
}

void Message::setMessage(const char* message)
{
	if (!message || this->message == message)
	{
		return;
	}

	this->message = new char[std::strlen(message) + 1] {};
	std::strcpy(this->message, message);
}

void Message::setFont(int font)
{
	if (font <= 0)
	{
		return;
	}

	this->font = font;
}

Message::Message(const char* sender, const char* receiver, const char* message, int font)
{
	setSender(sender);
	setReceiver(receiver);
	setMessage(message);
	setFont(font);
}

Message::Message(const Message& other)
{
	copyFrom(other);
}

Message& Message::operator=(const Message& other)
{
	if (this != &other)
	{
		free();
		copyFrom(other);
	}

	return *this;
}

Message::~Message()
{
	free();
}

const char* Message::getSender() const
{
	return sender;
}

const char* Message::getReceiver() const
{
	return receiver;
}

const char* Message::getMessage() const
{
	return message;
}

int Message::getFont() const
{
	return font;
}