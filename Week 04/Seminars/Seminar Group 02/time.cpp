#include <iostream>
#include <iomanip>

namespace CONSTANTS
{
	constexpr size_t SECONDS_IN_MIN = 60;
	constexpr size_t MINS_IN_HOUR = 60;
	constexpr size_t HOURS_IN_DAY = 24;
	constexpr size_t SECONDS_IN_DAY = 86400;

	constexpr size_t UPPER_BOUND_DINNER_HOUR = 22;
	constexpr size_t LOWER_BOUND_DINNER_HOUR = 20;
	constexpr size_t LOWER_BOUND_DINNER_MINUTE = 30;
	
	constexpr size_t UPPER_BOUND_PARTY_HOUR = 6;
	constexpr size_t LOWER_LOWER_PARTY_HOUR = 23;
}

class Time
{
	unsigned hours = 0;
	unsigned minutes = 0;
	unsigned seconds = 0;
	
	void setHours(unsigned hours)
	{
		if (hours > 23)
		{
			this->hours = 0;
			return;
		}

		this->hours = hours;
	}


	void setMinutes(unsigned minutes)
	{
		if (minutes > 59)
		{
			this->minutes = 0;
			return;
		}

		this->minutes = minutes;
	}


	void setSeconds(unsigned seconds)
	{
		if (seconds > 59)
		{
			this->seconds = 0;
			return;
		}

		this->seconds = seconds;
	}

	void incrementHours()
	{
		hours++;
		if (hours >= CONSTANTS::HOURS_IN_DAY)
		{
			hours %= CONSTANTS::HOURS_IN_DAY;
		}
	}

	void incrementMins()
	{
		minutes++;
		if (minutes >= CONSTANTS::MINS_IN_HOUR)
		{
			minutes = 0;
			incrementHours();
		}
	}

	unsigned convertToSeconds() const
	{
		return seconds
			+ (hours * CONSTANTS::MINS_IN_HOUR * CONSTANTS::SECONDS_IN_MIN)
			+ (minutes * CONSTANTS::SECONDS_IN_MIN);
	}

public:

	Time() = default;

	Time(int seconds)
	{
		setHours((seconds / CONSTANTS::SECONDS_IN_MIN) / CONSTANTS::MINS_IN_HOUR);
		setMinutes((seconds / CONSTANTS::SECONDS_IN_MIN) % CONSTANTS::MINS_IN_HOUR);
		setSeconds(seconds % CONSTANTS::SECONDS_IN_MIN);
	}

	Time(unsigned hours, unsigned minutes, unsigned seconds)
	{
		setHours(hours);
		setMinutes(minutes);
		setSeconds(seconds);
	}

	Time remaining() const
	{
		int newHours = CONSTANTS::HOURS_IN_DAY - hours - 1;
		int newMinutes = CONSTANTS::MINS_IN_HOUR - minutes - 1;
		int newSeconds = CONSTANTS::SECONDS_IN_MIN - seconds;

		if (newSeconds >= 60)
		{
			newSeconds = 0;
			newMinutes += 1;
		}

		if (newMinutes >= 60)
		{
			newMinutes = 0;
			newHours += 1;
		}

		return Time(newHours, newMinutes, newSeconds);
	}

	void tick()
	{
		seconds++;
		if (seconds >= CONSTANTS::SECONDS_IN_MIN)
		{
			seconds = 0;
			incrementMins();
		}
	}

	bool isDinnerTime() const
	{

		if (hours < CONSTANTS::LOWER_BOUND_DINNER_HOUR 
			|| hours > CONSTANTS::UPPER_BOUND_DINNER_HOUR)
		{
			return false;
		}

		else if (hours == CONSTANTS::LOWER_BOUND_DINNER_HOUR 
					&& minutes < CONSTANTS::LOWER_BOUND_DINNER_MINUTE)
		{
			return false;
		}

		else if (hours == CONSTANTS::UPPER_BOUND_DINNER_HOUR 
					&& (minutes > 0 || seconds > 0))
		{
			return false;
		}

		return true;
	}


	bool isPartyTime() const
	{
		return (hours >= CONSTANTS::UPPER_BOUND_PARTY_HOUR 
			|| hours <= CONSTANTS::LOWER_LOWER_PARTY_HOUR);
	}

	Time difference(const Time& other) const
	{
		return Time(convertToSeconds() - other.convertToSeconds());
	}

	bool isEarlier(const Time& other) const
	{
		return convertToSeconds() < other.convertToSeconds();
	}

	void printTime() const
	{
		std::cout << "Time is: "
			<< std::setw(2) << std::setfill('0') << hours << ":"
			<< std::setw(2) << std::setfill('0') << minutes << ":"
			<< std::setw(2) << std::setfill('0') << seconds
			<< std::endl;
	}
};

void sortByCriteria(Time* arr, size_t size, bool(*criteria)(const Time& lhs, const Time& rhs))
{

	for (size_t i = 0; i < size - 1; i++)
	{
		size_t minIdx = i;
		for (size_t j = i + 1; j < size; j++)
		{
			if (criteria(arr[minIdx], arr[j]))
			{
				minIdx = j;
			}
		}

		if (minIdx != i)
		{
			std::swap(arr[i], arr[minIdx]);
		}
	}

}
int main()
{

	Time time1 = { 20, 31, 0};
	std::cout << time1.isDinnerTime() << std::endl;
	std::cout << std::endl;

	Time time3 = time1.remaining();
	std::cout << time3.isPartyTime() << std::endl;
	time3.printTime();
	std::cout << std::endl;

	Time time2 = { 0, 59, 59 };
	time2.tick();
	time2.printTime();
	std::cout << std::endl;

	Time diff = time1.difference(time3);
	diff.printTime();
	std::cout << std::endl;

	Time times[3] = { time1, time2, time3 };
	sortByCriteria(times, 3, [](const Time& lhs, const Time& rhs) -> bool {
		return lhs.isEarlier(rhs);
	});

	for (int i = 0; i < 3; i++)
	{
		times[i].printTime();
	}

	return 0;
}