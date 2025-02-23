#include <iostream>
#include <fstream>

namespace CONSTANTS
{
	constexpr int NAME_MAX_SIZE = 100;
	constexpr int STUDENTS_MAX_SIZE = 10;
}

enum class Major
{
	undefined,
	Inf,
	Cs,
	InfS,
	S
};

struct Student
{
	char name[CONSTANTS::NAME_MAX_SIZE]{};
	unsigned fn = 0;
	Major major = Major::undefined;
};

struct StudentDatabase
{
	Student students[CONSTANTS::STUDENTS_MAX_SIZE]{};
	unsigned studentsCount = 0;
};

void serializeStudent(std::ofstream& ofs, const Student& st)
{
	ofs << st.name << std::endl
		<< st.fn << std::endl
		<< (int)st.major << std::endl;
}

void serializeDatabase(std::ofstream& ofs, const StudentDatabase& database)
{
	ofs << database.studentsCount << std::endl;
	for (int i = 0; i < database.studentsCount; i++)
	{
		serializeStudent(ofs, database.students[i]);
	}
}

void deserializeStudent(std::ifstream& ifs, Student& st)
{
	ifs.ignore();
	ifs.getline(st.name, 100);
	ifs >> st.fn;

	int temp;
	ifs >> temp;
	st.major = (Major)temp;
}

StudentDatabase deserializeDatabase(std::ifstream& ifs)
{
	StudentDatabase sd;
	ifs >> sd.studentsCount;
	for (int i = 0; i < sd.studentsCount; i++)
	{
		deserializeStudent(ifs, sd.students[i]);
	}

	return sd;
}

int main()
{
	{
		std::ofstream ofs("students_to_text_file.txt");
		if (!ofs.is_open())
		{
			std::cerr << "Error while opening file for writing" << std::endl;
			return -1;
		}
		StudentDatabase db{
			{
				{"Ivan Popov", 12, Major::InfS},
				{"Petur Aleksandrov", 3312, Major::S},
				{"Kiril Petkov", 3312, Major::S}
			},
			3
		};
		serializeDatabase(ofs, db);
	}
	{
		std::ifstream ifs("students_to_text_file.txt");
		if (!ifs.is_open())
		{
			std::cerr << "Error while opening file for writing" << std::endl;
			return -1;
		}

		StudentDatabase db = deserializeDatabase(ifs);
		std::ofstream fileOut("students_to_text_file_cpy.txt");
		serializeDatabase(fileOut, db);
	}
}