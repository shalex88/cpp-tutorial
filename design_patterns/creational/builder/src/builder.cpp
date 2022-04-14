#include "builder.h"
#include <string>
#include <utility>

// Implement the Coffee classes "create" method
CoffeeBuilder Coffee::create(std::string requesterName) {
	return CoffeeBuilder{std::move(requesterName)};
}

// Builder methods
CoffeeBuilder&  CoffeeBuilder::makeHot() {
	coffee.isHot = true;
	return *this;
}

CoffeeBuilder&  CoffeeBuilder::addSugar() {
	coffee.hasSugar = true;
	return *this;
}

CoffeeBuilder&  CoffeeBuilder::addMilk() {
	coffee.hasMilk = true;
	return *this;
}

CoffeeBuilder&  CoffeeBuilder::costs(double cost) {
	coffee.cost = cost;
	return *this;
}
