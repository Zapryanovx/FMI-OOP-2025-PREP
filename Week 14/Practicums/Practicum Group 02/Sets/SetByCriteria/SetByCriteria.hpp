#include "Set.h"

template <typename T>
class SetByCriteria : public Set {

public:
	SetByCriteria(const T& obj);
	SetByCriteria(T&& obj);

	bool accepts(unsigned int el) const;
	Set* clone() const override;


protected:
	const T& getObj() const;

private:
	T obj;
};

template <typename T>
SetByCriteria<T>::SetByCriteria(const T& obj): obj(obj){}

template <typename T>
SetByCriteria<T>::SetByCriteria(T&& obj) : obj(std::move(obj)) {}

template <typename T>
bool SetByCriteria<T>::accepts(unsigned int el) const {
	return obj(el);
}

template <typename T>
const T& SetByCriteria<T>::getObj() const {
	return obj;
}

template <typename T>
Set* SetByCriteria<T>::clone() const {
	return new SetByCriteria(*this);
}