#include "builder.h"
#include <string>
#include <utility>

Coffee::Coffee(std::string requester_name) :
	requester_name(std::move(requester_name)), is_hot(false), has_milk(false), has_sugar(false), cost(0.0) {
}

const std::string& Coffee::getRequesterName() const {
	return requester_name;
}

bool Coffee::isHot() const {
	return is_hot;
}

void Coffee::setIsHot(bool is_hot) {
	Coffee::is_hot = is_hot;
}

bool Coffee::isHasMilk() const {
	return has_milk;
}

void Coffee::setHasMilk(bool has_milk) {
	Coffee::has_milk = has_milk;
}

bool Coffee::isHasSugar() const {
	return has_sugar;
}

void Coffee::setHasSugar(bool has_sugar) {
	Coffee::has_sugar = has_sugar;
}

double Coffee::getCost() const {
	return cost;
}

void Coffee::setCost(double cost) {
	Coffee::cost = cost;
}

CoffeeBuilder::CoffeeBuilder(std::string requester_name) :
	coffee(Coffee(std::move(requester_name))) {
}

// Implement the Coffee classes "create" method
CoffeeBuilder Coffee::create(std::string requester_name) {
	return CoffeeBuilder{std::move(requester_name)};
}

// Builder methods
CoffeeBuilder& CoffeeBuilder::makeHot() {
	coffee.is_hot = true;
	return *this; // Allow fluent builder (method chaining)
}

CoffeeBuilder& CoffeeBuilder::addSugar() {
	coffee.has_sugar = true;
	return *this; // Allow fluent builder (method chaining)
}

CoffeeBuilder& CoffeeBuilder::addMilk() {
	coffee.has_milk = true;
	return *this; // Allow fluent builder (method chaining)
}

CoffeeBuilder& CoffeeBuilder::costs(double cost) {
	coffee.cost = cost;
	return *this; // Allow fluent builder (method chaining)
}

CoffeeBuilder::operator Coffee() const {
	return coffee;
}
