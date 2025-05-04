#pragma once
#include "Student.h"

class StudentDB
{
public:
	StudentDB();
	
	StudentDB(const StudentDB& other);
	StudentDB& operator=(const StudentDB& other);

	StudentDB(StudentDB&& other) noexcept;
	StudentDB& operator=(StudentDB&& other) noexcept;

	~StudentDB();

	size_t getSize() const;
	size_t getCapacity() const;
	const Student* const* getStudents() const;

	void add(const Student& st);
	void remove(unsigned fn);
	const Student& find(unsigned fn);
	void display() const;
	void swapStudents(size_t i, size_t j);

private:
	Student** students;
	size_t size;
	size_t capacity;

	void copyFrom(const StudentDB& other);
	void moveFrom(StudentDB&& other);
	void free();

	void resize(size_t newCap);

	int getIndexOf(unsigned fn);

};

