#pragma once
#include "Sequence.hpp"

template <typename T>
class GeometricProgression: public Sequence<T>
{
public:

	GeometricProgression(const T& start, const T& q);
	virtual T getNth(int nth) override;
	
private: 
	T start;
	T q;
};

template <typename T>
GeometricProgression<T>::GeometricProgression(const T& start, const T& q): start(start), q(q) {}

template <typename T>
T GeometricProgression<T>::getNth(int nth) {
	T res = start * std::pow(q, nth);
	return res;
}
