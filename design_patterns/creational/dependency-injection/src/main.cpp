#include <iostream>
#include "coffee-machine.h"
#include "icoffee-service.h"

class MockCoffeeService : public ICoffeeService {
	void send_metrics() override {
		std::cout << "Sending mock metrics!\n";
	}
};

// Example of simple "constructor injection" using interfaces
int main() {
	CoffeeMachine my_machine(std::make_unique<MockCoffeeService>());

	// Test my machine with a mock coffee service
	my_machine.brew();
}
