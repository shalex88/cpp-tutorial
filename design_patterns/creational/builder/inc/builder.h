#ifndef CPP_TUTORIAL_BUILDER_H
#define CPP_TUTORIAL_BUILDER_H

#include <iostream>
#include <string>
#include <utility>

// Forward declare CoffeeBuilder class here to avoid compilation errors
class CoffeeBuilder;

// Coffee class declaration
class Coffee
{
	std::string requesterName;

public:
	bool isHot;
	bool hasMilk;
	bool hasSugar;
	double cost;

	explicit Coffee(std::string requesterName) : requesterName(std::move(requesterName)), isHot(false), hasMilk
		(false), hasSugar(false), cost(0.0) {}

	friend class CoffeeBuilder;
	static CoffeeBuilder create(std::string requesterName);
};

// CoffeeBuilder class declaration - responsible for building a Coffee
class CoffeeBuilder
{
	Coffee coffee;

public:
	explicit CoffeeBuilder(std::string requesterName) : coffee(Coffee(std::move(requesterName))) {}

	// This operator allows us to convert from a CoffeeBuilder to a Coffee
	operator Coffee() const {return coffee;}

	CoffeeBuilder& makeHot();
	CoffeeBuilder& addMilk();
	CoffeeBuilder& addSugar();
	CoffeeBuilder& costs(double cost);
};

#endif //CPP_TUTORIAL_BUILDER_H
