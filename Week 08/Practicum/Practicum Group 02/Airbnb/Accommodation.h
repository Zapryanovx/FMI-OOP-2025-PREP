#pragma once
#include <iostream>
#pragma warning(disable:4996)

enum class Type
{
	Apartment,
	Hotel,
	Villa,
	None
};

struct Point
{
	int x;
	int y;

	double calculateDistance(const Point& other) const
	{

		double param1 = x - other.x;
		double param2 = y - other.y;

		return sqrt(param1 * param1 + param2 * param2);

	}
};

class Accommodation
{
public:
	Accommodation();
	Accommodation(const char* name, Type type, Point location, double price, bool reserved, unsigned duration);
	Accommodation(const Accommodation& other);
	Accommodation& operator=(const Accommodation& other);
	~Accommodation();

	void reserve();
	void unreserve();
	bool isReserved() const;

	double total() const;

	void print() const;

	unsigned getId() const;
	const Point& getLocation() const;

	void setDuration(unsigned duration);

private:
	static unsigned id;
	unsigned currId;
	char* name;
	Type type;
	Point location;
	double price;
	bool reserved;
	unsigned duration;
	
	void setName(const char* name);

	void copyFrom(const Accommodation& other);
	void free();
};

