#include <iostream>
#include "coffee-machine.h"

void CoffeeMachine::brew() {
	std::cout << "Brewing coffee!\n";

	coffee_service->send_metrics();
}