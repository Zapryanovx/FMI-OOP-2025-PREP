#include "ComponentFactory.h"

Component* Create_Component()
{
	std::cout << "> Choose a component to create:" << std::endl;
	std::cout << "[0] - CPU" << std::endl;
	std::cout << "[1] - Memory" << std::endl;

	int choice;
	std::cin >> choice;
	std::cin.ignore();

	Type type = Type(choice);

	if (type == Type::CPU)
	{
		std::cout << "> Please input (name, cores, clock speed):" << std::endl;
 		char buff[1024]{};
		unsigned short cores;
		unsigned short clockSpeed;

		std::cin.getline(buff, 1024);
		std::cin >> cores >> clockSpeed;

		try
		{
			CPU* cpu = new CPU(buff, cores, clockSpeed);
			return cpu;
		}

		catch (...)
		{
			return nullptr;
		}
	}

	else if (type == Type::Memory)
	{
		std::cout << "> Please input (name, capacity):" << std::endl;

		char buff[1024]{};
		unsigned short capacity;

		std::cin.getline(buff, 1024);
		std::cin >> capacity;

		try
		{
			Memory* memory = new Memory(buff, capacity);
			return memory;
		}

		catch (...)
		{
			return nullptr;
		}
	}

	else
	{
		std::cout << "[Error] Invalid choice. Please try again..." << std::endl;
		return Create_Component();
	}

}