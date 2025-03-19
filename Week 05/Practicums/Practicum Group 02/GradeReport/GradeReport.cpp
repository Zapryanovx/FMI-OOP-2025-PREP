#include "GradeReport.h"

GradeReport::GradeReport(const unsigned* grades, size_t size, const char* report)
{
	setGrades(grades, size);
	setReport(report);
}

GradeReport::GradeReport(const GradeReport& other)
{
	copyFrom(other);
}

GradeReport& GradeReport::operator=(const GradeReport& other)
{
	if (this != &other)
	{
		free();
		copyFrom(other);
	}

	return *this;
}

GradeReport::~GradeReport()
{
	free();
}

size_t GradeReport::getSize() const
{
	return size;
}

const char* GradeReport::getReport() const
{
	return report;
}

double GradeReport::getAvgRes() const
{
	return (double) getSumOfPoints() / size;
}

unsigned GradeReport::getSumOfPoints() const
{
	unsigned sum = 0;
	for (size_t i = 0; i < size; i++)
	{
		sum += grades[i];
	}

	return sum;
}

bool GradeReport::isGradesValid(const unsigned* grades, size_t size) const
{
	if (!grades || size == 0)
	{
		return false;
	}

	for (size_t i = 0; i < size; i++)
	{
		if (grades[i] > CONSTANTS::MAX_POINTS)
		{
			return false;
		}
	}

	return true;
}

void GradeReport::setGrades(const unsigned* grades, size_t size)
{
	if (!isGradesValid(grades, size))
	{
		return;
	}

	this->grades = new unsigned[size] {};
	this->size = size;

	for (size_t i = 0; i < size; i++)
	{
		this->grades[i] = grades[i];
	}
}

void GradeReport::setReport(const char* report)
{
	if (!report)
	{
		return;
	}

	this->report = new char[strlen(report) + 1] {};
	std::strcpy(this->report, report);
}

void GradeReport::copyFrom(const GradeReport& other)
{
	size = other.size;
	
	grades = new unsigned[size] {};
	for (size_t i = 0; i < size; i++)
	{
		grades[i] = other.grades[i];
	}

	report = new char[std::strlen(other.report) + 1];
	std::strcpy(report, other.report);
}

void GradeReport::free()
{
	delete[] grades;
	grades = nullptr;

	size = 0;

	delete[] report;
	report = nullptr;
}
