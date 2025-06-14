#pragma once
#include "WorkItem.h"

class SingleTask: public WorkItem
{
public:
	SingleTask(const MyString& task, size_t start, size_t duration);

	bool status(long now) const override;
	void print(size_t level = 0) const override;

	WorkItem* clone() const override;

private:
	size_t start = 0;
	size_t duration = 0;
};

