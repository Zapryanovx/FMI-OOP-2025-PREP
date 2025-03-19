#pragma once
#include <iostream>
#pragma warning(disable:4996)

namespace CONSTANTS
{
	constexpr size_t MAX_POINTS = 100;
}

class GradeReport
{
public:

	GradeReport() = default;
	GradeReport(const unsigned* grades, size_t size, const char* report);
	GradeReport(const GradeReport& other);
	GradeReport& operator=(const GradeReport& other);
	~GradeReport();

	size_t getSize() const;
	const char* getReport() const;
	double getAvgRes() const;

private:

	unsigned getSumOfPoints() const;
	bool isGradesValid(const unsigned* grades, size_t size) const;

	void setGrades(const unsigned* grades, size_t size);
	void setReport(const char* report);

	void copyFrom(const GradeReport& other);
	void free();

	unsigned* grades = nullptr;
	size_t size = 0;
	char* report = nullptr;
};
