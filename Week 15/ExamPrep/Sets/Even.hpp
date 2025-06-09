#pragma once
#include "Set.hpp"

class Even : public Set<int> {
public:

	bool member(const int& element) const override;
	Set<int>* clone() const override;

	void serialize(std::ostream& os) const override;
	void deserialize(std::istream& is) override;
};

bool Even::member(const int& element) const {
	return element % 2 == 0;
}

Set<int>* Even::clone() const {
	return new Even(*this);
}

void Even::serialize(std::ostream& os) const {
	std::cout << "[Printing Even]" << std::endl;
}

void Even::deserialize(std::istream& is) {
	std::cout << "[Reading Even]" << std::endl;
}

