#pragma once
#include "MyString.h"

class WorkItem
{
public:

	WorkItem(const MyString& task);

	virtual bool status(long now) const = 0;
	virtual void print(size_t level = 0) const = 0;
	virtual WorkItem* clone() const = 0;

protected:
	const MyString& getTask() const;

private:
	MyString task;
};

