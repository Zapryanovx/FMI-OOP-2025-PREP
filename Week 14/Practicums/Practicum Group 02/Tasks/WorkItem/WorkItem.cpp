#include "WorkItem.h"

WorkItem::WorkItem(const MyString& task): task(task){}

const MyString& WorkItem::getTask() const {
	return task;
}

void WorkItem::print(size_t level) const {
	std::cout << task.c_str() << std::endl;
}