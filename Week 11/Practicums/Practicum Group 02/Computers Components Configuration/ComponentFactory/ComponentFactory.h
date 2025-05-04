#include "Component.h"
#include "CPU.h"
#include "Memory.h"

enum class Type
{
	CPU,
	Memory,
};

Component* Create_Component();