#include <iostream>
#include "builder.h"

int main() {
	Coffee coffee = Coffee::create("Zachary")
		.makeHot()
		.addSugar()
		.addMilk()
		.costs(4.00);

	Coffee coffee2 = Coffee::create("Jennifer")
		.makeHot()
		.costs(3.50);

	std::cout << coffee.cost << std::endl;
	std::cout << coffee2.cost << std::endl;

	return 0;
}
