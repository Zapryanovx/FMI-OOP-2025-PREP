#include "StudentDB.h"

void StudentDB::copyFrom(const StudentDB& other)
{
	students = new Student * [other.capacity] {};
	capacity = other.capacity;
	size = other.size;

	for (size_t i = 0; i < size; i++)
	{
		students[i] = new Student(*other.students[i]);
	}
}

void StudentDB::moveFrom(StudentDB&& other)
{
	students = other.students;
	other.students = nullptr;

	size = other.size;
	capacity = other.capacity;

	other.capacity = other.size = 0;
}

void StudentDB::free()
{
	for (size_t i = 0; i < size; i++)
	{
		delete students[i];
	}

	delete[] students;
	students = nullptr;
	
	capacity = size = 0;
}

void StudentDB::resize(size_t newCap)
{
	Student** newStudents = new Student * [newCap] {};
	for (size_t i = 0; i < size; i++)
	{
		newStudents[i] = students[i];
	}

	delete[] students;
	students = newStudents;
	newStudents = nullptr;

	capacity = newCap;
}

StudentDB::StudentDB()
{
	capacity = 8;
	size = 0;
	students = new Student*[capacity]{};
}

StudentDB::StudentDB(const StudentDB& other)
{
	copyFrom(other);
}

StudentDB& StudentDB::operator=(const StudentDB& other)
{
	if (this != &other)
	{
		free();
		copyFrom(other);
	}
	
	return *this;
}

StudentDB::StudentDB(StudentDB&& other) noexcept
{
	moveFrom(std::move(other));
}

StudentDB& StudentDB::operator=(StudentDB&& other) noexcept
{
	if (this != &other)
	{
		free();
		moveFrom(std::move(other));
	}

	return *this;
}

StudentDB::~StudentDB()
{
	free();
}

void StudentDB::add(const Student& st)
{
	if (size == capacity)
	{
		resize(capacity * 2);
	}

	students[size++] = new Student(st);
}

int StudentDB::getIndexOf(unsigned fn)
{
	for (size_t i = 0; i < size; i++)
	{
		if (students[i]->getFn() == fn)
		{
			return i;
		}
	}

	throw std::invalid_argument("fn not found");
}

void StudentDB::remove(unsigned fn)
{
	int at = getIndexOf(fn);
	std::swap(students[at], students[size - 1]);
	delete students[size - 1];
	size--;
}

const Student& StudentDB::find(unsigned fn)
{
	return *students[getIndexOf(fn)];
}

void StudentDB::display() const
{
	std::cout << "---[Student DB]---" << std::endl;
	for (size_t i = 0; i < size; i++)
	{
		students[i]->print();
	}
}

size_t StudentDB::getSize() const
{
	return size;
}

size_t StudentDB::getCapacity() const
{
	return capacity;
}

const Student* const* StudentDB::getStudents() const
{
	return students;
}

void StudentDB::swapStudents(size_t i, size_t j)
{
	if (i >= size || j >= size)
	{
		throw std::out_of_range("invalid index found");
	}

	std::swap(students[i], students[j]);
}
