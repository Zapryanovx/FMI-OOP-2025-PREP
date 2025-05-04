#include "TimestampWithDescription.h"

void TimestampWithDescription::setDesc(const char* desc)
{
	if (!desc)
	{
		throw std::invalid_argument("invalid desc");
	}

	this->desc = new char[std::strlen(desc) + 1] {};
	strcpy(this->desc, desc);
}

void TimestampWithDescription::copyFrom(const TimestampWithDescription& other)
{
	desc = new char[std::strlen(other.desc) + 1] {};
	strcpy(desc, other.desc);
}

void TimestampWithDescription::moveFrom(TimestampWithDescription&& other)
{
	desc = other.desc;
	other.desc = nullptr;
}

void TimestampWithDescription::free()
{
	delete[] desc;
	desc = nullptr;
}

const char* TimestampWithDescription::getDecs() const
{
	return desc;
}

std::istream& operator>>(std::istream& is, TimestampWithDescription& ts)
{
	unsigned long long seconds;
	is >> seconds;

	char buff[1024]{};
	is.getline(buff, 1024);

	TimestampWithDescription res(seconds, buff);
	ts = res;
	return is;
}

std::ostream& operator<<(std::ostream& os, const TimestampWithDescription& ts)
{
	return os << ts.getSeconds() << " " << ts.getDecs();
}

TimestampWithDescription::TimestampWithDescription(unsigned long long seconds, const char* desc) : Timestamp(seconds)
{
	setDesc(desc);
}

TimestampWithDescription::TimestampWithDescription(const TimestampWithDescription& other) : Timestamp(other)
{
	copyFrom(other);
}

TimestampWithDescription& TimestampWithDescription::operator=(const TimestampWithDescription& other)
{
	if (this != &other)
	{
		Timestamp::operator=(other);
		free();
		copyFrom(other);
	}

	return *this;
}

TimestampWithDescription::TimestampWithDescription(TimestampWithDescription&& other) noexcept : Timestamp(std::move(other))
{
	moveFrom(std::move(other));
}

TimestampWithDescription& TimestampWithDescription::operator=(TimestampWithDescription&& other) noexcept
{
	if (this != &other)
	{
		Timestamp::operator=(std::move(other));
		free();
		moveFrom(std::move(other));
	}
	
	return *this;
}

TimestampWithDescription::~TimestampWithDescription()
{
	free();
}
