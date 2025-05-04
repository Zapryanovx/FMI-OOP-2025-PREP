#pragma once
#include "Timestamp.h"
#pragma warning(disable:4996)

class TimestampWithDescription: public Timestamp
{
public:
	TimestampWithDescription(unsigned long long seconds, const char* desc);
	
	TimestampWithDescription(const TimestampWithDescription& other);
	TimestampWithDescription& operator=(const TimestampWithDescription& other);

	TimestampWithDescription(TimestampWithDescription&& other) noexcept;
	TimestampWithDescription& operator=(TimestampWithDescription&& other) noexcept;

	~TimestampWithDescription();

	const char* getDecs() const;
	
	friend std::istream& operator>>(std::istream& is, TimestampWithDescription& ts);
	friend std::ostream& operator<<(std::ostream& os, const TimestampWithDescription& ts);

private:
	char* desc;

	void setDesc(const char* desc);

	void copyFrom(const TimestampWithDescription& other);
	void moveFrom(TimestampWithDescription&& other);
	void free();
};

