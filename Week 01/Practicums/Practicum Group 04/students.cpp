#include <iostream>
#pragma warning(disable: 4996)

enum class Age : uint8_t
{
	freshman,
	sophomore,
	junior,
	senior,
	none,
};

struct Student
{
	char* name = nullptr;
	char* surname = nullptr;
	int egn = 0;
	Age age = Age::freshman;
};

Age getAgeEnum(int age)
{
	switch (age)
	{
		case 1:
			return Age::freshman;
			break;
		case 2:
			return Age::sophomore;
			break;
		case 3:
			return Age::junior;
			break;
		case 4:
			return Age::senior;
			break;
		default:
			return Age::none;
			break;
	}

}
Student readStudent()
{
	int nameSize;
	std::cin >> nameSize;
	char* name = new char[nameSize + 1];
	for (int i = 0; i < nameSize; i++) 
	{
		std::cin >> name[i]; 
	}

	int surnameSize;
	std::cin >> surnameSize;
	char* surname = new char[surnameSize + 1];
	for (int i = 0; i < surnameSize; i++)
	{
		std::cin >> surname[i];
	}

	int egn;
	std::cin >> egn;

	int age;
	std::cin >> age;

	Student student;
	
	student.name = new char[nameSize + 1];
	strncpy(student.name, name, nameSize);
	student.name[nameSize] = '\0';
	delete[] name;

	student.surname = new char[surnameSize + 1];
	strncpy(student.surname, surname, surnameSize);
	student.surname[surnameSize] = '\0';
	delete[] surname;

	student.egn = egn;
	student.age = getAgeEnum(age);

	return student;
}

const char* getAgeStr(Age age)
{
	switch (age)
	{
		case Age::freshman:
			return "freshman";
			break;
		case Age::sophomore:
			return "sophomore";
			break;
		case Age::junior:
			return "junior";
			break;
		case Age::senior:
			return "senior";
			break;
		case Age::none:
			return "none";
			break;
	}
}

void printStudent(const Student& student)
{
	std::cout << student.name << " " << student.surname << 
		  " " << student.egn << " " << getAgeStr(student.age) << std::endl;
}

void freeStudent(Student& student)
{
	delete[] student.name;
	student.name = nullptr;

	delete[] student.surname;
	student.surname = nullptr;
}

const int STUDENTS_MAX_SIZE = 256;
struct University
{
	char* name = nullptr;
	Student students[STUDENTS_MAX_SIZE]{};
	int studentsSize = 0;

	bool hasStudent(const Student& target)
	{
		for (int i = 0; i < studentsSize; i++)
		{
			if (students[i].egn == target.egn)
			{
				return true;
			}
		}

		return false;
	}

	void addStudent(const Student& other)
	{
		if (hasStudent(other))
		{
			return;
		}

		students[studentsSize++] = other;
	}

	void removeStudent(int targetEgn)
	{
		if (studentsSize == 0)
		{
			return;
		}

		int targetIdx = -1;
		for (int i = 0; i < studentsSize; i++)
		{
			if (students[i].egn == targetEgn)
			{
				targetIdx = i;
				break;
			}
		}

		if (targetIdx != -1)
		{
			freeStudent(students[targetIdx]);
		}

		else
		{
			return;
		}

		for (int i = targetIdx; i < studentsSize - 1; i++)
		{

			students[i] = students[i + 1];
		}

		studentsSize -= 1;
	}

	void printStudents(Age age)
	{
		for (int i = 0; i < studentsSize; i++)
		{
			if (students[i].age == age)
			{
				printStudent(students[i]);
			}
		}
	}
};

void freeUniversity(University& university, int n)
{
	delete[] university.name;
	university.name = nullptr;

	for (int i = 0; i < n; i++)
	{
		freeStudent(university.students[i]);
	}
}

int main()
{
	University fmi;

	Student st = readStudent();
	fmi.addStudent(st);
	std::cout << fmi.hasStudent(st) << std::endl; // 1
	
	Student st2 = readStudent();
	fmi.addStudent(st2);
	
	Student st3 = readStudent();
	std::cout << fmi.hasStudent(st3) << std::endl; // 0
	std::cout << "size: " << fmi.studentsSize << std::endl;

	fmi.removeStudent(123);
	std::cout << "size: " << fmi.studentsSize << std::endl;

	fmi.removeStudent(312312);
	std::cout << "size: " << fmi.studentsSize << std::endl;

	Age age = Age::freshman;
	fmi.printStudents(age);

	freeUniversity(fmi, fmi.studentsSize);

	std::cout << fmi.studentsSize << std::endl;

	return 0;
}