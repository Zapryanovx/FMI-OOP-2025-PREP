#pragma once
#include "Container.h"

namespace DCConstants {
	constexpr double EPSILON = 0.0000001;
}

class DynamicContainer : public Container
{
public:
	DynamicContainer(const double* data, size_t N);

	DynamicContainer(const DynamicContainer& other);
	DynamicContainer& operator=(const DynamicContainer& other);

	DynamicContainer(DynamicContainer&& other) noexcept;
	DynamicContainer& operator=(DynamicContainer&& other) noexcept;

	~DynamicContainer();

	bool member(double x) const override;
	double& operator[](size_t i) override;
	const double& operator[](size_t i) const override;
	int count() const override;

	virtual DynamicContainer* clone() const = 0;

protected:
	double* data = nullptr;
	size_t N = 0;

	explicit DynamicContainer(size_t N);

private:
	void free();
	void copyFrom(const DynamicContainer& other);
	void moveFrom(DynamicContainer&& other);
};

