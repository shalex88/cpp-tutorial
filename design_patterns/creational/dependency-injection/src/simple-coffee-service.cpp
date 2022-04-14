#include <iostream>
#include "icoffee-service.h"

// Specific implementation of a CoffeeService
class SimpleCoffeeService : public ICoffeeService {
	void send_metrics() override {
		std::cout << "Sending metrics!\n";
	}
};

