#include <iostream>
#include "builder.h"

int main() {
	// Can't compile this line because the constructor is private
	// Coffee coffee("Alex");

	Coffee coffee_1 = Coffee::create("Zachary")
		.makeHot()
		.addSugar()
		.addMilk()
		.costs(4.00);

	Coffee coffee_2 = Coffee::create("Jennifer")
		.makeHot()
		.costs(3.50);

	std::cout << coffee_1.getCost() << std::endl;
	std::cout << coffee_2.getCost() << std::endl;

	return 0;
}
