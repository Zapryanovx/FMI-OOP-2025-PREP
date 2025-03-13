#include <iostream>
#include <fstream>
#pragma warning(disable:4996)

namespace CONSTANTS
{
	constexpr size_t BRAND_MAX_SIZE = 100;
	constexpr size_t MODEL_MAX_SIZE = 100;
	constexpr size_t CARS_MAX_SIZE = 1000;
}

enum class EngineType
{
	GASOLINE,
	DIESEL,
	ELECTRICITY,
	NONE,
};

class Car
{
	char brand[CONSTANTS::BRAND_MAX_SIZE]{};
	char model[CONSTANTS::MODEL_MAX_SIZE]{};
	EngineType type = EngineType::NONE;
	bool isSecondHand = false;
	unsigned mileage = 0;
	double price = 0.0;

	void setBrand(const char* brand)
	{
		if (!brand)
		{
			return;
		}

		strcpy(this->brand, brand);
	}

	void setModel(const char* model)
	{
		if (!model)
		{
			return;
		}

		strcpy(this->model, model);
	}

	void setType(EngineType type)
	{
		this->type = type;
	}

	void setPrice(double price)
	{
		if (price < 0.0)
		{
			return;
		}

		this->price = price;
	}

	void setIsSecondHand(bool isSecondHand)
	{
		this->isSecondHand = isSecondHand;
	}

	void setMileage(unsigned mileage)
	{
		this->mileage = mileage;
	}

	const char* convertEngineTypeToStr(EngineType type) const
	{
		switch (type)
		{
			case EngineType::GASOLINE:
				return "Gasoline";
			case EngineType::DIESEL:
				return "Diesel";
			case EngineType::ELECTRICITY:
				return "Electricity";
			case EngineType::NONE:
				return "None";
		}
	}

public:

	Car() = default;

	Car(const char* brand, const char* model, EngineType type, double price)
	{
		setBrand(brand);
		setModel(model);
		setType(type);
		setPrice(price);
		setIsSecondHand(false);
		setMileage(0);
	}

	void printInfo() const
	{
		std::cout << "[Brand]: " << brand << " " << "[Model]: " << model << std::endl;
		std::cout << "----[Engine Type]: " << convertEngineTypeToStr(type) << std::endl;
		std::cout << "----[Price]: " << price << std::endl;
		std::cout << "----[Second Hand]: " << (isSecondHand ? "True": "False") << std::endl;
		std::cout << "----[Mileage]: " << mileage << std::endl;
	}

	void drive(unsigned kms)
	{
		isSecondHand = true;
		mileage += kms;

		for (int i = 0; i < kms; i++)
		{
			price *= 0.99;
		}
	}

	const char* getBrand() const
	{
		return brand;
	}

	const char* getModel() const
	{
		return model;
	}

	EngineType getType() const
	{
		return type;
	}

	double getPrice() const
	{
		return price;
	}
};

class CarDealership
{
	Car cars[CONSTANTS::CARS_MAX_SIZE]{};
	size_t size = 0;

	void setCars(const Car* cars, size_t size)
	{
		if (!cars || size == 0)
		{
			return;
		}

		for (size_t i = 0; i < size; i++)
		{
			this->cars[i] = cars[i];
		}

		this->size = size;
	}

	void setCarsWithEngineType(const Car* cars, size_t size, EngineType type)
	{
		if (!cars || size == 0)
		{
			return;
		}

		for (size_t i = 0; i < size; i++)
		{
			if (cars[i].getType() == type)
			{
				this->cars[this->size++] = cars[i];
			}
		}
	}

	void setCarsWithEngineType(const Car* cars, size_t size, const char* model)
	{
		if (!cars || size == 0 || !model)
		{
			return;
		}

		for (size_t i = 0; i < size; i++)
		{
			if (!strcmp(cars[i].getModel(), model))
			{
				this->cars[this->size++] = cars[i];
			}
		}
	}

	int getIndexByBrandAndModel(const char* brand, const char* model)
	{
		for (size_t i = 0; i < size; i++)
		{
			if(!strcmp(this->cars[i].getBrand(), brand)
				&& !strcmp(this->cars[i].getModel(), model))
			{
				return i;
			}
		}

		return -1;
	}

	int getIndexByModel(const char* model)
	{
		for (size_t i = 0; i < size; i++)
		{
			if (!strcmp(this->cars[i].getModel(), model))
			{
				return i;
			}
		}

		return -1;
	}

public:

	CarDealership() = default;

	CarDealership(const Car* cars, size_t size)
	{
		setCars(cars, size);
	}

	CarDealership(const Car* cars, size_t size, EngineType type)
	{
		setCarsWithEngineType(cars, size, type);
	}

	CarDealership(const Car* cars, size_t size, const char* model)
	{
		setCarsWithEngineType(cars, size, model);
	}

	size_t getSize() const
	{
		return size;
	}

	void addCar(const Car& car)
	{
		if (size >= CONSTANTS::CARS_MAX_SIZE)
		{
			return;
		}

		cars[size++] = car;
	}

	void removeCar(const char* brand, const char* model)
	{
		if (!brand || !model)
		{
			return;
		}

		int idx = getIndexByBrandAndModel(brand, model);
		if (idx == -1)
		{
			return;
		}

		std::swap(cars[idx], cars[size - 1]);
		size--;
	}

	void testDrive()
	{
		for (size_t i = 0; i < size; i++)
		{
			cars[i].drive(1);
		}
	}

	void printInfo(const char* model)
	{
		if (!model)
		{
			return;
		}

		int idx = getIndexByModel(model);
		if (idx == -1)
		{
			return;
		}

		cars[idx].printInfo();
	}
	
	const Car& getMostExpensiveCar() const
	{
		size_t at = 0;

		for (size_t i = 1; i < size; i++)
		{
			if (cars[at].getPrice() < cars[i].getPrice())
			{
				at = i;
			}
		}

		return cars[at];
	}

	double getAvgPriceOfSameBrand(const Car& car) const
	{
		size_t count = 0;
		int sum = 0;
		
		for (size_t i = 0; i < size; i++)
		{
			if (!strcmp(cars[i].getBrand(), car.getBrand()))
			{
				sum += cars[i].getPrice();
				count++;
			}
		}

		return (double)sum / count;
	}
};

int main()
{

	CarDealership cd;
	
	const char brand[4] = "BMW";
	const char model[3] = "X5";
	EngineType type = EngineType::GASOLINE;
	double price = 10000.75;
	Car c1(brand, model, type, price);

	const char brand2[3] = "da";
	const char model2[3] = "ad";
	EngineType type2 = EngineType::DIESEL;
	double price2 = 5.50;
	Car c2(brand2, model2, type2, price2);

	cd.addCar(c1);
	cd.addCar(c2);

	cd.testDrive();

	cd.printInfo(model2);

	std::cout << cd.getAvgPriceOfSameBrand(c1) << std::endl;

	Car c3 = cd.getMostExpensiveCar();
	c3.printInfo();

	cd.removeCar(brand, model);
	Car c4 = cd.getMostExpensiveCar();
	c4.printInfo();

	return 0;
}

