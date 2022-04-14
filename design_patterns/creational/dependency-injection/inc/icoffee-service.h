#ifndef CPP_TUTORIAL_ICOFFEE_SERVICE_H
#define CPP_TUTORIAL_ICOFFEE_SERVICE_H

#include <memory>

// Interface for defining a CoffeeService type
struct ICoffeeService {
	virtual void send_metrics() = 0;
	virtual ~ICoffeeService() = default;
};

#endif //CPP_TUTORIAL_ICOFFEE_SERVICE_H