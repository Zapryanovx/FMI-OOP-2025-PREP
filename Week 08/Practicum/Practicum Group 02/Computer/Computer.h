#pragma once
#include <iostream>
#pragma warning(disable:4996)

class Computer
{
public:
	Computer();
	Computer(const char* brand, const char* processor, int video, int hardDrive, int weight, int battery, double price, int quantity);
	Computer(const Computer& other);
	Computer& operator=(const Computer& other);
	~Computer();

	Computer& operator++();
	Computer operator++(int dummy);
	Computer& operator--();
	Computer operator--(int dummy);

	const char* getBrand() const;
	const char* getProcessor() const;
	int getVideo() const;
	int getHardDrive() const;
	int getWeight() const;
	int getBattery() const;
	double getPrice() const;
	int getQuantity() const;

	void print() const;

private:
	static int serial;
	int currSerial;
	char* brand;
	char* processor;
	int video;
	int hardDrive;
	int weight;
	int battery;
	double price;
	int quantity;

	void setBrand(const char* brand);
	void setProcessor(const char* processor);

	void copyFrom(const Computer& other);
	void free();

};

