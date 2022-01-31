#include <iostream>
#include <iomanip>
#include <vector>
#include <string>

struct City {
  std::string name;
  long population;
  double cost;
};

// Assume each country has at least 1 city
struct Country {
  std::string name;
  std::vector<City> cities;
};

struct Tours {
  std::string title;
  std::vector<Country> countries;
};

int main() {
	Tours tours
		{"Tour Ticket Prices from Miami",
		{
			{
				"Colombia", {
				{"Bogota", 8778000, 400.98},
				{"Cali", 2401000, 424.12},
				{"Medellin", 2464000, 350.98},
				{"Cartagena", 972000, 345.34}
			},
			},
			{
				"Brazil", {
				{"Rio De Janiero", 13500000, 567.45},
				{"Sao Paulo", 11310000, 975.45},
				{"Salvador", 18234000, 855.99}
			},
			},
			{
				"Chile", {
				{"Valdivia", 260000, 569.12},
				{"Santiago", 7040000, 520.00}
			},
			},
			{
				"Argentina", {
				{"Buenos Aires", 3010000, 723.77}
			}
			},
		}
		};

  const size_t field1_width {20};
  const size_t field2_width {20};
  const size_t field3_width {15};
  const size_t field4_width {15};
  const size_t total_width {field1_width + field2_width + field3_width + field4_width};
  const size_t title_width {tours.title.length()};

  std::cout << std::setw(total_width) << std::setfill('-') << "" << std::endl;
  std::cout << std::setfill(' ');
  std::cout << std::setw((total_width - title_width) / 2) << "" << tours.title << std::endl;
  std::cout << std::endl;

  std::cout << std::left << std::setw(field1_width) << "Country"
  			<< std::setw(field2_width) << "City"
			<< std::right  << std::setw(field3_width) << "Population"
			<< std::setw(field4_width) << "Price"
			<< std::endl;

  std::cout << std::setw(total_width) << std::setfill('-') << "" << std::endl;
  std::cout << std::setfill(' ');

  std::cout << std::setprecision(2) << std::fixed;

  for (auto country : tours.countries) {   // loop through the countries
	for (size_t i = 0; i < country.cities.size(); i++) {
	std::cout << std::left << std::setw(field1_width) << ((i == 0) ? country.name : "")
			<< std::left << std::setw(field2_width) << country.cities.at(i).name
			<< std::right  << std::setw(field3_width) << country.cities.at(i).population
			<< std::setw(field4_width) << country.cities.at(i).cost
			<< std::endl;
	}
  }

  std::cout << std::setw(total_width) << std::setfill('-') << "" << std::endl;
  std::cout << std::setfill(' ');

  return 0;
}
