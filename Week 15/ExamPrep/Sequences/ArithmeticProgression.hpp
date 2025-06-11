#pragma once
#include "Sequence.hpp"

template <typename T>
class ArithmeticProgression: public Sequence<T> {
public:
	ArithmeticProgression(const T& start, const T& d);
	virtual T getNth(int nth) override;

private:
	T start;
	T d;
};

template <typename T>
ArithmeticProgression<T>::ArithmeticProgression(const T& start, const T& d) : start(start), d(d) {}

template <typename T>
T ArithmeticProgression<T>::getNth(int nth) {
	T res = start + d * nth;
	return res;
}