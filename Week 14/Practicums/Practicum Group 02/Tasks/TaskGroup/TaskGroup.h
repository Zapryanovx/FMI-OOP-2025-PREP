#pragma once
#include "WorkItem.h"

class TaskGroup: public WorkItem
{
public:
	TaskGroup(const MyString& task);

	TaskGroup(const TaskGroup& other);
	TaskGroup& operator=(const TaskGroup& other);

	TaskGroup(TaskGroup&& other) noexcept;
	TaskGroup& operator=(TaskGroup&& other) noexcept;

	~TaskGroup();

	void add(WorkItem* item);

	bool status(long now) const override;
    void print(size_t level = 0) const override;

	WorkItem* clone() const override;
private:
	WorkItem** arr;
	size_t size;
	size_t capacity;

	void resize(size_t newCap);

	void free();
	void copyFrom(const TaskGroup& other);
	void moveFrom(TaskGroup&& other);

};

