#include <iostream>
#pragma warning(disable:4996)

namespace CONSTANTS
{
	constexpr size_t NAME_MAX_SIZE = 32;
	constexpr size_t MIN_AGE_CRITERIA = 18;
	constexpr size_t MIN_SALARY_CRITERIA = 2500;
	constexpr size_t MAX_SALARY_CRITERIA = 5000;
	constexpr size_t LANGUAGES_SIZE = 5;
	constexpr size_t MAX_PROGRAMMERS_SIZE = 50;
}

enum class ProgrammingLanguages
{
	CPlusPlus,
	Python,
	Java,
	CSharp,
	JavaScript,
};

const char* convertPLToStr(ProgrammingLanguages pl)
{
	switch (pl)
	{
		case ProgrammingLanguages::CPlusPlus:
			return "C++";
		case ProgrammingLanguages::Python:
			return "Python";
		case ProgrammingLanguages::Java:
			return "Java";
		case ProgrammingLanguages::CSharp:
			return "C#";
		case ProgrammingLanguages::JavaScript:
			return "JavaScript";
	}
}

class Programmer
{
	char name[CONSTANTS::NAME_MAX_SIZE]{};
	unsigned age = 18;
	unsigned salary = 2500;
	uint8_t languages = 0;

	void printProgrammingLanguages() const
	{
		for (size_t i = 0; i < CONSTANTS::LANGUAGES_SIZE; i++)
		{
			ProgrammingLanguages language = (ProgrammingLanguages) i;
			if (doesKnow(language))
			{
				std::cout << convertPLToStr(language);
				if (i != CONSTANTS::LANGUAGES_SIZE - 1)
				{
					std::cout << " | ";
				}
			}
		}
	}

	void setName(const char* name)
	{
		if (!name)
		{
			strcpy(this->name, "Unknown");
			return;
		}

		strcpy(this->name, name);
	}

	void setAge(unsigned age)
	{
		if (age < CONSTANTS::MIN_AGE_CRITERIA)
		{
			age = CONSTANTS::MIN_AGE_CRITERIA;
		}

		this->age = age;
	}

public:
	
	Programmer() = default;
	
	Programmer(const char* name, unsigned age, unsigned salary)
	{
		setName(name);
		setAge(age);
		setSalary(salary);
	}

	const char* getName() const
	{
		return name;
	}

	unsigned getAge() const
	{
		return age;
	}

	unsigned getSalary() const
	{
		return salary;
	}

	void setSalary(unsigned newSalary)
	{
		if (newSalary < CONSTANTS::MIN_AGE_CRITERIA
		 || newSalary > CONSTANTS::MAX_SALARY_CRITERIA)
		{
			salary = CONSTANTS::MIN_SALARY_CRITERIA;
			return;
		}

		salary = newSalary;
	}

	void addProgramingLanguage(ProgrammingLanguages pl)
	{
		int pos = int(pl);
		languages |= (1 << pos);
	}

	void removeProgrammingLanguage(ProgrammingLanguages pl)
	{
		int pos = int(pl);
		languages &= ~(1 << pos);
	}

	bool doesKnow(ProgrammingLanguages pl) const
	{
		int pos = int(pl);
		return languages & (1 << pos);
	}

	void printInfo() const
	{
		std::cout << name << " | " << age << " | " << salary;
		if (languages)
		{
			std::cout << " | ";
			printProgrammingLanguages();
		}
		std::cout << std::endl;
	}
};

class SoftwareCompany
{
	Programmer programmers[CONSTANTS::MAX_PROGRAMMERS_SIZE]{};
	size_t programmersSize = 0;

	size_t getTotalSalaries() const
	{
		size_t total = 0;
		for (size_t i = 0; i < programmersSize; i++)
		{
			total += programmers[i].getSalary();
		}

		return total;
	}

	size_t getTotalAges() const
	{
		size_t total = 0;
		for (size_t i = 0; i < programmersSize; i++)
		{
			total += programmers[i].getAge();
		}

		return total;
	}

