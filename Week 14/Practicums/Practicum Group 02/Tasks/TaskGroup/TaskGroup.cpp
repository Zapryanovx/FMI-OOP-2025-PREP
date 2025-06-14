#include "TaskGroup.h"

TaskGroup::TaskGroup(const MyString& task): WorkItem(task) {
	capacity = 8;
	size = 0;
	arr = new WorkItem * [capacity] {};
}

TaskGroup::TaskGroup(const TaskGroup& other): WorkItem(other) {
	copyFrom(other);
}

TaskGroup& TaskGroup::operator=(const TaskGroup& other) {
	if (this != &other) {
		WorkItem::operator=(other);
		free();
		copyFrom(other);
	}

	return *this;
}

TaskGroup::TaskGroup(TaskGroup&& other) noexcept: WorkItem(std::move(other)) {
	moveFrom(std::move(other));
}

TaskGroup& TaskGroup::operator=(TaskGroup&& other) noexcept {
	if (this != &other) {
		WorkItem::operator=(std::move(other));
		free();
		moveFrom(std::move(other));
	}

	return *this;
}

TaskGroup::~TaskGroup() {
	free();
}

void TaskGroup::add(WorkItem* item) {
	if (size == capacity) {
		resize(capacity * 2);
	}

	arr[size++] = item;
}

bool TaskGroup::status(long now) const {
	for (size_t i = 0; i < size; i++) {
		if (!arr[i]->status(now)) {
			return false;
		}
	}

	return true;
}

void TaskGroup::print(size_t level) const {
	for (size_t i = 0; i < level; i++) {
		std::cout << " ";
	}

	std::cout << getTask().c_str() << std::endl;

	for (size_t i = 0; i < size; i++) {
		arr[i]->print(level + 1);
	}
}

WorkItem* TaskGroup::clone() const {
	return new TaskGroup(*this);
}

void TaskGroup::resize(size_t newCap) {
	WorkItem** newArr = new WorkItem * [newCap] {};
	for (size_t i = 0; i < size; i++) {
		newArr[i] = arr[i];
	}

	capacity = newCap;
}

void TaskGroup::free() {
	for (size_t i = 0; i < size; i++) {
		delete arr[i];
	}

	delete[] arr;
	arr = nullptr;
	capacity = size = 0;
}
void TaskGroup::copyFrom(const TaskGroup& other) {
	arr = new WorkItem * [other.capacity] {};
	for (size_t i = 0; i < other.size; i++) {
		arr[i] = other.arr[i]->clone();
	}

	size = other.size;
	capacity = other.capacity;
}
void TaskGroup::moveFrom(TaskGroup&& other) {
	arr = other.arr;
	other.arr = nullptr;

	size = other.size;
	capacity = other.capacity;

	other.capacity = other.size = 0;
}

