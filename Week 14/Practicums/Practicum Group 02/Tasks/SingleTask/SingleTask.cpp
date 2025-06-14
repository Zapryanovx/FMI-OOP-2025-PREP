#include "SingleTask.h"

SingleTask::SingleTask(const MyString& task, size_t start, size_t duration):
	WorkItem(task), start(start), duration(duration) {}


bool SingleTask::status(long now) const {
	if (start + duration >= now) {
		return true;
	}

	return false;
}

void SingleTask::print(size_t level) const {
	for (size_t i = 0; i < level; i++) {
		std::cout << " ";
	}

	WorkItem::print();
}

WorkItem* SingleTask::clone() const {
	return new SingleTask(*this);
}