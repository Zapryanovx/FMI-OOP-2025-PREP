#include "SmartHome.h"

int main()
{

	MyString lightName("Living Room Light");
	MyString makerA("A");
	SmartLight light(lightName, makerA, 49, 75);

	MyString speakerName("Kitchen Speaker");
	MyString makerB("B");
	SmartSpeaker speaker(speakerName, makerB, 89, 50);

	MyString thermoName("Bedroom Thermostat");
	SmartThermostat thermostat(thermoName, makerA, 120, 22, 25);

	SmartHome home;
	home.add(&light);
	home.add(&speaker);
	home.add(&thermostat);

	home.print();
	std::cout << std::endl;
	home.turnOn(0);
	home.turnOff(2);

	std::cout << "[Maker A]: " << home.avgPriceOf("A") << std::endl;

	home.remove("Kitchen Speaker");
	std::cout << std::endl;
	home.print();

	return 0;

}