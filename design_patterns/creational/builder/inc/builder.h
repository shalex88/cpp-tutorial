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
	std::string requester_name;
	bool is_hot;
	bool has_milk;
	bool has_sugar;
	double cost;

	// Private constructor to avoid building without builder
	explicit Coffee(std::string requester_name);

public:
	friend class CoffeeBuilder;
	static CoffeeBuilder create(std::string requester_name);

	const std::string& getRequesterName() const;
	bool isHot() const;
	void setIsHot(bool is_hot);
	bool isHasMilk() const;
	void setHasMilk(bool has_milk);
	bool isHasSugar() const;
	void setHasSugar(bool has_sugar);
	double getCost() const;
	void setCost(double cost);
};

// CoffeeBuilder class declaration - responsible for building a Coffee
class CoffeeBuilder
{
	Coffee coffee;

public:
	explicit CoffeeBuilder(std::string requester_name);

	// This operator allows us to convert from a CoffeeBuilder to a Coffee
	operator Coffee() const;

	CoffeeBuilder& makeHot();
	CoffeeBuilder& addMilk();
	CoffeeBuilder& addSugar();
	CoffeeBuilder& costs(double cost);
};

#endif //CPP_TUTORIAL_BUILDER_H
