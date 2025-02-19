#include <iostream>
#pragma warning(disable:4996)


namespace CONSTANTS
{
	constexpr int NAME_SIZE = 32;
	constexpr int STUDENTS_MAX_SIZE = 50;
}

enum class Major
{

	SI,
	IS,
	KN,
	MA,
	None,
};

struct Student
{
	char name[CONSTANTS::NAME_SIZE]{};
	int fn = 123456;
	double avgGrade = 0.0;
	Major major = Major::None;
};

Student studentInit(const char* name, int fn, Major major)
{
	if (strlen(name) > 32)
	{
		return {};
	}

	Student student;

	strncpy(student.name, name, strlen(name));
	student.name[strlen(name)] = '\0';

	student.fn = fn;
	student.major = major;

	return student;
}

const char* getMajorStr(Major major)
{
	switch (major)
	{
		case Major::SI:
			return "SI";
			break;
		case Major::KN:
			return "KN";
			break;
		case Major::IS:
			return "IS";
			break;
		case Major::MA:
			return "MA";
			break;
		default:
			return "None";
			break;
	}
}

void printStudent(const Student& student)
{
	std::cout << student.name << " " << student.fn <<
		" " << student.avgGrade << " " << getMajorStr(student.major) << std::endl;
}

struct Course
{
	Student students[CONSTANTS::STUDENTS_MAX_SIZE]{};
	int studentsCount = 0;
};

void addStudent(Course& course, const Student& student)
{
	if (course.studentsCount >= CONSTANTS::STUDENTS_MAX_SIZE)
	{
		return;
	}

	course.students[course.studentsCount++] = student;
}

void removeStudent(Course& course, int fn)
{
	if (course.studentsCount == 0)
	{
		return;
	}

	int removeAt = -1;
	for (int i = 0; i < course.studentsCount; i++)
	{
		if (course.students[i].fn == fn)
		{
			removeAt = i;
			break;
		}
	}

	for (int i = removeAt; i < course.studentsCount - 1; i++)
	{
		course.students[i] = course.students[i + 1];
	}

	course.studentsCount--;
}

void sortByGrades(Course& course)
{
	double* grades = new double[course.studentsCount];
	for (int i = 0; i < course.studentsCount; i++)
	{
		grades[i] = course.students[i].avgGrade;
	}

	for (int i = 0; i < course.studentsCount - 1; i++)
	{
		int minGrade = i;

		for (int j = i + 1; j < course.studentsCount; j++)
		{
			if (grades[j] <= grades[minGrade])
			{
				minGrade = j;
			}
		}

		if (minGrade != i)
		{
			if (grades[minGrade] == grades[i])
			{
				if (strcmp(course.students[minGrade].name, course.students[i].name) < 0)
				{
					std::swap(course.students[minGrade], course.students[i]);
					std::swap(grades[minGrade], grades[i]);
				}
			}

			else
			{
				std::swap(course.students[minGrade], course.students[i]);
				std::swap(grades[minGrade], grades[i]);
			}
		}
	}

}

typedef bool (*pred)(const Student&);
void filter(const Course& course, pred criteria)
{
	for (int i = 0; i < course.studentsCount; i++)
	{
		if (criteria(course.students[i]))
		{
			printStudent(course.students[i]);
		}
	}
}


bool highAchiever(const Student& s) {
	return s.avgGrade >= 5.50;
}

int main()
{
	Course course;

	Student s1 = studentInit("Ivan", 1001, Major::SI);
	s1.avgGrade = 5.75;
	addStudent(course, s1);

	Student s2 = studentInit("Maria", 1002, Major::KN);
	s2.avgGrade = 4.90;
	addStudent(course, s2);

	Student s3 = studentInit("Georgi", 1003, Major::IS);
	s3.avgGrade = 5.75;
	addStudent(course, s3);

	std::cout << "Students before sorting:" << std::endl;
	for (int i = 0; i < course.studentsCount; i++)
	{
		printStudent(course.students[i]);
	}

	sortByGrades(course);

	std::cout << std::endl;
	std::cout << "Students after sorting by grades:" << std::endl;
	for (int i = 0; i < course.studentsCount; i++)
	{
		printStudent(course.students[i]);
	}
	std::cout << std::endl;

	std::cout << "Students with high grades:" << std::endl;
	filter(course, highAchiever);

	return 0;
}
