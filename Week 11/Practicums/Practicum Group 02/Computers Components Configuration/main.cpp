#include "Component.h"
#include "Memory.h"
#include "CPU.h"
#include "Configuration.h"
#include "ComponentFactory.h"

int main()
{

	Configuration config;
	Component* cpu = Create_Component();

	if (cpu)
	{
		config.insert(cpu);
	}

	std::cin.ignore();
	std::cout << std::endl;

	Component* memory = Create_Component();

	if (memory) 
	{
		config.insert(memory);
	}

	std::cout << config;
	std::cout << config.price() << std::endl;

	return 0;
}
