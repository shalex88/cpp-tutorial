#include <iostream>
#include <memory>

class ICoffeeMachine
{
public:
	virtual void brew() = 0;
};

class SimpleCoffeeMachine : public ICoffeeMachine
{
public:
	void brew() override {
		std::cout << "Brewing simple coffee \n";
	}
};

class RobustCoffeeMachine : public ICoffeeMachine
{
public:
	void brew() override {
		std::cout << "Brewing robust coffee \n";
	}
};

class ICoffee
{
public:
	virtual void stir() = 0;
};

class SimpleCoffee : public ICoffee
{
public:
	void stir() override {
		std::cout << "Stirring simple coffee \n";
	}
};

class RobustCoffee : public ICoffee
{
public:
	void stir() override {
		std::cout << "Stirring robust coffee \n";
	}
};

// This is our abstract factory class
class ICoffeeFactory
{
public:
	virtual std::unique_ptr<ICoffeeMachine> create_machine() = 0;
	virtual std::unique_ptr<ICoffee> create_coffee() = 0;
};

// We can implement individual factories which include factory methods for a family of objects
class SimpleCoffeeFactory : public ICoffeeFactory
{
public:
	std::unique_ptr<ICoffeeMachine> create_machine() override {
		return std::make_unique<SimpleCoffeeMachine>();
	}

	std::unique_ptr<ICoffee> create_coffee() override {
		return std::make_unique<SimpleCoffee>();
	}
};

class RobustCoffeeFactory : public ICoffeeFactory
{
public:
	std::unique_ptr<ICoffeeMachine> create_machine() override {
		return std::make_unique<RobustCoffeeMachine>();
	}

	std::unique_ptr<ICoffee> create_coffee() override {
		return std::make_unique<RobustCoffee>();
	}
};

int main() {
	// We can use the abstract factory pattern to create families of related objects
	std::unique_ptr<ICoffeeFactory> factory_one = std::make_unique<SimpleCoffeeFactory>();
	auto coffee_machine_one = factory_one->create_machine();
	auto coffee_one = factory_one->create_coffee();

	auto factory_two = std::make_unique<RobustCoffeeFactory>();
	auto coffee_machine_two = factory_two->create_machine();
	auto coffee_two = factory_two->create_coffee();

	coffee_machine_one->brew();
	coffee_one->stir();

	coffee_machine_two->brew();
	coffee_two->stir();

	return 0;
}