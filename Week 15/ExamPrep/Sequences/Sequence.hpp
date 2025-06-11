#pragma once
#include <iostream>

template <typename T>
class Sequence {
public:

	virtual T getNth(int nth) = 0;
	virtual ~Sequence() = default;
};