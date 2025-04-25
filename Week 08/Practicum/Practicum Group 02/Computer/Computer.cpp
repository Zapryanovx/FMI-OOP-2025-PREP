#include "Computer.h"

int Computer::serial = 1;

Computer& Computer::operator++()
{
	quantity++;
	return *this;
}

Computer Computer::operator++(int dummy)
{
	Computer cpy(*this);
	quantity++;
	return cpy;
}

Computer& Computer::operator--()
{
	quantity--;
	return *this;
}

Computer Computer::operator--(int dummy)
{
	Computer cpy(*this);
	quantity--;
	return cpy;
}

void Computer::copyFrom(const Computer& other)
{
	brand = new char[std::strlen(other.brand) + 1] {};
	strcpy(brand, other.brand);

	processor = new char[std::strlen(other.processor) + 1] {};
	strcpy(processor, other.processor);

	video = other.video;
	hardDrive = other.hardDrive;
	weight = other.weight;
	battery = other.battery;
	price = other.price;
	quantity = other.quantity;

}

void Computer::free()
{
	delete[] brand;
	brand = nullptr;

	delete[] processor;
	processor = nullptr;

	video = 0;
	hardDrive = 0;
	weight = 0;
	battery = 0;
	price = 0.0;
	quantity = 0;
}

Computer::Computer(): Computer("default", "default", 0, 0, 0, 0, 0.0, 0){}

Computer::Computer(const char* brand, const char* processor, int video, int hardDrive, int weight, int battery, double price, int quantity) :
	video(video), hardDrive(hardDrive), weight(weight), battery(battery), price(price), quantity(quantity)
{
	setBrand(brand);
	setProcessor(processor);
	currSerial = serial;
	serial++;
}

Computer::Computer(const Computer& other)
{
	copyFrom(other);
}

Computer& Computer::operator=(const Computer& other)
{
	if (this != &other)
	{
		free();
		copyFrom(other);
	}

	return *this;
}

Computer::~Computer()
{
	free();
}

void Computer::setBrand(const char* brand)
{
	if (!brand)
	{
		return;
	}

	this->brand = new char[std::strlen(brand) + 1] {};
	strcpy(this->brand, brand);
}

void Computer::setProcessor(const char* processor)
{
	if (!processor)
	{
		return;
	}

	this->processor = new char[std::strlen(processor) + 1] {};
	strcpy(this->processor, processor);
}

const char* Computer::getBrand() const
{
	return brand;
}

double Computer::getPrice() const
{
	return price;
}

int Computer::getQuantity() const
{
	return quantity;
}

const char* Computer::getProcessor() const
{
	return processor;
}

int  Computer::getVideo() const
{
	return video;
}

int  Computer::getHardDrive() const
{
	return hardDrive;
}

int  Computer::getWeight() const
{
	return weight;
}

int  Computer::getBattery() const
{
	return battery;
}

void Computer::print() const
{
	std::cout << "[Serial] " << currSerial << std::endl;
	std::cout << "[Brand] " << brand << std::endl;
	std::cout << "[Processor] " << processor << std::endl;
	std::cout << "[Video] " << video << std::endl;
	std::cout << "[Hard Drive] " << hardDrive << std::endl;
	std::cout << "[Weight] " << weight << std::endl;
	std::cout << "[Battery] " << battery << std::endl;
	std::cout << "[Price] " << price << std::endl;
	std::cout << "[Quantity] " << quantity << std::endl;
	std::cout << "----------------------------------" << std::endl;
}
