#pragma once
#include "DynamicContainer.h"

class Matrix: public DynamicContainer
{
public:
	Matrix(const double* const* data, size_t N);

	virtual void write() const override;
	virtual DynamicContainer* clone() const override;

private:
	size_t dim;
};

