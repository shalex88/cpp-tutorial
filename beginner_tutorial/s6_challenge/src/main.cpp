#include <iostream>

using std::cin;
using std::cout;
using std::endl;

int main()
{
	/* TODO:
	 * [v] prompt the small_rooms_number
	 * [v] prompt the large_rooms_number
	 * [v] display PRICE_PER_SMALL_ROOM 25$
	 * [v] display PRICE_PER_LARGE_ROOM 35$
	 * [v] calc small_rooms_cost = small_rooms_number * PRICE_PER_SMALL_ROOM
	 * [v] calc large_rooms_cost = large_rooms_number * PRICE_PER_LARGE_ROOM
	 * [v] display cost = small_rooms_cost + large_rooms_cost
	 * [v] display tax = cost * 6%
	 * [v] display total_price = cost + tax
	 * [v] display ESTIMATE_EXPIRY = 30 days
	 * TEST:
	 * [v] small_rooms_number = 3, large_rooms_number = 1, cost = 110, tax = 6.6,
	 * total_price = 116.6
	 * */

	cout << "Enter the small rooms number: ";
	int small_rooms_number {0};
	cin >> small_rooms_number;

	cout << "Enter the large rooms number: ";
	int large_rooms_number {0};
	cin >> large_rooms_number;

	const float PRICE_PER_SMALL_ROOM {25};
	const float PRICE_PER_LARGE_ROOM {35};
	const float TAX_RATE {0.06};
	const int ESTIMATE_EXPIRY {30};

	cout << "Price per small room cleaning: " << PRICE_PER_SMALL_ROOM << "$" << endl;
	cout << "Price per large room cleaning: " << PRICE_PER_LARGE_ROOM << "$" << endl;

	float small_rooms_cost {small_rooms_number * PRICE_PER_SMALL_ROOM};
	float large_rooms_cost {large_rooms_number * PRICE_PER_LARGE_ROOM};
	float cost {small_rooms_cost + large_rooms_cost};
	cout << "Cost: " << cost << "$" << endl;

	float tax {cost * TAX_RATE};
	cout << "Tax: " << tax << "$" << endl;

	float total_price {cost + tax};
	cout << "Total price: " << total_price << "$" << endl;

	cout << "Deal is valid for " << ESTIMATE_EXPIRY << " days" << endl;

	return 0;
}