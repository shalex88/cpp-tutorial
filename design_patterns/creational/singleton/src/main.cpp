#include <iostream>
#include <map>
#include <string>

class GlobalCoffeeConfig
{
	std::map<std::string, std::string> coffeeState;

	// Private constructor
	GlobalCoffeeConfig() = default;

public:
	// Remove ability to use the copy constructor
	GlobalCoffeeConfig(GlobalCoffeeConfig const&) = delete;

	// Remove ability top use the copy assignment operator
	GlobalCoffeeConfig& operator=(GlobalCoffeeConfig const&) = delete;

	// Provide a single, static method for retrieving the singleton instance
	static GlobalCoffeeConfig& get() {
		static GlobalCoffeeConfig config;
		return config;
	}

	void setState(const std::string& key, const std::string& value) {
		coffeeState.insert({key, value});
	}

	std::string getState(const std::string& key) {
		auto iterator = coffeeState.find(key);
		return iterator->second;
	}
};

int main() {
	// Can't compile this line because the constructor is private
	// GlobalCoffeeConfig configObj = GlobalCoffeeConfig();

	// The "get" method is the only way to retrieve the static, singleton instance
	// This line doesn't compile, because the copy constructor has been removed - a new instance cannot be created
	// GlobalCoffeeConfig configObj = GlobalCoffeeConfig::get();

	GlobalCoffeeConfig& configObj = GlobalCoffeeConfig::get();

	configObj.setState("COFFEE_STATUS", "ON");
	configObj.setState("COFFEE_HEALTH_URL", "./health");

	std::cout << "COFFEE_STATUS: " << configObj.getState("COFFEE_STATUS").c_str() << std::endl;
	std::cout << "COFFEE_HEALTH_URL: " << configObj.getState("COFFEE_HEALTH_URL").c_str() << std::endl;

	return EXIT_SUCCESS;
}
