#include "ConsultantUtils.h"

bool ConsultantUtils::isGoodForGaming(const Computer& computer)
{
	if (std::strcmp(computer.getProcessor(), "i5")
		&& std::strcmp(computer.getProcessor(), "i7"))
	{
		return false;
	}

	if (computer.getVideo() != 3060
		&& computer.getVideo() != 3070
		&& computer.getVideo() != 3080
		&& computer.getVideo() != 3090)
	{
		return false;
	}

	if (computer.getHardDrive() < 512)
	{
		return false;
	}

	return true;
}

bool ConsultantUtils::isGoodForTravel(const Computer& computer)
{
	if (computer.getWeight() <= 2.5 && computer.getBattery() > 6)
	{
		return true;
	}

	return false;
}