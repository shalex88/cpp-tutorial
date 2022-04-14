#ifndef CPP_TUTORIAL_COFFEE_MACHINE_H
#define CPP_TUTORIAL_COFFEE_MACHINE_H

#include <memory>
#include "icoffee-service.h"

class CoffeeMachine {
public:
	explicit CoffeeMachine(std::unique_ptr<ICoffeeService>&& coffee_svc) : coffee_service(std::move(coffee_svc)) {}

	void brew();

private:
	std::unique_ptr<ICoffeeService> coffee_service;
};

#endif //CPP_TUTORIAL_COFFEE_MACHINE_H