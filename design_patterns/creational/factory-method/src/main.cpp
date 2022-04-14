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

// This factory class simply encapsulates the factory method for a CoffeeMachine type
class CoffeeMachineFactory
{
public:
	static std::unique_ptr<ICoffeeMachine> create_machine(int machine_type) {
		switch (machine_type)
		{
			case 1: return std::make_unique<SimpleCoffeeMachine>();
			case 2: return std::make_unique<RobustCoffeeMachine>();
			default: return std::make_unique<SimpleCoffeeMachine>();
		}
	}
};

int main() {
	std::unique_ptr<CoffeeMachineFactory> factory = std::make_unique<CoffeeMachineFactory>();

	auto machine_one = factory->create_machine(1);
	auto machine_two = factory->create_machine(2);

	machine_one->brew();
	machine_two->brew();

	return 0;
}