	void sortByCriteria(bool(*criteria)(const Programmer& lhs, const Programmer& rhs))
	{
		for (size_t i = 0; i < programmersSize - 1; i++)
		{
			size_t minIdx = i;
			for (size_t j = 0; j < programmersSize; j++)
			{
				if (criteria(programmers[minIdx], programmers[j]))
				{
					minIdx = j;
				}
			}

			if (minIdx != i)
			{
				std::swap(programmers[minIdx], programmers[i]);
			}
		}
	}

	int getIdxByName(const char* name)
	{
		for (size_t i = 0; i < programmersSize; i++)
		{
			if (!strcmp(programmers[i].getName(), name))
			{
				return i;
			}
		}

		return -1;
	}

	void setArr(const Programmer* arr, size_t arrSize)
	{
		if (!arr || arrSize >= CONSTANTS::MAX_PROGRAMMERS_SIZE)
		{
			return;
		}

		for (size_t i = 0; i < arrSize; i++)
		{
			this->programmers[i] = arr[i];
		}

		this->programmersSize = arrSize;
	}

public:
	
	SoftwareCompany() = default;

	SoftwareCompany(const Programmer* arr, size_t arrSize)
	{
		setArr(arr, arrSize);
	}

	void addProgrammer(const Programmer& p)
	{
		if (programmersSize >= CONSTANTS::MAX_PROGRAMMERS_SIZE)
		{
			return;
		}

		programmers[programmersSize++] = p;
	}
	
	size_t getProgrammersSize() const
	{
		return programmersSize;
	}

	void printInfo() const
	{
		for (size_t i = 0; i < programmersSize; i++)
		{
			programmers[i].printInfo();
		}
	}

	void printInfo(ProgrammingLanguages pl) const
	{
		for (size_t i = 0; i < programmersSize; i++)
		{
			if (programmers[i].doesKnow(pl))
			{
				programmers[i].printInfo();
			}
		}
	}

	double getAvgSalary() const
	{
		return double(getTotalSalaries()) / programmersSize;
	}

	double getAvgAge() const
	{
		return double(getTotalAges()) / programmersSize;
	}

	void sortBySalary()
	{
		sortByCriteria([](const Programmer& lhs, const Programmer& rhs) -> bool {
			return lhs.getSalary() > rhs.getSalary();
		});
	}

	void sortByAge()
	{
		sortByCriteria([](const Programmer& lhs, const Programmer& rhs) -> bool {
			return lhs.getAge() > rhs.getAge();
		});
	}

	void changeSalaryOf(const char* name, unsigned (*formula)(const Programmer& programmer))
	{
		if (!name)
		{
			return;
		}

		int idx = getIdxByName(name);
		programmers[idx].setSalary(formula(programmers[idx]));
	}
};

int main()
{
	Programmer p("user", 4214, 2500);
	p.addProgramingLanguage(ProgrammingLanguages::Python);

	//std::cout << p.doesKnow(ProgrammingLanguages::CPlusPlus) << std::endl;
	//std::cout << p.doesKnow(ProgrammingLanguages::Python) << std::endl;

	//p.removeProgrammingLanguage(ProgrammingLanguages::Python);
	//std::cout << p.doesKnow(ProgrammingLanguages::Python) << std::endl;

	//p.printInfo();

	Programmer p2("user2", 4231, 424);
	Programmer p3("user3", 421, 424);

	Programmer arr[2] = { p, p2};
	SoftwareCompany sc(arr, 2);

	sc.addProgrammer(p3);
	
	std::cout << sc.getAvgAge() << std::endl;
	std::cout << sc.getAvgSalary() << std::endl;
	sc.printInfo();
	std::cout << std::endl;
	sc.printInfo(ProgrammingLanguages::Python);

	std::cout << std::endl;
	sc.sortBySalary();
	sc.printInfo();

	std::cout << std::endl;
	sc.sortByAge();
	sc.printInfo();


	sc.changeSalaryOf("user", [](const Programmer& p) -> unsigned {
		return p.getSalary() / 2;
	});

	std::cout << std::endl;
	sc.printInfo();

	return 0;
}