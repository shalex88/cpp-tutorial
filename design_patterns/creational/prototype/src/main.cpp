#include <iostream>
#include <vector>

// Abstract base (interface) class - This is our prototype which contains a "clone" method
class ICoffeeMachine
{
public:
	virtual ICoffeeMachine* clone() = 0;
	virtual void brew() = 0;
	virtual ~ICoffeeMachine() = default;
};

// Concrete implementations of the prototype - in practice, these would be "complex" objects that cost a lot to instantiate
class SimpleCoffeeMachine : public ICoffeeMachine
{
public:
	ICoffeeMachine* clone() override {
		return new SimpleCoffeeMachine;
	}

	void brew() override {
		std::cout << "Brewing simple coffee!\n";
	}
};

class ComplexCoffeeMachine : public ICoffeeMachine
{
public:
	ICoffeeMachine* clone() override {
		return new ComplexCoffeeMachine;
	}

	void brew() override {
		std::cout << "Brewing complex coffee!\n";
	}
};

class EspressoMachine : public ICoffeeMachine
{
public:
	ICoffeeMachine* clone() override {
		return new EspressoMachine;
	}

	void brew() override {
		std::cout << "Brewing espresso!\n";
	}
};

// Helper, management class which can abstract the creation of objects via their type.
class CoffeeMachineManager
{
public:
	static ICoffeeMachine* createMachine(int machineType);
	~CoffeeMachineManager() = default;

private:
	static ICoffeeMachine* machines[3];
};

// The management class contains already instantiated objects so that new objects requested are simply cloned!
ICoffeeMachine* CoffeeMachineManager::machines[] = {
	new SimpleCoffeeMachine, new ComplexCoffeeMachine, new EspressoMachine
};

// This helper method will ensure that new machines are not created from scratch but are simply cloned instead
ICoffeeMachine* CoffeeMachineManager::createMachine(int machineType) {
	return machines[machineType]->clone();
}

int main() {
	// Each call to the "createMachine" method clones the right ICoffeeMachine object
	std::vector<ICoffeeMachine*> myMachines(3);
	ICoffeeMachine* simpleMachine = CoffeeMachineManager::createMachine(0);
	ICoffeeMachine* complexMachine = CoffeeMachineManager::createMachine(1);
	ICoffeeMachine* espressoMachine = CoffeeMachineManager::createMachine(2);

	myMachines[0] = simpleMachine;
	myMachines[1] = complexMachine;
	myMachines[2] = espressoMachine;

	for (auto& myMachine : myMachines)
	{
		myMachine->brew();
	}

	// Easily create a copy!
	ICoffeeMachine* clonedMachine = simpleMachine->clone();
	clonedMachine->brew();

	// Clean up!
	for (auto& myMachine : myMachines)
	{
		delete myMachine;
	}

	delete clonedMachine;

	return 0;
}
