#pragma once
#include "Accommodation.h"
#pragma warning(disable:4996)

class Airbnb
{
public:
	Airbnb();
	Airbnb(const Airbnb& other);
	Airbnb& operator=(const Airbnb& other);
	~Airbnb();

	void addAcc(const Accommodation& acc);
	void removeAcc(unsigned id);
	
	void reserve(unsigned id, unsigned duration);
	void unreserve(unsigned id);

	double getProfit() const;
	double getAlltimeProfit() const;

	const Accommodation& getClosest(const Point& location) const;

	void print() const;

private:
	Accommodation* accs;
	size_t size;
	size_t capacity;

	double totalProfit = 0.0;
	double currProfit = 0.0;

	int getIndexOf(unsigned id);

	void copyFrom(const Airbnb& other);
	void free();
	void resize(size_t newCap);
};

