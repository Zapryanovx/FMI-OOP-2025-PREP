#include "ArraySet.h"

void ArraySet::copyFrom(const ArraySet& other)
{
	nums = new int[other.capacity] {};
	size = other.size;
	capacity = other.capacity;

	for (size_t i = 0; i < size; i++)
	{
		nums[i] = other.nums[i];
	}
}

void ArraySet::moveFrom(ArraySet&& other)
{
	nums = other.nums;
	other.nums = nullptr;

	size = other.size;
	capacity = other.capacity;

	other.capacity = other.size = 0;
}

void ArraySet::free()
{
	delete[] nums;
	nums = nullptr;

	capacity = size = 0;
}

ArraySet::ArraySet(unsigned n)
{
	capacity = n;
	size = 0;
	nums = new int[n] {};
}

ArraySet::ArraySet(const ArraySet& other) 
{
	copyFrom(other);
}

ArraySet& ArraySet::operator=(const ArraySet& other)
{
	if (this != &other)
	{
		free();
		copyFrom(other);
	}

	return *this;
}

ArraySet::ArraySet(ArraySet&& other) noexcept
{
	moveFrom(std::move(other));
}

ArraySet& ArraySet::operator=(ArraySet&& other) noexcept
{
	if (this != &other)
	{
		free();
		moveFrom(std::move(other));
	}
	
	return *this;
}

ArraySet::~ArraySet()
{
	free();
}

bool ArraySet::insert(int x)
{
	if (size == capacity || member(x))
	{
		return false;
	}

	nums[size++] = x;
}

bool ArraySet::remove(int x)
{
	if (!member(x))
	{
		return false;
	}

	for (size_t i = 0; i < size; i++)
	{
		if (x == nums[i])
		{
			std::swap(nums[i], nums[size - 1]);
			size--;
			break;
		}
	}

	return true;
}

bool ArraySet::member(int x) const
{
	for (size_t i = 0; i < size; i++)
	{
		if (x == nums[i])
		{
			return true;
		}
	}

	return false;
}

int ArraySet::get(int i) const
{
	if (i >= size)
	{
		throw std::out_of_range("invalid index");
	}
	
	return nums[i];
}

bool ArraySet::isSubsetOf(const IntSet* s) const
{
	for (size_t i = 0; i < size; i++)
	{
		if (!s->member(nums[i]))
		{
			return false;
		}
	}

	return true;
}

bool ArraySet::intersects(const IntSet* s) const
{
	for (size_t i = 0; i < size; i++)
	{
		if (s->member(nums[i]))
		{
			return true;
		}
	}

	return false;
}

void  ArraySet::print() const
{
	std::cout << "<<<<< Array Set >>>>>" << std::endl;
	for (size_t i = 0; i < size; i++)
	{
		std::cout << nums[i];

		if (i != size - 1)
		{
			std::cout << " ";
		}
	}

	std::cout << std::endl;
}